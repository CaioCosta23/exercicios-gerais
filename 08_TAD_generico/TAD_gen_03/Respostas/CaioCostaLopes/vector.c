#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "aluno.h"

struct Vector {
    data_type *dados;
    int tamanho;
};

Vector *VectorConstruct() {
    Vector *vetor = (Vector*)malloc(sizeof(Vector));

    if (vetor == NULL) {
        printf("Erro na alocacao de memoria do vetor inicial!\n");
        exit(1);
    }

    vetor->tamanho = 0;
    
    vetor->dados = (data_type*)malloc(sizeof(data_type));
    if ((*vetor).dados == NULL) {
        printf("Erro na alocacao de memoria do vetor de dados!\n");
        VectorDestroy(vetor, NULL);
        exit(1);
    }

    return vetor;
}

void VectorPushBack(Vector *v, data_type val) {
    v->dados = (data_type*)realloc((*v).dados, ((*v).tamanho + 1) * sizeof(data_type));
    if ((*v).dados == NULL) {
        printf("Erro na realocacao de memoria do vetor de dados!\n");
        VectorDestroy(v, DestroiAluno);
        exit(1);
    }

    v->dados[(*v).tamanho] = val;
    v->tamanho += 1;
}

data_type VectorGet(Vector *v, int i) {
    return (*v).dados[i];
}

int VectorSize(Vector *v) {
    return (*v).tamanho;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)) {
    int t;

    if (v != NULL) {
        if ((*v).dados != NULL) {
            for (t = 0; t < VectorSize(v); t++) {
                destroy(VectorGet(v, t));
            }
            free((*v).dados);
            v->dados = NULL;
        }
        free(v);
        v = NULL;
    }
}

