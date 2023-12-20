#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

char *CriaVetor(int tamanho) {
    char *vetor = malloc(tamanho * sizeof(char));
    int v;

    if (vetor == NULL) {
        printf("Erro na alocacao!");
        exit(1);
    }

    for (v = 0; v < tamanho; v++) {
        vetor[v] = '_';
    }
}

void LeVetor(char vetor[], int tamanho) {
    int c = 0;
    char letra;

    while ((c <tamanho) && (letra != '\n')) {
        scnaf("%c", &letra);
        vetor[c] = letra;

        c++;
    } 
}

void ImprimeString(char vetor[], int tamanho) {
    int v;

    for (v = 0; v < tamanho; v++) {
        printf("_");
    }

    printf("\n");

    for (v = 0; v < tamanho; v++) {
        printf("%c", vetor[v]);
    }
}

void LiberaVetor(char *vetor) {
    free(vetor);
}