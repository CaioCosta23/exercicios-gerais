#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

void EncerraPrograma(tEmpresa *empresas[], int qtdEmpresas) {
    int l;

    for (l = 0; l < qtdEmpresas; l++) {
        ApagaEmpresa(empresas[l]);
    }
}


int main() {
    int qtdEmpresas, e;

    scanf("%d", &qtdEmpresas);

    tEmpresa *empresas[qtdEmpresas];

    for (e = 0; e < qtdEmpresas; e++) {
        empresas[e] = CriaEmpresa();
        if (empresas[e] == NULL) {
            EncerraPrograma(empresas, (e + 1));
            exit(1);
        }
        LeEmpresa(empresas[e]);
        if (empresas[e] == NULL) {
            EncerraPrograma(empresas, (e + 1));
            exit(1);
        }
    }
    for (e = 0; e < qtdEmpresas; e++) {
        ImprimeEmpresa(empresas[e]);
    }

    EncerraPrograma(empresas, qtdEmpresas);

    return 0;
}