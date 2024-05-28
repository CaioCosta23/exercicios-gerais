#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

struct funcionario {
    int id;
    float salario;
};

tFuncionario *CriaFuncionario() {
    tFuncionario *funcionario = (tFuncionario*)malloc(sizeof(tFuncionario));

    if (funcionario != NULL) {
        funcionario->id = -1;
        funcionario->salario = 0;
    }
    return funcionario;
}

void LeFuncionario(tFuncionario *funcionario) {
    scanf("%d %f", &funcionario->id, &funcionario->salario);
}

int GetIdFuncionario(tFuncionario *funcionario) {
    return (*funcionario).id;
}

void ImprimeFuncionario(tFuncionario *funcionario) {
    printf("- Funcionario %d: RS %.2f\n", GetIdFuncionario(funcionario), (*funcionario).salario);
}

void ApagaFuncionario(tFuncionario *funcionario) {
    if (funcionario != NULL) {
        free(funcionario);
        funcionario = NULL;
    }
}

