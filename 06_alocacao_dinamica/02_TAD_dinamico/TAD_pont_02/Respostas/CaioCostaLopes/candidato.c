#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidato.h"

#define TAM_MAX 50

tCandidato *CriaCandidato() {
    tCandidato *candidato = (tCandidato *)malloc(sizeof(tCandidato));

    if (candidato == NULL) {
        printf("Erro na alocacao do candidato!\n");
        exit(1);
    }

    candidato->nome = (char *)malloc(TAM_MAX * sizeof(char));
    candidato->partido = (char *)malloc(TAM_MAX * sizeof(char));
    candidato->cargo = '\0';
    candidato->id = -1;
    candidato-> votos = -1;

    return candidato;
}

void LeCandidato(tCandidato *candidato) {
    scanf("\n%[^,], %[^,], %c, %d\n", (*candidato).nome, (*candidato).partido, &(*candidato).cargo, &(*candidato).id);
}

int VerificaIdCandidato(tCandidato *candidato, int id) {
    return (*candidato).id == id;
}

int EhMesmoCandidato(tCandidato *candidato1, tCandidato *candidato2) {
    
}