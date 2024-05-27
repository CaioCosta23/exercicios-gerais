#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

struct Usuario {
    char nome[50];
    char cpf[15];
};

tUsuario *CriaUsuario() {
    tUsuario *usuario = (tUsuario*)malloc(sizeof(tUsuario));

    if (usuario == NULL) {
        printf("Erro na alocacao de memoria do usuario da conta ");
    }
    return usuario;
}

void LeUsuario(tUsuario *user) {
    scanf("%s %s", user->nome, user->cpf);
}

void ImprimeUsuario(tUsuario *user) {
    printf("Nome: %s\n", (*user).nome);
    printf("CPF: %s\n", (*user).cpf);
}

void DestroiUsuario(tUsuario *user) {
    if (user != NULL) {
        free(user);
        user = NULL;
    }
}