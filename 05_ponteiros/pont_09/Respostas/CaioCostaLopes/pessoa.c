#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

tPessoa CriaPessoa() {
    tPessoa pessoa = {'\0', NULL, NULL};

    return pessoa;
}

void LePessoa(tPessoa *pessoa) {
    scanf("%[^^\n]\n", (*pessoa).nome);
}

int VerificaSeTemPais(tPessoa *pessoa) {
    return (((*pessoa).mae != NULL) || ((*pessoa).pai =! NULL));
}

void ImprimePessoa(tPessoa *pessoa) {
    if (VerificaSeTemPais(&pessoa)) {
        printf("NOME COMPLETO: %s\n", (*pessoa).nome);
        if ((*pessoa).pai != NULL) {
            printf("PAI: %s\n", (*pessoa).pai);
        }else {
            printf("NAO INFORMADO\n");
        }
        if ((*pessoa).mae != NULL) {
            printf("MAE: %s\n", (*pessoa).mae);
        }else {
            printf("NAO INFORMADO\n");
        }
    }
}

void AssociaFamiliasGruposPessoas(tPessoa pessoa[]) {
    int indiceMae, indicePai, indiceFilho;
    
    scanf("mae: %d, pai: %d, filho: %d\n", &indiceMae, &indicePai, &indiceFilho);

    pessoa[indiceFilho].mae = &pessoa[indiceMae];
    pessoa[indiceFilho].pai = &pessoa[indicePai];
}
