#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

int main() {
    int qtdPessoas, p;

    scanf("%d\n", &qtdPessoas);

    tPessoa pessoas[qtdPessoas];

    for (p = 0; p < qtdPessoas; p++) {
        pessoas[p] = CriaPessoa();
        LePessoa(&pessoas[p]);
    }
    
    AssociaFamiliasGruposPessoas(pessoas);

    for (p = 0; p < qtdPessoas; p++) {
        ImprimePessoa(&pessoas[p]);
    }

    return 0;
}