#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    char cpf[12];
    char senha[20];
    int amigos[10]; // IDs dos amigos para um máximo de 10 amizades
    int totalAmigos;
} Usuario;
