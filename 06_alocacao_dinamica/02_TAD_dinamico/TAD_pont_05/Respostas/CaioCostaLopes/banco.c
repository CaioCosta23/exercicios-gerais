#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

#define QTD_CONTAS_ALOCADAS 5

tBanco *CriaBanco() {
    int ca;
    tBanco *banco = (tBanco*)malloc(sizeof(tBanco));

    if (banco == NULL) {
        printf("Erro na alocacao de memoria do banco ");
        return banco;
    }

    banco->contasAlocadas = QTD_CONTAS_ALOCADAS;
    banco->qtdContas = 0;

    banco->contas = (tConta**)malloc((*banco).contasAlocadas * sizeof(tConta*));
    if ((*banco).contas == NULL) {
        printf("Erro na alocacao de memoria no vetor de contas do banco");
        DestroiBanco(banco);
    }
    return banco;
}

void AbreContaBanco(tBanco *banco) {
    int ca;

    if ((*banco).qtdContas == (*banco).contasAlocadas) {
        banco->contasAlocadas += QTD_CONTAS_ALOCADAS;
        banco->contas = (tConta**)realloc((*banco).contas, (*banco).contasAlocadas *sizeof(tConta*));
        if ((*banco).contas == NULL) {
            printf("Erro na realocacao de memoria no vetor de contas do banco!\n");
            DestroiBanco(banco);
        }
    }

    if (banco != NULL) {
        banco->contas[(*banco).qtdContas] = CriaConta();
        if ((*banco).contas[(*banco).qtdContas] == NULL) {
            printf("%d!\n", ((*banco).qtdContas + 1));
            DestroiBanco(banco);
        }else {
            LeConta((*banco).contas[(*banco).qtdContas]);
            banco->qtdContas += 1;
        }
    }
}

void SaqueContaBanco(tBanco *banco) {
    int numero, c;
    float valor;

    scanf("%d %f\n", &numero, &valor);

    for (c = 0; c < (*banco).qtdContas; c++) {
        if (VerificaConta((*banco).contas[c], numero)) {
            SaqueConta((*banco).contas[c], valor);
            break;
        }
    }
}

void DepositoContaBanco(tBanco *banco) {
    int numero, c;
    float valor;

    scanf("%d %f\n", &numero, &valor);

    for (c = 0; c < (*banco).qtdContas; c++) {
        if (VerificaConta((*banco).contas[c], numero)) {
            DepositoConta((*banco).contas[c], valor);
            break;
        }
    }
}

void TransferenciaContaBanco(tBanco *banco) {
    int numeroOrigem, numeroDestino, cd, co;
    float valor;
    int encerraOperacao = 0;

    scanf("%d %d %f\n", &numeroDestino, &numeroOrigem, &valor);

    for (cd = 0; cd < (*banco).qtdContas; cd++) {
        if (VerificaConta((*banco).contas[cd], numeroDestino)) {
            for (co = 0; co < (*banco).qtdContas; co++) {
                if (VerificaConta((*banco).contas[co], numeroOrigem)) {
                    TransferenciaConta((*banco).contas[cd], (*banco).contas[co], valor);
                    encerraOperacao = 1;
                    break;
                }
            }
            if (encerraOperacao) {
                break;
            }
        }
    }
}

void ImprimeRelatorioBanco(tBanco *banco) {
    int r;

    printf("===| Imprimindo Relatorio |===\n");

    for (r = 0; r < (*banco).qtdContas; r++) {
        ImprimeConta((*banco).contas[r]);
        printf("\n");
    }
}

void DestroiBanco(tBanco *banco) {
    int c;

    if (banco != NULL) {
        if ((*banco).contas != NULL) {
            for (c = 0; c < (*banco).qtdContas; c++) {
                DestroiConta((*banco).contas[c]);
            }
            free((*banco).contas);
            banco->contas = NULL;
        }
        free(banco);
        banco = NULL;
    }
}