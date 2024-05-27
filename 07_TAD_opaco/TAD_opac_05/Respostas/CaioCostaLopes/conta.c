#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
#include "usuario.h"

struct Conta {
    int numero;
    float saldo;
    tUsuario *user;
};

tConta *CriaConta() {
    tConta *conta = (tConta*)malloc(sizeof(tConta));
    if (conta == NULL) {
        printf("Erro na alocacao de memoria da conta ");
        return conta;
    }

    conta->user = CriaUsuario();
    if ((*conta).user == NULL) {
        DestroiConta(conta);
        return conta;
    }

    conta->numero = -1;
    conta->saldo = 0.00;

    return conta;
}

void LeConta(tConta *conta) {
    LeUsuario((*conta).user);
    scanf("%d\n", &conta->numero);
}

int VerificaConta(tConta *conta, int numero) {
    return ((*conta).numero == numero);
}

void SaqueConta(tConta *conta, float valor) {
    if ((*conta).saldo >= valor) {
        conta->saldo -= valor;
    }
}

void DepositoConta(tConta *conta, float valor) {
    conta->saldo += valor;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor) {
    if ((*origem).saldo >= valor) {
        SaqueConta(origem, valor);
        DepositoConta(destino, valor);
    }
}

void ImprimeConta(tConta *conta) {
    printf("Conta: %d\n", (*conta).numero);
    printf("Saldo: R$ %.2f\n", (*conta).saldo);
    ImprimeUsuario((*conta).user);
}

void DestroiConta(tConta *conta) {
    if (conta != NULL) {
        if ((*conta).user != NULL) {
            DestroiUsuario((*conta).user);
        }
        free(conta);
        conta = NULL;
    }
}