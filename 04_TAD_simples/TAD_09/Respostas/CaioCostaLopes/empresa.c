#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"
#include "funcionario.h"

tEmpresa criaEmpresa(int id) {
    tEmpresa empresa;

    empresa.id = id;

    return empresa;
}

tEmpresa leEmpresa() {
    int id, qtdCandidatos, f;
    tEmpresa empresa;
    tFuncionario funcionario;

    scanf("%d %d", &id, &qtdCandidatos);

    empresa = criaEmpresa(id);
    empresa.qtdFuncionarios = 0;

    for (f = 0; f < qtdCandidatos; f++) {
        funcionario = leFuncionario();
        empresa = contrataFuncionarioEmpresa(empresa, funcionario);        
    }

    return empresa;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario) {
    int f;
    int contratado = 0;

    if (empresa.qtdFuncionarios > 0) {
        for (f = 0; f < empresa.qtdFuncionarios; f++) {
            if (funcionario.id == getIdFuncionario(empresa.funcionarios[f])) {
                contratado = 1;
                break;
            }
        }
    }else {
        empresa.funcionarios[0] = funcionario;
        return empresa;
    }

    if (contratado) {
        printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, funcionario.id);
    }else {
        empresa.funcionarios[empresa.qtdFuncionarios + 1] = funcionario;
        empresa.qtdFuncionarios += 1;
    }
    return empresa;
}

void imprimeEmpresa(tEmpresa empresa) {
    int f;

    printf("Empresa %d:\n", empresa.id);

    for (f = 0; f < empresa.qtdFuncionarios; f++) {
        imprimeFuncioanrio(empresa.funcionarios[f]);
    }
}

