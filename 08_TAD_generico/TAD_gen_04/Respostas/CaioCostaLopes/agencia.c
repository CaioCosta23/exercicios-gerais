#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"

#define TAM_NOME_LOCAL_AGENCIA 100

struct Agencia {
    int id;
    char *local;
    DataType contas;
};

tAgencia *CriaAgencia() {
    tAgencia *agencia = (tAgencia*)malloc(sizeof(tAgencia));

    if (agencia == NULL) {
        printf("Erro na alocacao de memoria da agencia ");
        return agencia;
    }

    agencia->id = -1;
    agencia->local = (char*)malloc(TAM_NOME_LOCAL_AGENCIA * sizeof(char));
    if ((*agencia).local == NULL) {
        printf("Erro na alocacaco de memoria do nome da agencia ");
        DestroiAgencia(agencia);
        return agencia;
    }

    agencia->contas = VectorConstruct();
    if ((*agencia).contas == NULL) {
        DestroiAgencia(agencia);
    }
    return agencia;
}

void LeAgencia(tAgencia *agencia) {
    scanf("%d;%[^\n]\n", &agencia->id, agencia->local);
}


void AdicionaConta(tAgencia *agencia, tConta *conta) {
    VectorPushBack((*agencia).contas, conta);
}

int ComparaAgencia(int numAgencia, tAgencia *agencia) {
    return (numAgencia == (*agencia).id);
}

float GetSaldoMedioAgencia(tAgencia *agencia) {
    int c;
    float saldoMedio = 0;

    for (c = 0; c < VectorSize((*agencia).contas); c++) {
        saldoMedio += GetSaldoConta(VectorGet((*agencia).contas, c));
    }
    return saldoMedio;
}

void ImprimeDadosAgencia(tAgencia *agencia) {
    printf("\tNome: %s\n", (*agencia).local);
    printf("\tNumero: %d\n", (*agencia).id);
    printf("\tNumero de contas cadastradas: %d\n", VectorSize((*agencia).contas));
    printf("\tSaldo médio: R$%.2f\n\n", GetSaldoMedioAgencia(agencia));
}

void DestroiAgencia(DataType agencia) {
    tAgencia *agen = (tAgencia*)agencia;

    if (agen != NULL) {
        if ((*agen).local != NULL) {
            free((*agen).local);
            (*agen).local = NULL;
        }
        VectorDestroy((*agen).contas, DestroiConta);
        free(agen);
        agen = NULL;
    }
}