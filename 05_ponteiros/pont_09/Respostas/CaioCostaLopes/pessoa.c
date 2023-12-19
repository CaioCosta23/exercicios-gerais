#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

tPessoa CriaPessoa() {
    tPessoa pessoa;

    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;

    return pessoa;
}

void LePessoa(tPessoa *pessoa) {
    scanf("\n%[^\n]\n", (*pessoa).nome);
    // De onde está surguindo o primeiro '\n' lido? (Verificar casos de teste de entrada)
}

int VerificaSeTemPais(tPessoa *pessoa) {
    return (((*pessoa).mae != NULL) || ((*pessoa).pai != NULL));
}

void ImprimePessoa(tPessoa *pessoa) {

    if (VerificaSeTemPais(pessoa)) {
        printf("NOME COMPLETO: %s\n", (*pessoa).nome);
        if ((*pessoa).pai != NULL) {
            printf("PAI: %s\n", (*pessoa).pai->nome);
        }else {
            printf("PAI: NAO INFORMADO\n");
        }
        if ((*pessoa).mae != NULL) {
            printf("MAE: %s\n", (*pessoa).mae->nome);
        }else {
            printf("MAE: NAO INFORMADO\n");
        }
        printf("\n");
    }
}

void AssociaFamiliasGruposPessoas(tPessoa pessoa[]) {
    int a, qtdAssociacoes, indiceMae, indicePai, indiceFilho;
    
    scanf("%d\n", &qtdAssociacoes);

    for (a = 0; a < qtdAssociacoes; a++) {
        scanf("mae: %d, pai: %d, filho: %d\n", &indiceMae, &indicePai, &indiceFilho);

        if (indiceMae != -1) {
            pessoa[indiceFilho].mae = &pessoa[indiceMae];
        }
        if (indicePai != -1) {
            pessoa[indiceFilho].pai = &pessoa[indicePai];
        }
    }
}
