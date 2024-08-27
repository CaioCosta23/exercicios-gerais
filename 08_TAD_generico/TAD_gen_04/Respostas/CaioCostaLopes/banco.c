#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

#define TAM_NOME_BANCO_ESTIPULADO 100
#define QTD_INICIAL_AGENCIAS 10

struct Banco {
    char *nome;
    DataType agencias;
};

tBanco *CriaBanco() {
    tBanco *banco = (tBanco*)malloc(sizeof(tBanco));

    if (banco == NULL) {
        printf("Erro na alocacao de memoria do banco!\n");
        exit(1);
    }

    banco->agencias = VectorConstruct();
    if ((*banco).agencias == NULL) {
        DestroiBanco(banco);
        exit(1);   
    }

    banco->nome = (char*)malloc(TAM_NOME_BANCO_ESTIPULADO * sizeof(char));
    if ((*banco).nome == NULL) {
        printf("Erro na alocacao de memoria do nome do banco!\n");
        DestroiBanco(banco);
        exit(1);
    }

    return banco;

}
void LeBanco(tBanco *banco) {
    scanf("%[^\n]\n", banco->nome);
}

void AdicionaAgencia(tBanco *banco, tAgencia *agencia) {
    VectorPushBack((*banco).agencias, agencia);
}

void InsereContaBanco(tBanco *banco, int numAgencia, tConta *conta) {
    int a;

    for (a = 0; a < VectorSize((*banco).agencias); a++) {
        if (ComparaAgencia(numAgencia, VectorGet((*banco).agencias, a))) {
            AdicionaConta(VectorGet((*banco).agencias, a), conta);
            break;
        }
    }
}

void ImprimeRelatorioBanco(tBanco *banco) {
    int a;

    printf("%s\n", (*banco).nome);
    printf("Lista de agencias:\n");

    for(a = 0; a < VectorSize((*banco).agencias); a++) {
        ImprimeDadosAgencia(VectorGet((*banco).agencias, a));
    }
}

void DestroiBanco(tBanco *banco) {

    if (banco != NULL) {
        if ((*banco).agencias != NULL) {
            VectorDestroy((*banco).agencias, DestroiAgencia);
        }
        if ((*banco).nome != NULL) {
            free((*banco).nome);
            banco->nome = NULL;
        }
        free(banco);
        banco = NULL;
    }
}