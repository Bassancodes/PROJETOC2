#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projeto.h"

void cadastrarUsuario() {
    FILE *arquivoBin = fopen("usuarios.dat", "ab");

    if (arquivoBin == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Usuario usuario;
    usuario.totalAmigos = 0;

    printf("ID do Usuario: ");
    scanf("%d", &usuario.id);
    printf("Nome: ");
    scanf("%s", usuario.nome);
    printf("CPF: ");
    scanf("%s", usuario.cpf);
    printf("Senha: ");
    scanf("%s", usuario.senha);

    fwrite(&usuario, sizeof(Usuario), 1, arquivoBin);
    fclose(arquivoBin);
    printf("Usuario cadastrado com sucesso!\n");
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

void removerConta(char *cpf) {
    FILE *arquivoBin = fopen("usuarios.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (arquivoBin == NULL || temp == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Usuario usuario;
    while (fread(&usuario, sizeof(Usuario), 1, arquivoBin)) {
        if (strcmp(usuario.cpf, cpf) != 0) {
            fwrite(&usuario, sizeof(Usuario), 1, temp);
        }
    }

    fclose(arquivoBin);
    fclose(temp);

    remove("usuarios.dat");
    rename("temp.dat", "usuarios.dat");

    printf("Conta removida com sucesso!\n");
}

void enviarSolicitacaoAmizade(Usuario *usuarioLogado) {
    FILE *arquivoBin = fopen("usuarios.dat", "r+b");
    if (arquivoBin == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    int idAmigo;
    printf("Digite o ID do usuario para enviar a solicitacao de amizade: ");
    scanf("%d", &idAmigo);

    Usuario usuario;
    int encontrado = 0;

    while (fread(&usuario, sizeof(Usuario), 1, arquivoBin)) {
        if (usuario.id == idAmigo && usuarioLogado->totalAmigos < 10) {
            usuarioLogado->amigos[usuarioLogado->totalAmigos++] = usuario.id;
            printf("Solicitacao de amizade enviada para %s\n", usuario.nome);

            // Salva a atualização dos amigos do usuário logado
            fseek(arquivoBin, -sizeof(Usuario), SEEK_CUR);
            fwrite(usuarioLogado, sizeof(Usuario), 1, arquivoBin);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuario com ID %d nao encontrado.\n", idAmigo);
    }

    fclose(arquivoBin);
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
