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

        if (candidato[c].cargo == 'G') {
            eleicao.governadores[g] = candidato[c];
            g++;
        }else {
            if (candidato[c].cargo == 'P') {
                eleicao.presidentes[p] = candidato[c];
                p++;
            }
        }
    }
    eleicao.totalGovernadores = g;
    eleicao.totalPresidentes = p;

    if ((eleicao.totalGovernadores > MAX_CANDIDATOS_POR_CARGO) || (eleicao.totalPresidentes > MAX_CANDIDATOS_POR_CARGO)) {
        printf("ELEICAO ANULADA\n");
        exit(1);
    }
    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao) {
    int governadorValido = 0, presidenteValido = 0;
    int e1, e2, g, p, qtdEleitores, v;

    scanf("%d", &qtdEleitores);

    if (qtdEleitores > MAX_ELEITORES) {
        printf("ELEICAO ANULADA\n");
        exit(1);
    }

    for (v = 0; v < qtdEleitores; v++) {
        eleicao.eleitores[v] = LeEleitor();
    }
    for (e1 = 0; e1 < (qtdEleitores - 1); e1++) {
        for (e2 = e1 + 1; e2 < qtdEleitores; e2++) {
            if (EhMesmoEleitor(eleicao.eleitores[e1], eleicao.eleitores[e2])) {
                printf("ELEICAO ANULADA\n");
                exit(1);
            }
        }
    }

    for (v = 0; v < qtdEleitores; v++) {
        if (ObtemVotoGovernador(eleicao.eleitores[v]) == 0) {
            eleicao.votosBrancosGovernador += 1;
        }else {
            governadorValido = 0;
            for (g = 0; g < eleicao.totalGovernadores; g++) {
                if (VerificaIdCandidato(eleicao.governadores[g], ObtemVotoGovernador(eleicao.eleitores[v]))) {
                    eleicao.governadores[g] = IncrementaVotoCandidato(eleicao.governadores[g]);
                    governadorValido = 1;
                    break;
                }
            }
            if (!(governadorValido)) {
                eleicao.votosNulosGovernador += 1;
            }
        }
        if (ObtemVotoPresidente(eleicao.eleitores[v]) == 0) {
            eleicao.votosBrancosPresidente += 1;
        }else {
            presidenteValido = 0;
            for (p = 0; p < eleicao.totalPresidentes; p++) {
                if (VerificaIdCandidato(eleicao.presidentes[p], ObtemVotoPresidente(eleicao.eleitores[v]))) {
                    eleicao.presidentes[p] = IncrementaVotoCandidato(eleicao.presidentes[p]);
                    presidenteValido = 1;
                    break;
                }
            }
            
            if (!(presidenteValido)) {
                eleicao.votosNulosPresidente += 1;
            }
        }
    }
    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao) {
    int v, totalVotosGov, totalVotosPres;
    int votosValidosGov = 0, votosValidosPres = 0;
    int empateGovernadores = 0, empatePresidentes = 0;
    tCandidato liderGovernador, liderPresidente;

    for (v = 0; v < eleicao.totalPresidentes; v++) {
        votosValidosPres += ObtemVotos(eleicao.presidentes[v]);
    }
    totalVotosPres = eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente + votosValidosPres;
    for (v = 0; v < eleicao.totalPresidentes; v++) {
        if (v == 0) {
            liderPresidente = eleicao.presidentes[v];
        }else{
            if ((ObtemVotos(eleicao.presidentes[v])) > liderPresidente.votos) {
                liderPresidente = eleicao.presidentes[v];
                empatePresidentes = 0;
            }else {
                if ((ObtemVotos(eleicao.presidentes[v])) == liderPresidente.votos) {
                    empatePresidentes = 1;
                }
            }
        }
    }

    printf("- PRESIDENTE ELEITO: ");
    if (ObtemVotos(liderPresidente) < (eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente)) {
        printf("SEM DECISAO\n");
    }else {
        if (empatePresidentes) {
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }else {
            ImprimeCandidato(liderPresidente, CalculaPercentualVotos(liderPresidente, totalVotosPres));
        }
    }

    for (v = 0; v < eleicao.totalGovernadores; v++) {
        votosValidosGov += ObtemVotos(eleicao.governadores[v]);
    }
    totalVotosGov = eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador + votosValidosGov;
    for (v = 0; v < eleicao.totalGovernadores; v++) {
        if (v == 0) {
            liderGovernador = eleicao.governadores[v];
        }else{
            if ((ObtemVotos(eleicao.governadores[v])) > liderGovernador.votos) {
                liderGovernador = eleicao.governadores[v];
                empateGovernadores = 0;
            }else {
                if ((ObtemVotos(eleicao.governadores[v])) == liderGovernador.votos) {
                    empateGovernadores = 1;
                }
            }
        }
    }

    printf("- GOVERNADOR ELEITO: ");
    if (ObtemVotos(liderGovernador) < (eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador)) {
        printf("SEM DECISAO\n");
    }else {
        if (empateGovernadores) {
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }else {
            ImprimeCandidato(liderGovernador, CalculaPercentualVotos(liderGovernador, totalVotosGov));
        }
    }
    printf("- NULOS E BRANCOS: %d, %d", (eleicao.votosNulosGovernador + eleicao.votosNulosPresidente), (eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente));
}