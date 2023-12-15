#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

void LeDadosParaVetor(int *vet, int tam) {
    int i;
    int lista[tam];

    for (i = 0; i < tam; i++) {
        scanf("%d", &lista[i]);
    }
    vet = lista;
}

void ImprimeDadosDoVetor(int *n, int tam) {
    int i;
    
    for (i = 0; i < tam; i++) {
        printf("%d ", *(n + i));
    }
    printf("\n");
}

void TrocaSeAchaMenor(int *vet, int tam, int *paraTrocar) {
    int *x;
    int aux;

    for (*x = paraTrocar + 1; x < vet + tam; x++) {
        if (*x < *paraTrocar) {
            aux = *x;
            *x = paraTrocar;
            *paraTrocar = aux;
        }
    }
}

void OrdeneCresecnte(int *vet, int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        TrocaSeAchaMenor(vet, tam, vet + i);
    }
}