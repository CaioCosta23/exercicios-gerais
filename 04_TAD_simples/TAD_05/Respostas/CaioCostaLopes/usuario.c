#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

tUsuario CriaUsuario(char nome[20], char cpf[15]) {
    tUsuario usuario;

    strncpy(usuario.nome, nome, 20);
    strncpy(usuario.cpf, cpf, 15);

    return usuario;
}

void ImprimeUsuario(tUsuario user) {
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s\n", user.cpf);
}