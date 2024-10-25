#include "projeto.h"
#include <stdio.h>
#include <stdlib.h>

void cadastrarUsuario(){
    printf("Cadastro");
    return 0;
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
        if (usuario.id == idAmigo) {
            if (usuarioLogado->totalAmigos < 10) {
                usuarioLogado->amigos[usuarioLogado->totalAmigos++] = usuario.id;
                printf("Solicitacao de amizade enviada para %s\n", usuario.nome);

                // Salva a atualização de amigos do usuário logado
                fseek(arquivoBin, -sizeof(Usuario), SEEK_CUR);
                fwrite(usuarioLogado, sizeof(Usuario), 1, arquivoBin);
            } else {
                printf("Limite de amigos atingido.\n");
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuario com ID %d nao encontrado.\n", idAmigo);
    }

    fclose(arquivoBin);
}
