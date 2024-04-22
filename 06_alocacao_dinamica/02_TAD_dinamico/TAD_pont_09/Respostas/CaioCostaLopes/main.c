#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

int main() {
    int qtdEmpresas, e, l;

    scanf("%d", &qtdEmpresas);

    tEmpresa *empresas[qtdEmpresas];

    for (e = 0; e < qtdEmpresas; e++) {
        empresas[e] = CriaEmpresa();
        if (empresas[e] == NULL) {
            for (l = 0; l <= e; l++) {
                ApagaEmpresa(empresas[l]);
            }
            exit(1);
        }
        LeEmpresa(empresas[e]);
    }
    for (e = 0; e < qtdEmpresas; e++) {
        ImprimeEmpresa(empresas[e]);
    }

    for(e = 0; e < qtdEmpresas; e++) {
        ApagaEmpresa(empresas[e]);
    }

    return 0;
}