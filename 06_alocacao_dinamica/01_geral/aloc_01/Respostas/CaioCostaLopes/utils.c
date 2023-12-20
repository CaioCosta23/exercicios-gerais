#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int *CriaVetor(int tamanho) {
    int *vetor = (int *) malloc(tamanho * sizeof(int));

    if (vetor == NULL) {
        printf ("Problema na alocacao!");
        exit (1);
    }
    return vetor;
}

void LeVetor(int vetor[], int tamanho) {
    int v;

    for (v = 0; v < tamanho; v++) {
        scanf("%d", &vetor[v]);
    }
}

float CalculaMedia(int vetor[], int tamanho) {
    int v;
    float soma = 0;

    for (v = 0; v < tamanho; v++) {
        soma += vetor[v];
    }
    return (soma / tamanho);
}

void LiberaVetor(int *vetor) {
    free(vetor);
}