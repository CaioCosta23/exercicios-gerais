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

LerArray(Array *array) {
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
            if ((*array).data[a1] < (*array).data[a2]) {
                aux = (*array).data[a1];
                array->data[a1] = (*array).data[a2];
                array->data[a2] = aux;
            }
        }
    }
}

int BuscaBinaria(Array *array, int elementoBuscado) {
    int primeiroIndice = 0, ultimoIndice = (*array).tamanho - 1;
    int indiceMeio, elementoMeio;
    int encontrado = -1;

    indiceMeio = (primeiroIndice + ultimoIndice) / 2;
    elementoMeio = (*array).data[indiceMeio];

    while(1) {
        if (primeiroIndice == ultimoIndice) {
            if (elementoMeio != elementoBuscado) {
                break;
            }
        }else {
            if (elementoMeio == elementoBuscado) {
                encontrado = indiceMeio;
            }else {
                if (elementoMeio > elementoBuscado) {
                    ultimoIndice = indiceMeio - 1;
                    indiceMeio = (primeiroIndice + ultimoIndice) / 2;
                    elementoMeio = (*array).data[indiceMeio];
                    
                    if (elementoMeio == elementoBuscado) {
                        encontrado = indiceMeio;
                    }
                }else {
                    if (elementoMeio < elementoBuscado) {
                        primeiroIndice = indiceMeio - 1;
                        indiceMeio = (primeiroIndice + ultimoIndice) / 2;
                        elementoMeio = (*array).data[indiceMeio];
                        
                        if (elementoMeio == elementoBuscado) {
                            encontrado = indiceMeio;
                        }
                    }
                }
            }
        }
    }
    return encontrado;
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