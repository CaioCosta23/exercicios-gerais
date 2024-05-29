#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct Array {
    int *elemento;
    int tamanho;
};

Array *CriarArray() {
    Array *lista = (Array*)malloc(sizeof(Array));

    if (lista == NULL) {
        printf("Erro na alocacao do array!\n");
        exit(1);
    }

    lista->elemento = NULL;
    lista->tamanho = 0;

    return lista;
}

void LerArray(Array *array) {
    array->elemento = (int*)calloc(((*array).tamanho) + 1, sizeof(int));

    if ((*array).elemento == NULL) {
        printf("Erro na alocacao do vetor da estrutura do array na posicao %d!\n", (*array).tamanho);
        DestruirArray(array);
        exit(1);
    }

    while (scanf("%d", &array->elemento[(*array).tamanho]) == 1) {
        array->tamanho += 1;
        array->elemento = (int*)realloc((*array).elemento, ((*array).tamanho + 1) * sizeof(int));
        if ((*array).elemento == NULL) {
            printf("Erro na realocacao do vetor da estrutura do array na posicao %d!\n", (*array).tamanho);
            DestruirArray(array);
            exit(1);
        }
    }
    scanf("%*[^\n]\n");
}

void OrdenarArray(Array *array) {
    int a1, a2, elementoAuxiliar;

    for (a1 = 0; a1 < ((*array).tamanho - 1); a1++) {
        for (a2 = a1 + 1; a2 < (*array).tamanho; a2++)  {
            if ((*array).elemento[a1] > (*array).elemento[a2]) {
                elementoAuxiliar = (*array).elemento[a1];
                array->elemento[a1] = (*array).elemento[a2];
                array->elemento[a2] = elementoAuxiliar;
            }
        }
    }
}

int BuscaBinariaArray(Array *array, int elementoBuscado) {
    int inicio, meio, fim;

    inicio = 0;
    fim = (*array).tamanho - 1;
    
    while (inicio <= fim) {
        meio = inicio + ((fim - inicio) / 2);

        if ((*array).elemento[meio] == elementoBuscado) {
            return meio;
        }

        if ((*array).elemento[meio] < elementoBuscado) {
            inicio = meio += 1;
        }else {
            if ((*array).elemento[meio] > elementoBuscado) {
                fim = meio - 1;
            }
        }
    }
    return -1;
}

void DestruirArray(Array *array) {
    if (array != NULL) {
        if ((*array).elemento != NULL) {
            free((*array).elemento);
            array->elemento = NULL;
        }
        free(array);
        array = NULL;
    }
}