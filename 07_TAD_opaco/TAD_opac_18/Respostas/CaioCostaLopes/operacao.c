#include <stdio.h>
#include <stdlib.h>
#include "operacao.h"

struct Operacao {
    int idConta;
    float valor;
};

tOperacao *CriaOperacao(tConta *conta, float valor) {
    tOperacao *operacao = (tOperacao*)malloc(sizeof(tOperacao));

    if (operacao == NULL) {
        printf("Erro na alocacao de memoria da operacao ");
        return operacao;
    }

    operacao->idConta = RetornaIdConta(conta);
    operacao->valor = valor;
}

float ConsultaValorOperacao(tOperacao *op) {
    return (*op).valor;
}

void ImprimeOperacao(tOperacao *op) {
    printf("\nOperação na conta %d com valor %.2f", (*op).idConta, (*op).valor);
}

void DestroiOperacao(tOperacao *op) {
    if (op != NULL) {
        free(op);
        op = NULL;
    }
}