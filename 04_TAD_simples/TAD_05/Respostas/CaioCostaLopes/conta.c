#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

tConta CriaConta(int numero, tUsuario user) {
    tConta conta;

    conta.user = user;
    conta.numero = numero;
    conta.saldo = 0.00;

    return conta;
}

void ImprimeConta(tConta conta) {
    printf("Conta: %d\n", conta.numero);
    printf("Saldo: R$ %.2f\n", conta.saldo);
    ImprimeUsuario(conta.user);
}

int VerificaConta(tConta conta, int numero) {
    return (numero == conta.numero);
}

tConta SaqueConta(tConta conta, float valor) {
    conta.saldo -= valor;

    return conta;
}

tConta DepositoConta(tConta conta, float valor) {
    conta.saldo += valor;

    return conta;
}