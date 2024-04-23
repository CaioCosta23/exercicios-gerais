#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

tEmpresa *CriaEmpresa() {
    tEmpresa *empresa = (tEmpresa*)malloc(sizeof(tEmpresa));

    if (empresa == NULL) {
        printf("Erro na alocaccao da empresa!\n");
        return empresa;
    }
    
    empresa->funcionarios = NULL;
    empresa->id = -1;
    empresa->qtdFuncionarios = 0;

    return empresa;
}

void LeEmpresa(tEmpresa *empresa) {
    int f, qtdCandidatos;
    tFuncionario *funcionario = NULL;

    scanf("%d %d", &empresa->id, &qtdCandidatos);

    empresa->funcionarios = (tFuncionario**)malloc(qtdCandidatos *sizeof(tFuncionario*));

    if ((*empresa).funcionarios != NULL) {
        for (f = 0; f < qtdCandidatos; f++) {
            funcionario = CriaFuncionario();
            
            if (funcionario != NULL) {
                LeFuncionario(funcionario);
                ContrataFuncionarioEmpresa(empresa, funcionario);
            }else {
                printf("Erro na alocacao do funcionario %d da empresa %d!\n", f, (*empresa).id);
                ApagaEmpresa(empresa);
            }
        }
        empresa->funcionarios = (tFuncionario**)realloc((*empresa).funcionarios, (*empresa).qtdFuncionarios * sizeof(tFuncionario*));
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
    int f;

    if (empresa != NULL) {
        if ((*empresa).funcionarios != NULL) {
            for (f = 0; f < (*empresa).qtdFuncionarios; f++) {
                ApagaFuncionario((*empresa).funcionarios[f]);
            }
            free((*empresa).funcionarios);
            empresa->funcionarios = NULL;
        }
        free(empresa);
        empresa = NULL;
    }
}

