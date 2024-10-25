# PROJETOC2

# Sistema de Cadastro de Usuários

## Descrição do Projeto

Este projeto é um sistema de gerenciamento de usuários, implementado em C, que permite realizar cadastro e login de usuários. Após o login, o usuário pode acessar um menu com as seguintes funcionalidades:

- **Trocar senha**: Permite que o usuário altere sua senha atual.
- **Remover conta**: Remove o usuário do sistema.
- **Enviar solicitação de amizade**: Envia uma solicitação de amizade para outro usuário cadastrado pelo ID.

Os dados dos usuários são armazenados em um arquivo binário (`usuarios.dat`) para maior segurança, enquanto as operações são controladas internamente através de manipulação de structs e arrays, utilizando ponteiros para gerenciar informações.

## Estrutura do Projeto

O projeto é organizado em três arquivos principais:

- `projeto.h`: Define a estrutura `Usuario` e declara as funções.
- `projeto.c`: Contém a implementação das funções que manipulam as operações do sistema.
- `main.c`: Gerencia o menu principal e as operações de login.

## Funcionalidades

1. **Cadastro de Usuário**: Permite que novos usuários se cadastrem no sistema com um ID, nome, CPF e senha.
2. **Login de Usuário**: Autentica o usuário com CPF e senha.
3. **Menu do Usuário**:
   - Trocar senha.
   - Remover conta.
   - Enviar solicitação de amizade para outro usuário.

## Compilação

Para compilar o projeto, o usuario pode rodar através do bash com o comando "gcc", ou baixar como zip e rodar por qualquer plataforma de sua preferencia.
