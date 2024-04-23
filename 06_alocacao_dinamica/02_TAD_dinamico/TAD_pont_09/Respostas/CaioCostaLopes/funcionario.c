#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

tFuncionario *CriaFuncionario() {
    tFuncionario *funcionario = (tFuncionario*)malloc(sizeof(tFuncionario));

    funcionario->id = -1;
    funcionario->salario = -1;

    return funcionario;
}

void LeFuncionario(tFuncionario *funcionario) {
    scanf("%d %f", &funcionario->id, &funcionario->salario);
}

int GetIdFuncionario(tFuncionario *funcionario) {
    return (*funcionario).id;
}

void ImprimeFuncionario(tFuncionario *funcionario) {
    printf("- Funcionario %d: RS %.2f\n", (*funcionario).id, (*funcionario).salario);
}

void ApagaFuncionario(tFuncionario *funcionario) {
    if (funcionario != NULL) {
        free(funcionario);
        funcionario = NULL;
    }
}