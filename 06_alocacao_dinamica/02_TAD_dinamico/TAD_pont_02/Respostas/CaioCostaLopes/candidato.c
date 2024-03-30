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
    if ((*candidato).nome == NULL) {
        printf("Erro na alocacao do nome do candidato!\n");
        exit(1);
    }

    candidato->partido = (char *)malloc(TAM_MAX * sizeof(char));
    if((*candidato).partido == NULL) {
        printf("Erro na alocacao do nome do partido do candidato!\n") {
            exit(1);
        }
    }
    
    candidato->cargo = '\0';
    candidato->id = -1;
    candidato-> votos = 0;

    return candidato;
}

void LeCandidato(tCandidato *candidato) {
    scanf("\n%[^,], %[^,], %c, %d\n", (*candidato).nome, (*candidato).partido, &(*candidato).cargo, &(*candidato).id);
}

int VerificaIdCandidato(tCandidato *candidato, int id) {
    return (*candidato).id == id;
}

int EhMesmoCandidato(tCandidato *candidato1, tCandidato *candidato2) {
    if(((*candidato1).id == (*candidato2).id) && (strcmp((*candidato1).partido, (*candidato2).partido) == 0)) {
        return 1;
    }
    return 0;
}

char ObtemCargo(tCandidato *candidato) {
    return (*candidato).cargo;
}

void IncrementaVotoCandidato(tCandidato *candidato) {
    candidato->votos += 1;
}

int ObtemVotos(tCandidato *candidato) {
    return (*candidato).votos;
}

float CalculaPercentualVotos(tCandidato *candidato, int totalVotos) {
    float percentual = 0.00;

    percentual = (float)((*candidato).votos * 100.00) / (float)totalVotos;

    return percentual;
}

void ImprimeCandidato(tCandidato *candidato, float percentualVotos) {
    printf("%s (%s), %d voto(s), %.2f%%\n", (*candidato).nome, (*candidato).partido, (*candidato).votos, percentualVotos);
}

void ApagaCandidato(tCandidato *candidato) {
    free(candidato->nome);
    free(candidato->partido);
    free(candidato);
}