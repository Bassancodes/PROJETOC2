#include "projeto.h"
#include <stdio.h>
#include <stdlib.h>

void cadastrarCliente() {
    FILE *arquivoBin = fopen("clientes.dat", "ab");
    FILE *arquivoTexto = fopen("log.txt", "a");

    if (arquivoBin == NULL || arquivoTexto == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Cliente cliente;
    printf("ID do Cliente: ");
    scanf("%d", &cliente.id);
    printf("Nome: ");
    scanf("%s", cliente.nome);
    printf("CPF: ");
    scanf("%s", cliente.cpf);
    printf("Idade: ");
    scanf("%d", &cliente.idade);
    printf("Saldo: ");
    scanf("%f", &cliente.saldo);

    fwrite(&cliente, sizeof(Cliente), 1, arquivoBin);
    fprintf(arquivoTexto, "Cadastro - ID: %d, Nome: %s, CPF: %s\n", cliente.id, cliente.nome, cliente.cpf);

    fclose(arquivoBin);
    fclose(arquivoTexto);

    printf("Cliente cadastrado com sucesso!\n");
}


int loginUsuario(Usuario *usuarioLogado) {
    FILE *arquivoBin = fopen("usuarios.dat", "rb");
    if (arquivoBin == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    char cpf[12], senha[20];
    Usuario usuario;
    int encontrado = 0;

    printf("CPF: ");
    scanf("%s", cpf);
    printf("Senha: ");
    scanf("%s", senha);

    while (fread(&usuario, sizeof(Usuario), 1, arquivoBin)) {
        if (strcmp(usuario.cpf, cpf) == 0 && strcmp(usuario.senha, senha) == 0) {
            *usuarioLogado = usuario;
            encontrado = 1;
            break;
        }
    }

    fclose(arquivoBin);
    return encontrado;
}

void menuUsuario(Usuario *usuarioLogado) {
    int opcao;

    do {
        printf("\n--- Menu do Usuario ---\n");
        printf("1. Trocar senha\n");
        printf("2. Remover conta\n");
        printf("3. Enviar solicitacao de amizade\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                trocarSenha(usuarioLogado);
                break;
            case 2:
                removerConta(usuarioLogado->cpf);
                return;
            case 3:
                enviarSolicitacaoAmizade(usuarioLogado);
                break;
            case 4:
                printf("Saindo do menu...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);
}



void trocarSenha(Usuario *usuarioLogado) {
    FILE *arquivoBin = fopen("usuarios.dat", "r+b");
    if (arquivoBin == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Usuario usuario;
    while (fread(&usuario, sizeof(Usuario), 1, arquivoBin)) {
        if (usuario.id == usuarioLogado->id) {
            printf("Digite a nova senha: ");
            scanf("%s", usuarioLogado->senha);
            fseek(arquivoBin, -sizeof(Usuario), SEEK_CUR);
            fwrite(usuarioLogado, sizeof(Usuario), 1, arquivoBin);
            printf("Senha alterada com sucesso!\n");
            break;
        }
    }

    fclose(arquivoBin);
}


void removerConta(){
    printf("remover");
    return 0;
}

void enviarSolicitacaoAmizade{
    printf("solicitação");
    return 0;
}