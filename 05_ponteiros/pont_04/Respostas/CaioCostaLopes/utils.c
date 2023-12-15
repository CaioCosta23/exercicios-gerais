#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void LeNumeros(int *array, int tamanho) {
    int i;

    for (i  = 0; i < tamanho; i++) {
        scanf("%d", array + i);
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media) {
    int i;
    int soma = 0;
    
    for(i = 0; i < tamanho; i++) {
        if ((i == 0) || (*(array + i) > *maior)) {
            *maior = *(array + i);
        }
        if ((i == 0) || (*(array + i) < *menor)) {
            *menor = *(array + i);
        }
        soma += *(array + i);
    }

    *media = (float)soma / (float)tamanho;
}