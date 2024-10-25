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


int loginUsuario(){
    printf("login");
    return 0;
}

void trocarSenha(){
    printf("trocarsenha");
    return 0;
}

void removerConta(){
    printf("remover");
    return 0;
}

void enviarSolicitacaoAmizade{
    printf("solicitação");
    return 0;
}