#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eleitor.h"

tEleitor CriaEleitor(int id, int votoP, int votoG) {
    tEleitor eleitor;

    eleitor.id = id;
    eleitor.votoP = votoP;
    eleitor.votoG = votoG;

    return eleitor;
}

tEleitor LeEleitor() {
    int id, votoP, votoG;
    tEleitor eleitor;

    scanf("%d %d %d\n", &id, &votoG, &votoP);

    eleitor = CriaEleitor(id, votoP, votoG);

    return eleitor;
}

int ObtemVotosPresidente(tEleitor eleitor) {
    return eleitor.votoP;
}

int ObtemVotosGovernador(tEleitor eleitor) {
    return eleitor.votoG;
}

int EhMesmoEleitor(tEleitor eleitor1, tEleitor eleitor2) {
    return (eleitor1.id == eleitor2.id);
}