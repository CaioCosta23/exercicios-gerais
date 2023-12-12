#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

int main() {
    int qtdEmpresas, e;

    scanf("%d", &qtdEmpresas);

    tEmpresa empresas[qtdEmpresas];

    for (e = 0; e < qtdEmpresas; e++) {
        empresas[e] = leEmpresa();
    }
    for(e = 0; e < qtdEmpresas; e++) {
        imprimeEmpresas(empresas[e]);
    }

    return 0;
}