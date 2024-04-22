#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

int main() {
    int qtdEmpresas, e;

    scanf("%d", &qtdEmpresas);

    tEmpresa *empresas[qtdEmpresas];

    for (e = 0; e < qtdEmpresas; e++) {
        empresas[e] = CriaEmpresa();
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