#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array *CriarArray() {
    Array *lista = (Array*)malloc(sizeof(Array));
    
    if (lista == NULL) {
        printf("Erro na alocacao da estrutura do array!\n");
        exit(1);
    }

    lista->data = NULL;
    lista->tamanho = 0;

    return lista;
}

void LerArray(Array *array) {
    array->data = (int*)calloc(((*array).tamanho + 1), sizeof(int));

    if ((*array).data == NULL) {
        printf("Erro na alocacao do vetor da estrutura do array na posicao %d!\n", (*array).tamanho);
        DestruirArray(array);
        exit(1);
    }

    while(scanf("%d", &array->data[(*array).tamanho]) == 1) {
        array->tamanho += 1;
        array->data = (int*)realloc((*array).data, ((*array).tamanho + 1) * sizeof(int));
        if ((*array).data == NULL) {
            printf("Erro na realocacao do vetor da estrutura do array na posicao %d!\n", (*array).tamanho);
            DestruirArray(array);
            exit(1);
        }
    }
    scanf("%*[^\n]\n");
}

void OrdenarArray(Array *array) {
    int a1, a2, aux;

    for (a1 = 0; a1 < ((*array).tamanho - 1); a1++) {
        for(a2 = a1 + 1; a2 < (*array).tamanho; a2++) {
            if ((*array).data[a1] > (*array).data[a2]) {
                aux = (*array).data[a1];
                array->data[a1] = (*array).data[a2];
                array->data[a2] = aux;
            }
        }
    }
}

int BuscaBinariaArray(Array *array, int elementoBuscado) {
    int inicio = 0;
    int fim = (*array).tamanho - 1;
    int meio;

    while (inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;

        if ((*array).data[meio] == elementoBuscado) {
            return meio;
        }

        if ((*array).data[meio] < elementoBuscado) {
            inicio = meio + 1;
        }else{
            if ((*array).data[meio] > elementoBuscado) {
                fim = meio - 1;
            }
        }
    }
    return -1; // Elemento não encontrado
}

void DestruirArray(Array *array) {
    if (array != NULL) {
        if ((*array).data != NULL) {
            free((*array).data);
            array->data = NULL;
        }
        free(array);
        array = NULL;
    }
}