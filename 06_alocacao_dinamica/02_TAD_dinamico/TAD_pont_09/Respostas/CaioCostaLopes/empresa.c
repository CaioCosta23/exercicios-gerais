#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

void ApagaFuncionariosPorErro(tFuncionario *funcionarios[], int qtdFuncionarios) {
    int l;

    for (l = 0; l < qtdFuncionarios; l++) {
        ApagaFuncionario(funcionarios[l]);
    }
}


tEmpresa *CriaEmpresa() {
    tEmpresa *empresa = (tEmpresa*)malloc(sizeof(tEmpresa));

    if (empresa == NULL) {
        printf("Erro na alocaccao da empresa!\n");
        return empresa;
    }
    
    empresa->funcionarios = NULL;
    empresa->id = -1;
    empresa->qtdFuncionarios;

    return empresa;
}

void LeEmpresa(tEmpresa *empresa) {
    int f, l;

    scanf("%d %d", &empresa->id, &empresa->qtdFuncionarios);

    empresa->funcionarios = (tFuncionario**)malloc(empresa->qtdFuncionarios *sizeof(tFuncionario*));

    if (!((*empresa).funcionarios == NULL)) {
        for (f = 0; f < (*empresa).qtdFuncionarios; f++) {
            empresa->funcionarios[f] = CriaFuncionario();
            
            if (!((*empresa).funcionarios == NULL)) {
                LeFuncionario((*empresa).funcionarios[f]);
                ContrataFuncionarioEmpresa(empresa, (*empresa).funcionarios[f]);
            }else {
                ApagaFuncionariosPorErro(empresa->funcionarios, f);
                ApagaEmpresa(empresa);
            }
        }
    }else {
        printf("Erro na alocacao do vetor de funcionarios!\n");
        ApagaEmpresa(empresa);
    }
}

void ContrataFuncionarioEmpresa(tEmpresa *empresa, tFuncionario *funcionario) {
    int f;
    int contratado = 0;

    if ((*empresa).qtdFuncionarios > 0) {
        for (f = 0; f < (*empresa).qtdFuncionarios; f++) {
            if ((*funcionario).id == GetIdFuncionario((*empresa).funcionarios[f])) {
                contratado = 1;
                break;
            }
        }
    }else {
        contratado = 1;
    }

    if (contratado) {
        printf("A empresa %d ja possui um funcionario com o id %d\n", (*empresa).id, (*funcionario).id);
    }else {
        empresa->funcionarios[(*empresa).qtdFuncionarios] = funcionario;
        empresa->qtdFuncionarios += 1;
    }
}

void ImprimeEmpresa(tEmpresa *empresa) {
    int f;

    printf("Empresa %d:\n", (*empresa).id);
    for (f = 0; f < (*empresa).qtdFuncionarios; f++) {
        ImprimeFuncionario((*empresa).funcionarios[f]);
    }
}

void ApagaEmpresa(tEmpresa *empresa) {
    if (empresa != NULL) {
        if ((*empresa).funcionarios != NULL) {
            free((*empresa).funcionarios);
            empresa->funcionarios = NULL;
        }
        free(empresa);
        empresa = NULL;
    }
}

