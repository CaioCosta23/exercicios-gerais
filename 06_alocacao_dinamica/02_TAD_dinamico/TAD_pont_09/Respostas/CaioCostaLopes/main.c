#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

void EncerraProgramaPorErro(tEmpresa *empresas[], int qtdEmpresas) {
    int l;

    for (l = 0; l <= qtdEmpresas; l++) {
        ApagaEmpresa(empresas[l]);
    }
    exit(1);
}


int main() {
    int qtdEmpresas, e, l;

    scanf("%d", &qtdEmpresas);

    tEmpresa *empresas[qtdEmpresas];

    for (e = 0; e < qtdEmpresas; e++) {
        empresas[e] = CriaEmpresa();
        if (empresas[e] == NULL) {
            EncerraProgramaPorErro(empresas, e);
        }
        LeEmpresa(empresas[e]);
        if (empresas[e] == NULL) {
            EncerraProgramaPorErro(empresas, e);
        }
    }
    for (e = 0; e < qtdEmpresas; e++) {
        ImprimeEmpresa(empresas[e]);
    }

    for(e = 0; e < qtdEmpresas; e++) {
        ApagaEmpresa(empresas[e]);
    }

    return 0;
}