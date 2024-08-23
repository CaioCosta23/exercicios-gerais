#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

struct generic {
    int tamanho;
    void *vetor;
    Type tipoElemento;
};

tGeneric *CriaGenerico(Type type, int numElem) {
    tGeneric *tipoGenerico = (tGeneric*)malloc(sizeof(tGeneric));

    if (tipoGenerico == NULL) {
        printf("Erro na alocacao de memoria do tipo genérico!\n");
    }

    tipoGenerico->tamanho = numElem;
    
    if (type == INT) {
        tipoGenerico->tipoElemento = INT;
        tipoGenerico->vetor = (int*)malloc((*tipoGenerico).tamanho * sizeof(int));
        if ((*tipoGenerico).vetor == NULL) {
            printf("Erro na alocacao de memória do vetor (do tipo inteiro)!\n");
            DestroiGenerico(tipoGenerico);
        } 
    }else {
        if (type == FLOAT) {
            tipoGenerico->tipoElemento = FLOAT;
            tipoGenerico->vetor = (float*)malloc((*tipoGenerico).tamanho * sizeof(float));
            if ((*tipoGenerico).vetor == NULL) {
                printf("Erro na alocacao de memória do vetor (do tipo inteiro)!\n");
                DestroiGenerico(tipoGenerico);
            } 
        }
    }

    return tipoGenerico;
}

void LeGenerico(tGeneric *gen) {
    int v;

    printf("\nDigite o vetor:\n");

    if ((*gen).tipoElemento == INT) {
        for (v = 0; v < (*gen).tamanho; v++) {
            scanf("%d", &((int*)gen->vetor)[v]);
        }
    }else {
        if ((*gen).tipoElemento == FLOAT) {
            for (v = 0; v < (*gen).tamanho; v++) {
                scanf("%f", &((float*)gen->vetor)[v]);
            }
        }
    }
}

void ImprimeGenerico(tGeneric *gen) {
    int v;

    if ((*gen).tipoElemento == INT) {
        for (v = 0; v < (*gen).tamanho; v++) {
            printf("%d ", ((int*)(*gen).vetor)[v]);
        }
    }else {
        if ((*gen).tipoElemento == FLOAT) {
            for (v = 0; v < (*gen).tamanho; v++) {
                printf("%.2f ", ((float*)(*gen).vetor)[v]);
            }
        }     
    }
}

void DestroiGenerico(tGeneric *gen) {
    if (gen != NULL) {
        if ((*gen).vetor != NULL) {
            free((*gen).vetor);
            gen->vetor = NULL;
        }     
        free(gen);
        gen = NULL;
    }
}