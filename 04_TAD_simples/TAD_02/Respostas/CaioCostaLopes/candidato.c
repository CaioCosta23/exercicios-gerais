#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidato.h"

#define TAM_MAX 50

tCandidato CriarCandidato(char nome[], char partido[], char cargo, int id) {
    tCandidato candidato;

    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;

    return candidato;
}

tCandidato LeCandidato() {
    char nome[TAM_MAX], partido[TAM_MAX];
    char cargo;
    int id;
    tCandidato candidato;

    scanf("\n%[^,], %[^,], %c, %d\n", nome, partido, &cargo, &id);
    
    candidato = CriarCandidato(nome, partido, cargo, id);

    return candidato;
}

int VerificaIdCandidato(tCandidato candidato, int id) {
    return (candidato.id == id);
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2) {
    if ((candidato1.id == candidato2.id) && (strcmp(candidato1.partido, candidato2.partido) == 0)) {
        return 1;
    }
    return 0;
}

char ObtemCargo(tCandidato candidato) {
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato) {
    candidato.votos += 1;

    return candidato;
}

int ObtemVotos(tCandidato candidato) {
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos) {
    float percentual = 0.00;

    percentual = (float)(candidato.votos * 100) / (float)totalVotos;

    return percentual;
}

void ImprimeCandidato(tCandidato candidato, float percentualVotos) {
    printf("%s (%s), %d voto(s), %.2f%%\n", candidato.nome, candidato.partido, candidato.votos, percentualVotos);
}