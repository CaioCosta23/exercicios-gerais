#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"

#include "operacao.h"

#define QTD_INICIAL_CONTAS 30

struct Agencia {
    tConta **contas;
    int qtdContas;
    tOperacao **operacoes;
    int qtdOperacoes;
    float saldo;
};

tAgencia *CriaAgencia() {
    int c, qtdContas, id;

    tAgencia *agencia = (tAgencia*)malloc(sizeof(tAgencia));

    if (agencia == NULL) {
        printf("Erro na alocacao de memoria da agencia!\n");
        exit(1);
    }

    scanf("%d\n", &qtdContas);
    agencia->contas = (tConta**)malloc(qtdContas * sizeof(tConta*));
    if ((*agencia).contas == NULL) {
        printf("Erro de alocacao de memoria na lista/vetor de contas da agencia");
        DestroiConta(agencia);
        exit(1);
    }
    agencia->qtdContas = 0;

    while((*agencia).qtdContas < qtdContas) {
        while(1) {
            scanf("%d\n", &id);
            
            if (id > 0) {
                break;
            }
            printf("\nDigite um id valido para a conta ser cadastrada!");
        }
        agencia->contas[(*agencia).qtdContas] = CriaConta(id);
        agencia->qtdContas += 1;
    }

    agencia->operacoes = (tOperacao**)malloc(QTD_INICIAL_CONTAS * sizeof(tOperacao*));
    if ((*agencia).operacoes == NULL) {
        printf("Erro na alocacao de memoria na lista/vetor de operacoes!\n");
        DestroiAgencia(agencia);
        exit(1);
    }
    
    agencia->saldo = 0;

    return agencia;    
}

void LeOperacoes(tAgencia *agencia) {
    int o, id, c;
    float valor;

    for(o = 0; o < (*agencia).qtdOperacoes; o++) {
        scanf("%d %f", &id, &valor);

        if (BuscaContaPorId(agencia, id) != NULL) {
            agencia->operacoes[o] = CriaOperacao(BuscaContaPorId(agencia, id), id);
            agencia->saldo += valor;
        }else {
            printf("\nConta Invalida! Repita a operacao, mas com uma conta valida!");
        }
    }
}

tConta *BuscaContaPorId(tAgencia *agencia, int id) {
    int c;

    for (c = 0; c < (*agencia).qtdContas; c++) {
        if (ConfereIdConta((*agencia).contas[c], id)) {
            return (*agencia).contas[c];
        }
    }
    return NULL;
}

void ImprimeOperacoesSuspeitas(tAgencia *agencia) {
    int o;

    printf("\nLista de operações suspeitas:");
    for (o = 0; o < (*agencia).qtdOperacoes; o++) {
        if ((ConsultaValorOperacao((*agencia).operacoes[o]) > 20000) || (ConsultaValorOperacao((*agencia).operacoes[o]) < 20000)) {
            ImprimeOperacao((*agencia).operacoes[o]);
        }
    }
}

void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia *agencia) {
    int c1, c2, m;
    tConta *contaAuxiliar = NULL;

    for (c1 = 0; c1 < ((*agencia).qtdContas - 1); c1++) {
        for (c2 = (c1 + 1); c2 < (*agencia).qtdContas; c2++) {
            if (RetornaSaldoConta((*agencia).contas[c1]) < RetornaSaldoConta((*agencia).contas[c2])) {
                contaAuxiliar = (*agencia).contas[c1];
                agencia->contas[c1] = (*agencia).contas[c2];
                agencia->contas[c2] = contaAuxiliar;
            }
        }
    }

    printf("\nOs dois correntistas com maior saldo são:");

    for (m = 0; m < 2; m ++) {
        printf("\nId: %d, Saldo: %.2f", RetornaIdConta((*agencia).contas[m]), RetornaSaldoConta((*agencia).contas[m]));
    }
}

void ImprimeSaldoTotal(tAgencia *agencia) {
    printf("\nO saldo total da agencia eh: %.2f", (*agencia).saldo);
}

void DestroiAgencia(tAgencia *agencia) {
    int c, o;

    if (agencia != NULL) {
        if ((*agencia).contas != NULL) {
            for (c = 0; c < (*agencia).qtdContas; c++) {
                DestroiConta((*agencia).contas[c]);
            }
            free((*agencia).contas);
            agencia->contas = NULL;
        }
        if ((*agencia).operacoes != NULL) {
            for (o = 0; o < (*agencia).qtdOperacoes; o++) {
                DestroiOperacao((*agencia).operacoes[o]);
            }
            free((*agencia).operacoes);
            agencia->operacoes == NULL;
        }
        free(agencia);
        agencia = NULL;
    }
}