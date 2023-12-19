#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

void LeVetor(Vetor *vetor) {
    int v;
    
    scanf("%d", (*vetor).tamanhoUtilizado);
    
    for (v = 0; v < (*vetor).tamanhoUtilizado; v++) {
        scanf("%d", (*vetor).elementos[v]);
    }
}

int AplicaOperacaoVetor(Vetor *vetor, Operation op) {
    int v, resultado;

    resultado = (*vetor).elementos[0];

    for (v = 1; v < (*vetor).tamanhoUtilizado; v++) {
        resultado = op(resultado, (*vetor).elementos[v]);
    }
}