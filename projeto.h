#ifndef projeto_h
#define projeto_h

typedef struct {
    int id;
    char nome[50];
    char cpf[12];
    char senha[20];
    int amigos[10]; 
    int totalAmigos;
} Usuario;

void cadastrarUsuario();
int loginUsuario(Usuario *usuarioLogado);
void menuUsuario(Usuario *usuarioLogado);