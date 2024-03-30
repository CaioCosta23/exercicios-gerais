#include <stdio.h>
#include <stdlib.h>
#include "eleitor.h"

#define MAX_ELEITORES 10

tEleitor *CriaEleitor() {
    tEleitor *eleitor = (tEleitor *) malloc(sizeof(tEleitor));

    if (eleitor == NULL) {
        printf("Erro na alocacao da estrutura de dados do eleitor!");
    }

    eleitor->id = -1;
    eleitor->votoG = -1;
    eleitor->votoP = -1;

    return eleitor;
}

void LeEleitor(tEleitor *eleitor) {

    scanf("%d %d %d", &(*eleitor).id, &(*eleitor).votoP, &(*eleitor).votoG);
}

int ObtemVotoPresidente(tEleitor *eleitor) {
    return (*eleitor).votoP;
}

int ObtemVotoGovernador(tEleitor *eleitor) {
    return (*eleitor).votoG;
}

int EhMesmoEleitor(tEleitor *eleitor1, tEleitor *eleitor2) {
    return ((*eleitor1).id == (*eleitor2).id);
}

void ApagaEleitor(tEleitor *eleitor) {
    free(eleitor);
}