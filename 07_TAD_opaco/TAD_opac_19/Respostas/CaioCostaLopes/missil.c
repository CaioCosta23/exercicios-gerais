#include <stdio.h>
#include <stdlib.h>
#include "missil.h"

struct missil {
    char nome[MAX_TAM];
    float coordX;
    float coordY;
    float poder;
};


tMissil LeMissil() {
    tMissil missil = (tMissil)malloc(sizeof(struct missil));

    if (missil == NULL) {
        printf("Erro na alocacao de memoria do missil ");
        return missil;
    }

    scanf("%s %f %f %f\n", missil->nome, &missil->coordX, &missil->coordY, &missil->poder);

    return missil;
}

void ImprimeMissil(tMissil missil) {
    printf("M-%s: %.2f\n", (*missil).nome, (*missil).poder);
}

float GetMissilY(tMissil missil) {
    return (*missil).coordY;
}

float GetMissilX(tMissil missil) {
    return (*missil).coordX;
}


float GetMissilPoder(tMissil missil) {
    return (*missil).poder;
}

void ReduzPoder(tMissil missil, float valor) {
    missil->poder -= valor;

    if ((*missil).poder < 0) {
        missil->poder = 0;
    }
}


void LiberaMissil(tMissil missil) {
    if (missil != NULL) {
        free(missil);
        missil = NULL;
    }
}