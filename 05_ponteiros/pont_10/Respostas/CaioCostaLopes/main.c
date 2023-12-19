#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

int main() {
    int qtdPessoas, p;

    scanf("%d", &qtdPessoas);

    tPessoa pessoas [qtdPessoas];

    for (p = 0; p < qtdPessoas; p++) {
        pessoas[p] = CriaPessoa();
        LePessoas(&pessoas[p]);
    }

    AssociaFamiliasGruposPessoas(pessoas, qtdPessoas);

    for (p = 0; p < qtdPessoas; p++) {
        ImprimePessoa(&pessoas[p]);
    }
    return 0;
}