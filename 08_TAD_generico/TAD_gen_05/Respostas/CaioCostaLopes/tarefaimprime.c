#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefaimprime.h"

#define TAM_MAX_MSG 1001

struct impr{
    char *mensagem;
};

tImpr *CriaTarefaImprimir(char *msg) {
    tImpr *impressao = (tImpr*)malloc(sizeof(tImpr));

    if (impressao == NULL) {
        printf("Erro na alocacao de memoria da impressao ");
        DestroiTarefaImprimir(impressao);
        return impressao;
    }

    impressao->mensagem = (char*)calloc(TAM_MAX_MSG, sizeof(char));
    if ((*impressao).mensagem == NULL) {
        printf("Erro na a locacaco de memoria da mensagem de impressao ");
        DestroiTarefaImprimir(impressao);
        return impressao;
    }

    strcpy(impressao->mensagem, msg);

    return impressao;
}

void ExecutaTarefaImprimir(void *imp) {
    tImpr *impressao = imp;

    printf("\n%s", (*impressao).mensagem);
}

void DestroiTarefaImprimir(void *imp) {
    tImpr *impressao = imp;

    if (impressao != NULL) {
        if ((*impressao).mensagem != NULL) {
            free((*impressao).mensagem);
            impressao->mensagem = NULL;
        }
        free(impressao);
        impressao = NULL;
    }
}