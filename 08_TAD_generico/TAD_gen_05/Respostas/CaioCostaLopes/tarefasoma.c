#include <stdio.h>
#include <stdlib.h>
#include "tarefasoma.h"

struct soma{
    float numero1;
    float numero2;
};

tSoma *CriaSoma(float n1, float n2) {
    tSoma *soma = (tSoma*)malloc(sizeof(tSoma));

    if (soma == 0) {
        printf("Erro na alocacao de memoria da soma ");
        DestroiTarefaSoma(soma);
        return soma;
    }

    soma->numero1 = n1;
    soma->numero2 = n2;

    return soma;
}

void ExecutaTarefaSoma(void *sum) {
    tSoma *soma = sum;

    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f", (*soma).numero1, (*soma).numero2, ((*soma).numero1 + (*soma).numero2));
}

void DestroiTarefaSoma(void *sum) {
    tSoma *soma = sum;

    if (soma != NULL) {
        free(soma);
        soma = NULL;
    }
}