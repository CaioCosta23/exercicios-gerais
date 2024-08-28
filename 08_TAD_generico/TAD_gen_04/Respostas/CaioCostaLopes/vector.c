#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define TAM_INICIAL_VETOR 10

struct Vector {
    DataType *dados;
    int tamanho;
    int limiteTamanho;
};


Vector *VectorConstruct() {
    Vector *vetor = (Vector*)malloc(sizeof(Vector));

    if (vetor == NULL) {
        printf("Erro na alocacao de memoria do vetor ");
        return vetor;
    }

    vetor->dados = (DataType*)malloc(TAM_INICIAL_VETOR * sizeof(DataType));
    if ((*vetor).dados == NULL) {
        printf("Erro na alocacao de memoria da lista da estrutura do vetor de");
        exit(1);
    }

    vetor->tamanho = 0;
    vetor->limiteTamanho = TAM_INICIAL_VETOR;

    return vetor;
}

void VectorPushBack(Vector *v, DataType val) {
    if (VectorSize(v) == (*v).limiteTamanho) {
        v->limiteTamanho += TAM_INICIAL_VETOR;
        v->dados = (DataType*)realloc(v, (*v).limiteTamanho * sizeof(DataType));
        if (v == NULL) {
            printf("Erro na realocacao de memoria do vetor de ");
        }else {
            v->dados[VectorSize(v)] = val;
            v->tamanho += 1;
        }
    }else {
        v->dados[VectorSize(v)] = val;
        v->tamanho += 1;
    }
}

DataType VectorGet(Vector *v, int i) {
    return ((*v).dados[i]);
}

int VectorSize(Vector *v) {
    return (*v).tamanho;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)) {
    int d;

    if (v != NULL) {
        if ((*v).dados != NULL) {
            for(d = 0; d < VectorSize(v); d++) {
                destroy(VectorGet(v, d));
            }
            free((*v).dados);
            v->dados = NULL;
        }
        free(v);
        v = NULL;
    }
}