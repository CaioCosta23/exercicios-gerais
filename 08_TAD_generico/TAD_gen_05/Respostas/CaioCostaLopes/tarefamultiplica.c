#include <stdio.h>
#include <stdlib.h>
#include "tarefamultiplica.h"

struct mult{
    float numero1;
    float numero2;
};

tMult *CriaTarefaMultiplicar(float n1, float n2) {
    tMult *multiplicacao = (tMult*)malloc(sizeof(tMult));

    if (multiplicacao == NULL) {
        printf("Erro na alocacao de memoria da multiplicacao ");
        DestroiTarefaMultiplicar(multiplicacao);
        return multiplicacao;
    }

    multiplicacao->numero1 = n1;
    multiplicacao->numero2 = n2;

    return multiplicacao;
}

void ExecutaTarefaMultiplicar(void *mult) {
    tMult *multiplicacao = mult;

    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f", (*multiplicacao).numero1, (*multiplicacao).numero2, ((*multiplicacao).numero1 * (*multiplicacao).numero2));
}

void DestroiTarefaMultiplicar(void *mult) {
    tMult *multiplicacao = mult;

    if (multiplicacao != NULL) {
        free(multiplicacao);
        multiplicacao = NULL;
    }
}