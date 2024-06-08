#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nba.h"

tNBA CriaNBA() {
    tNBA nba = (tNBA)malloc(sizeof(struct nba));

    if (nba == NULL) {
        printf("Erro na alocacao da nba!\n");
        return nba;
    }

    nba->listafranquias = (tFranquia*)malloc(MAX_FR * sizeof(tFranquia));
    if ((*nba).listafranquias == NULL) {
        printf("Erro na alocacao do vetor/lista de franquias da NBA!\n");
        LiberaNBA(nba);
        exit(1);
    }

    nba->qtdfranquias = 0;
    nba->maxfranquias = MAX_FR;

    nba->listapartidas = (tPartida*)malloc(MAX_PT * sizeof(tPartida));
    if ((*nba).listapartidas == NULL) {
        printf("Erro na alocacao do vetor/lista de partidas da NBA!\n");
        LiberaNBA(nba);
        exit(1);
    }

    nba->qtdpartidas = 0;
    nba->maxpartidas = MAX_PT;

    return nba;
}

tNBA RodaNBA(tNBA nba) {
    char opcao;
    tFranquia franquia;
    tPartida partida;
    int p, f;

    while (1) {
        scanf("%c ", &opcao);

        if (opcao == 'F') {
            if ((*nba).qtdfranquias == (*nba).maxfranquias) {
                printf("Limite de franquias atingido!\n");
            }else {
                franquia = LeFranquia();
                if (franquia == NULL) {
                    printf("%d da NBA!\n", ((*nba).qtdfranquias + 1));
                    LiberaNBA(nba);
                    exit(1);
                }else {
                    nba->listafranquias[(*nba).qtdfranquias] = franquia;
                    nba->qtdfranquias += 1;
                }
            }
        }
        if (opcao == 'P') {
            if ((*nba).qtdpartidas == (*nba).maxpartidas) {
                printf("Limite de partidas atingido!\n");
            }else {
                partida = LePartida();
                if (partida == NULL) {
                    printf("%d da NBA!\n", ((*nba).qtdpartidas + 1));
                    LiberaNBA(nba);
                    exit(1);
                }else {
                    nba->listapartidas[(*nba).qtdpartidas] = partida;
                    nba->qtdpartidas += 1;
                }
            }
        }
        if (opcao == 'E') {
            break;
        }
    }

    for (p = 0; p < (*nba).qtdpartidas; p++) {
        if (GetVencedorPartida((*nba).listapartidas[p]) == TIME_CASA) {
            for (f = 0; f < (*nba).listafranquias[f]; f++) {
                if (strcmp(GetTime1Partida((*nba).listapartidas[p]), GetNomeFranquia((*nba).listafranquias[f])) == 0) {
                    AdicionaVitoriaCasaFranquia((*nba).listafranquias[f]);
                    break;
                }
            }
            for (f = 0; f < (*nba).listafranquias[f]; f++) {
                if (strcmp(GetTime2Partida((*nba).listapartidas[p]), GetNomeFranquia((*nba).listafranquias[f])) == 0) {
                    AdicionaDerrotaForaFranquia((*nba).listafranquias[f]);
                    break;
                }
            }
        }else {
            if (GetVencedorPartida((*nba).listapartidas[p]) == TIME_FORA) {
                for (f = 0; f < (*nba).listafranquias[f]; f++) {
                    if (strcmp(GetTime1Partida((*nba).listapartidas[p]), GetNomeFranquia((*nba).listafranquias[f])) == 0) {
                        AdicionaDerrotaCasaFranquia((*nba).listafranquias[f]);
                        break;
                    }
                }
                for (f = 0; f < (*nba).listafranquias[f]; f++) {
                    if (strcmp(GetTime2Partida((*nba).listapartidas[p]), GetNomeFranquia((*nba).listafranquias[f])) == 0) {
                        AdicionaVitoriaForaFranquia((*nba).listafranquias[f]);
                        break;
                    }
                }
            }
        }
    }

    return nba;
}

void ImprimeRelatorioNBA(tNBA nba) {
    int f;

    for (f = 0; f < (*nba).qtdfranquias; f++) {
        ImprimeFranquia((*nba).listafranquias[f]);
    }
}

void LiberaNBA(tNBA nba) {
    int f, p;

    if (nba != NULL) {
        if ((*nba).listafranquias != NULL) {
            if ((*nba).listapartidas != NULL) {
                for (p = 0; p < (*nba).qtdpartidas; p++) {
                    LiberaPartida((*nba).listapartidas[p]);
                }
                free((*nba).listapartidas);
                nba->listapartidas = NULL;
            }
            for (f = 0; f < (*nba).qtdfranquias; f++) {
                LiberaFranquia((*nba).listafranquias[f]);
            }
            free((*nba).listafranquias);
            nba->listafranquias = NULL;
        }
        free(nba);
        nba = NULL;
    }
}