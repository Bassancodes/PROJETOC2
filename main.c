#include <stdio.h>
#include "projeto.h"

int main() {
    int opcao;
    Usuario usuarioLogado;

    do {
        printf("\n--- Sistema de Cadastro de Usuarios ---\n");
        printf("1. Cadastrar Usuario\n");
        printf("2. Entrar\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                if (loginUsuario(&usuarioLogado)) {
                    printf("Login realizado com sucesso!\n");
                    menuUsuario(&usuarioLogado);
                } else {
                    printf("CPF ou senha incorretos!\n");
                }
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}