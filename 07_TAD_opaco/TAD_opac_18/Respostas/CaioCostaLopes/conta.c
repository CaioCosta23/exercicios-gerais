#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

struct Conta {
    int id;
    int saldo;
};

tConta *CriaConta(int id) {
    tConta *conta = (tConta*)malloc(sizeof(conta));

    if (conta == NULL) {
        printf("Erro na alocacao de memoria da conta ");
        return conta;
    }

    conta->id = id;
    conta->saldo = 0;

    return conta;
}

void AlteraSaldoConta(tConta *conta, float valor) {
    conta->saldo += valor;
}

int ConfereIdConta(tConta *conta, int id) {
    return ((*conta).id == id);
}

int RetornaIdConta(tConta *conta) {
    return (*conta).id;
}

float RetornaSaldoConta(tConta *conta) {
    return (*conta).saldo;
}

void DestroiConta(tConta *conta) {
    if (conta != NULL) {
        free(conta);
        conta = NULL;
    }
}