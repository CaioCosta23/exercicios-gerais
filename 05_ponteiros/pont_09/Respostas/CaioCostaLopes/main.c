#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

int main() {
    int qtdPessoas, qtdAssociacoes, p, a;

    scanf("%d\n", &qtdPessoas);

    tPessoa pessoas[qtdPessoas];

    for (p = 0; p < qtdPessoas; p++) {
        pessoas[p] = CriaPessoa();
        LePessoa(&pessoas[p]);
    }
    
    scanf("%d", &qtdAssociacoes);

    for (a = 0; a < qtdAssociacoes; a++) {
        AssociacoesFamiliasGruposPessoas(pessoas);
        ImprimePessoa(&pessoas[p]);
    }
    return 0;
}