#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

tPessoa CriaPessoa() {
    tPessoa pessoa;

    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    pessoa.irmao = NULL;

    return pessoa;
}

void LePessoa(tPessoa *pessoa) {
    scanf("%*[^\n]");
    scanf("%*c");
    scanf("%[^\n]\n", (*pessoa).nome);
    //De onde está surgindo o primeiro '\n' lido? (Verificar casos de teste de entrada); 
}

int VerificaSeTemPais(tPessoa *pessoa) {
    return (((*pessoa).mae != NULL) || ((*pessoa).pai != NULL));
}

/**
 * @brief Função auxiliar de 'ImprimePessoa()': coleta e imprime o nome do parente da pessoa que foi recebido no 'ImprimePessoa()';
 * 
 * @param parente Ponteiro para parente (pai, mãe ou irmão) da pessoa que está em 'ImprimePessoa()';
 */
void ColetaNomeParente(tPessoa *parente) {
    printf("%s\n", (*parente).nome);
}

void ImprimePessoa(tPessoa *pessoa) {
    if (VerificaSeTemPais(pessoa)) {
        printf("NOME COMPLETO: %s\n", (*pessoa).nome);
        printf("PAI: ");
        if ((*pessoa).pai != NULL) {
            
            ColetaNomeParente((*pessoa).pai);
        }else {
            printf("NAO INFORMADO\n");
        }
        printf("MAE: ");
        if ((*pessoa).mae != NULL) {
            
            ColetaNomeParente((*pessoa).mae);
        }else {
            printf("NAO INFORMADO\n");
        }
        printf("IRMAO: ");
        if ((*pessoa).irmao != NULL) {
            
            ColetaNomeParente((*pessoa).irmao);
        }else {
            printf("NAO INFORMADO\n");
        }
    }
}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2) {
    return ((((*pessoa1).pai) == ((*pessoa2).pai)) && ((*pessoa1).mae == (*pessoa2).mae));
}

void AssociaFamiliasGruposPessoas(tPessoa pessoa[], int numPessoas) {
    int a, qtdAssociacoes, indiceMae, indicePai, indiceFilho, indiceIrmao, p1, p2;

    scanf("%d\n", &qtdAssociacoes);

    for (a = 0; a < qtdAssociacoes; a++) {
        scanf("mae: %d, pai: %d, filho:%d\n", &indiceMae, &indicePai, &indiceFilho);

        if (indiceMae != -1) {
            pessoa[indiceFilho].mae = &pessoa[indiceMae];
        }
        if (indicePai != -1) {
            pessoa[indiceFilho].pai = &pessoa[indicePai];
        }
    }

    for (p1 = 0; p1 < numPessoas; p1++) {
        for (p2 = 0; p2 < numPessoas; p2++) {
            if (p2 == p1) {
                continue;
            }
            if (VerificaIrmaoPessoa(&pessoa[p1], &pessoa[p2])) {
                pessoa[p1].irmao = &pessoa[p2];
                break;
            }
        }
    }
}