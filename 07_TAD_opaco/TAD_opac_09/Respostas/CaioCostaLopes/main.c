#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

void EncerraPrograma(tEmpresa *empresas[], int qtdAlocacoes) {
    int a;

    for (a = 0; a < qtdAlocacoes; a++) {
        ApagaEmpresa(empresas[a]);
    }
}

void VerificaAlocacao(tEmpresa *empresas[], int posicaoAnalisada) {
    if (empresas[posicaoAnalisada] == NULL) {
        printf("%d", (posicaoAnalisada + 1));
        EncerraPrograma(empresas, (posicaoAnalisada + 1));
        exit(1);
    }
}


int main() {
    int qtdEmpresas, e;

    scanf("%d", &qtdEmpresas);

    tEmpresa *empresas[qtdEmpresas];

    for (e = 0; e < qtdEmpresas; e++) {
        empresas[e] = CriaEmpresa();
        VerificaAlocacao(empresas, (e));
        LeEmpresa(empresas[e]);
        VerificaAlocacao(empresas, (e));
    }
    for (e = 0; e < qtdEmpresas; e++) {
        ImprimeEmpresa(empresas[e]);
    }

    EncerraPrograma(empresas, qtdEmpresas);
}