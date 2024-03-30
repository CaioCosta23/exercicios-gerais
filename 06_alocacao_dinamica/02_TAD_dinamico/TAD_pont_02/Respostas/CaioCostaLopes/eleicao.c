#include <stdio.h>
#include <stdio.h>
#include "eleicao.h"

#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

tEleicao *InicializaEleicao() {
    tEleicao *eleicao = (tEleicao *)malloc(sizeof(tEleicao));
    tCandidato *candidato = NULL;

    if (eleicao == NULL) {
        printf("Erro na alocacao da eleicao!\n");
        exit(1);
    }

    eleicao->eleitores = (tEleitor *)malloc(MAX_ELEITORES * sizeof(tEleitor));
    
    if ((*eleicao).eleitores == NULL) {
        printf("Erro na alocacao do vetor de eleitores!\n");
        exit(1);
    }

    int qtdCandidatos, c;

    eleicao->votosBrancosGovernador = 0;
    eleicao->votosBrancosPresidente = 0;
    eleicao->votosNulosGovernador = 0;
    eleicao->votosNulosPresidente = 0;

    scanf("%d", &qtdCandidatos);

    eleicao->presidentes = (tCandidato *)malloc(MAX_CANDIDATOS_POR_CARGO * sizeof(tCandidato));
    if ((*eleicao).presidentes == NULL) {
        printf("Erro de alocacao no vetor dos presidentes!\n");
        exit(1);
    }
    eleicao->governadores = (tCandidato *)malloc(MAX_CANDIDATOS_POR_CARGO * sizeof(tCandidato));
    if ((*eleicao).governadores == NULL) {
        printf("Erro de alocacao no vetor dos governadores!\n");
        exit(1);
    }

    for (c = 0; c < qtdCandidatos; c++) {
        candidato = CriaCandidato();
        LeCandidato(candidato);

        if (ObtemCargo(candidato) == 'G') {
            eleicao->governadores[(*eleicao).totalGovernadores] = candidato;
            eleicao->totalGovernadores += 1;
        }else {
            if (ObtemCargo(candidato) == 'P') {
                eleicao->presidentes[(*eleicao).totalPresidentes] = candidato;
                eleicao->totalPresidentes += 1;
            }
        }

        eleicao->presidentes = realloc((*eleicao).presidentes, (*eleicao).totalPresidentes);
        if ((*eleicao).presidentes == NULL) {
            printf("Erro na realocacao do vetor dos candidatos a presidente!\n");
            exit(1);
        }
        eleicao->governadores = realloc((*eleicao).governadores, (*eleicao).totalGovernadores);
        if ((*eleicao).governadores == NULL) {
            printf("erro na realocacao do vetor dos candidatos a governador!\n");
            exit(1);
        }

        if (((*eleicao).totalGovernadores > MAX_CANDIDATOS_POR_CARGO) || ((*eleicao).totalPresidentes) > MAX_CANDIDATOS_POR_CARGO) {
            ApagaEleicao(eleicao);
            printf("ELEICAO ANULADA\n");
            exit(1);
        }
    }

    return eleicao;
}

void RealizaEleicao(tEleicao *eleicao) {
    int governadorValido = 0, presidenteValido = 0;
    int e1, e2, g, p, qtdEleitores, v;
    tEleitor *eleitor = NULL;

    scanf("%d", &qtdEleitores);

    if (qtdEleitores > MAX_ELEITORES) {
        ApagaEleicao(eleicao);
        printf("ELEICAO ANULADA\n");
        exit(1);
    }

    eleicao->eleitores = realloc((*eleicao).eleitores, qtdEleitores);

    for (v = 0; v < qtdEleitores; v++) {
        eleicao->eleitores[v] = Criaeleitor();
        LeEleitor((*eleicao).eleitores[v]);
    }

    for (e1 = 0; e1 < (qtdEleitores - 1); e1++) {
        for(e2 = e1 + 1; e2 < qtdEleitores; e2++) {
            if (EhMesmoeleitor((*eleicao).eleitores[e1], (*eleicao).eleitores[e2])) {
                ApagaEleicao(eleicao);
                printf("ELEICAO ANULADA\n");
                exit(1);
            }
        }
    }

    for (v = 0; v < qtdEleitores; v++) {
        if (ObtemVotoGovernador((*eleicao).eleitores[v] == 0)) {
            eleicao->votosBrancosGovernador += 1;
        }else {
            governadorValido = 0;
            for (g = 0; g < (*eleicao).totalGovernadores; g++) {
                if (VerificandoIdCandidato((*eleicao).governadores[g], ObtemVotoGovernador((*eleicao).eleitores[v]))) {
                    governadorValido = 1;
                    break;
                }
            }
            if (!(governadorValido)) {
                eleicao->votosNulosGovernador += 1;
            }
        }
        if (ObtemVotoPresidente((*eleicao).eleitores[v] == 0)) {
            eleicao->votosBrancosPresidente += 1;
        }else {
            presidenteValido = 0;
            for (p = 0; p < (*eleicao).totalPresidentes; p++) {
                if (VerificandoIdCandidato((*eleicao).presidentes[p], ObtemVotoGovernador((*eleicao).eleitores[v]))) {
                    presidenteValido = 1;
                    break;
                }
            }
            if (!(presidenteValido)) {
                eleicao->votosNulosPresidente += 1;
            }
        }
    }
}

void ApagaEleicao(tEleicao *eleicao) {
    int g, p, e;
    
    for (g = 0; g < (*eleicao).totalGovernadores; g++) {
        ApagaCandidato((*eleicao).governadores[g]);
    }
    for (p = 0; p < (*eleicao).totalPresidentes; p++) {
        ApagaCandidato((*eleicao).presidentes[p]);
    }
    for (e = 0; e < (*eleicao).totalEleitores; e++) {
        ApagaEleitor((*eleicao).eleitores[e]);
    }

    free((*eleicao).governadores);
    free((*eleicao).presidentes);
    free((*eleicao).eleitores);
    free(eleicao);
}