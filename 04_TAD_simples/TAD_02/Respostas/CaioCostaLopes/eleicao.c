#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"

tEleicao InicializaEleicao() {
    tEleicao eleicao;
    int qtdCandidatos, c, v;
    int g = 0, p = 0;

    eleicao.votosBrancosGovernador = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosGovernador = 0;
    eleicao.votosNulosPresidente = 0;

    scanf("%d", &qtdCandidatos);
    tCandidato candidato[qtdCandidatos];

    for (c = 0; c < qtdCandidatos; c++) {
        candidato[c] = LeCandidato();

        if (candidato[c].cargo = 'G') {
            eleicao.governadores[g] = candidato[c];
            g++;
        }else {
            if (candidato[c].cargo = 'P') {
                if (g > 0){
                    for (v = 0; v < g; v++) {
                        if (EhMesmoCandidato(candidato[c], eleicao.governadores[v])) {
                            printf("ELEICAO ANULADA\n");
                            exit(1);
                        }
                    }
                }
                eleicao.governadores[p] = candidato[c];
                p++;
            }
        }
    }
    eleicao.totalGovernadores = g + 1;
    eleicao.totalPresidentes = p + 1;

    if ((eleicao.totalGovernadores > 3) || (eleicao.totalPresidentes > 3)) {
        printf("ELEICAO ANULADA\n");
        exit(1);
    }

    return eleicao;
}

tEleicao Realizaeleicao(tEleicao eleicao) {
    int governadorValido, presidenteValido;
    int v = 0;
    int e1, e2, g, p;
    tEleitor eleitor[MAX_ELEITORES];

    while(1) {
        eleitor[v] = LeEleitor();

        if (v > 0) {
            for (e1 = 0; e1 < (v - 1); e1++) {
                for (e2 = e1 + 1; e2 < v; e2++) {
                    if (EhMesmoEleitor(eleitor[e1], eleitor[e2])) {
                        printf("ELEICAO ANULADA\n");
                        exit(1);
                    }
                }
            }
        }

        if (ObtemVotoGoverador(eleitor[v]) == 0) {
            eleicao.votosBrancosGovernador += 1;
        }else {
            governadorValido = 0;
            for (g = 0; g < eleicao.totalGovernadores; g++) {
                if (VerificaIdCandidato(eleicao.governadores[g], ObtemVotoGoverador(eleitor[v]))) {
                    eleicao.governadores[g] = IncrementaVotoCandidato(eleicao.governadores[g]);
                    governadorValido = 1;
                    break;
                }
            }
            if (!(governadorValido)) {
                eleicao.votosNulosGovernador += 1;
            }
        }
        if (ObtemVotoPresidente(eleitor[v]) == 0) {
            eleicao.votosBrancosPresidente += 1;
        }else {
            presidenteValido = 0;
            for (p = 0; p < eleicao.totalPresidentes; p++) {
                if (VerificaIdCandidato(eleicao.presidentes[p], ObtemVotoPresidente(eleitor[v]))) {
                    eleicao.presidentes[p] = IncrementaVotoCandidato(eleicao.presidentes[p]);
                    presidenteValido = 1;
                    break;
                }
            }
            if (!(presidenteValido)) {
                eleicao.votosNulosPresidente += 1;
            }
        }

        v++;

        if (v > 10) {
            printf("ELEICAO ANULADA\n");
            exit (1);
        }
    }
}

void ImprimeResultadosEleicao(tEleicao eleicao) {
    int v, totalVotosGov, totalVotosPres;
    int votosValidosGov = 0, votosValidosPres = 0;
    int empateGovernadores = 0, empatePresitentes = 0;
    tCandidato liderGovernador, liderPresidente;

    printf("- PRESIDENTE ELEITO: ");
    for (v = 0; v < eleicao.totalPresidentes; v++) {
        votosValidosPres += ObtemVotos(eleicao.presidentes[v]);
    }
    totalVotosPres = eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente + votosValidosPres;
    for (v = 0; v < eleicao.totalPresidentes; v++) {
        if (v == 0) {
            liderPresidente = eleicao.presidentes[v];
        }
        if ((ObtemVotos(eleicao.presidentes[v])) > liderPresidente.votos) {
            liderPresidente = eleicao.presidentes[v];
            empatePresitentes = 0;
        }else {
            if ((ObtemVotos(eleicao.presidentes[v])) == liderPresidente.votos) {
                empatePresitentes = 1;
            }
        }
    }

    if (ObtemVotos(liderPresidente) < (eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente)) {
        printf("SEM DECISAO");
    }else {
        if (empatePresitentes) {
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO");
        }else {
            ImprimeCandidato(liderPresidente, CalculaPercentualVotos(liderPresidente, totalVotosPres));
        }
    }
    printf("\n");

    printf("- GOVERNADOR ELEITO: ");
    for (v = 0; v < eleicao.totalGovernadores; v++) {
        votosValidosGov += ObtemVotos(eleicao.governadores[v]);
    }
    totalVotosGov = eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador + votosValidosGov;
    for (v = 0; v < eleicao.totalGovernadores; v++) {
        if (v == 0) {
            liderGovernador = eleicao.governadores[v];
        }
        if ((ObtemVotos(eleicao.governadores[v])) > liderGovernador.votos) {
            liderGovernador = eleicao.governadores[v];
            empateGovernadores = 0;
        }else {
            if ((ObtemVotos(eleicao.governadores[v])) == liderGovernador.votos) {
                empateGovernadores = 1;
            }
        }
    }

    if (ObtemVotos(liderGovernador) < (eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador)) {
        printf("SEM DECISAO");
    }else {
        if (empateGovernadores) {
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO");
        }else {
            ImprimeCandidato(liderGovernador, CalculaPercentualVotos(liderGovernador, totalVotosGov));
        }
    }
    printf("\n");

    printf("- NULOS E BRANCOS: %d %d", (eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador), (eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente));
}