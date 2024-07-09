#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nba.h"
#include "franquia.h"
#include "partida.h"

struct nba {
    tFranquia *listaFranquias;
    int qtdFranquias;
    int maxFranquias;
    tPartida *listaPartidas;
    int qtdPartidas;
    int maxPartidas;
};

tNBA CriaNBA() {
    tNBA nba = (tNBA)malloc(sizeof(struct nba));

    if (nba == NULL) {
        printf("Erro na alocação de memória da NBA!\n");
        exit(1);
    }

    nba->listaFranquias = (tFranquia*)malloc(MAX_FR * sizeof(tFranquia));
    if ((*nba).listaFranquias == NULL) {
        printf("Erro na alocação do vetor/lista de franquias da NBA!\n");
        LiberaNBA(nba);
        exit(1);
    }

    nba->qtdFranquias = 0;
    nba->maxFranquias = 0;

    nba->listaPartidas = (tPartida*)malloc(MAX_PT * sizeof(tPartida));
    if ((*nba).listaPartidas == NULL) {
        printf("Erro na alocacao de memoria do vetor/lista de partidas da NBA!\n");
        LiberaNBA(nba);
        exit(1);
    }

    nba->qtdPartidas = 0;
    nba->maxPartidas = 0;

    return nba;
}

tNBA RodaNBA(tNBA nba) {
    char opcao;
    tFranquia franquia;
    tPartida partida;
    int f, p;

    while (1) {
        scanf("%c ", &opcao);

        if (opcao == CAD_FRANQUIA) {
            franquia = LeFranquia();

            if (!((*nba).maxFranquias)) {
                if (franquia == NULL) {
                    printf("%d da NBA!\n", ((*nba).qtdFranquias + 1));
                    LiberaNBA(nba);
                    exit(1);
                }else {
                    nba->listaFranquias[(*nba).qtdFranquias] = franquia;
                    nba->qtdFranquias += 1;

                    if ((*nba).qtdFranquias == MAX_FR) {
                        nba->maxFranquias = 1;
                    }
                }
            }else {
                LiberaFranquia(franquia);
            }
        }
        if (opcao == CAD_PARTIDA) {
            partida = LePartida();
            if (!((*nba).maxPartidas)) {

                if (partida == NULL) {
                    printf("%d partida da NBA!", ((*nba).qtdPartidas + 1));
                    LiberaNBA(nba);
                    exit(1);
                }else {
                    nba->listaPartidas[(*nba).qtdPartidas] = partida;
                    nba->qtdPartidas += 1;

                    if ((*nba).qtdPartidas == MAX_PT) {
                        nba->maxPartidas = 1;
                    }
                }
            }else {
                LiberaPartida(partida);
            }
        }
        if (opcao == ENCERRAR) {
            break;
        }
    }

    for (p = 0; p < (*nba).qtdPartidas; p++) {
        if (GetVencedorPartida((*nba).listaPartidas[p]) == TIME_CASA) {
            for (f = 0; f < (*nba).qtdFranquias; f++) {
                if (strcmp(GetTime1Partida((*nba).listaPartidas[p]), GetNomeFranquia((*nba).listaFranquias[f])) == 0) {
                    AdicionaVitoriaCasaFranquia((*nba).listaFranquias[f]);
                    break;
                }
            }
            for (f = 0; f < (*nba).qtdFranquias; f++) {
                if (strcmp(GetTime2Partida((*nba).listaPartidas[p]), GetNomeFranquia((*nba).listaFranquias[f])) == 0) {
                    AdicionaDerrotaForaFranquia((*nba).listaFranquias[f]);
                    break;
                }
            }
        }else {
            if (GetVencedorPartida((*nba).listaPartidas[p]) == TIME_FORA) {
                for (f = 0; f < (*nba).qtdFranquias; f++) {
                    if (strcmp(GetTime1Partida((*nba).listaPartidas[p]), GetNomeFranquia((*nba).listaFranquias[f])) == 0) {
                        AdicionaDerrotaCasaFranquia((*nba).listaFranquias[f]);
                        break;
                    }
                }
                for (f = 0; f < (*nba).qtdFranquias; f++) {
                    if (strcmp(GetTime2Partida((*nba).listaPartidas[p]), GetNomeFranquia((*nba).listaFranquias[f])) == 0) {
                        AdicionaVitoriaForaFranquia((*nba).listaFranquias[f]);
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
    int vitoriasOeste = 0, derrotasOeste = 0, vitoriasLeste = 0, derrotasLeste = 0;
    double porcentagemLeste = 0, porcentagemOeste = 0;

    for (f = 0; f < (*nba).qtdFranquias; f++) {
        ImprimeFranquia((*nba).listaFranquias[f]);
        
        if (strcmp(GetConferenciaFranquia((*nba).listaFranquias[f]), "OESTE") == 0) {
            vitoriasOeste += (GetVitoriaCasaFranquia((*nba).listaFranquias[f]) + GetVitoriaForaFranquia((*nba).listaFranquias[f]));
            derrotasOeste += (GetDerrotaCasaFranquia((*nba).listaFranquias[f]) + GetDerrotaForaFranquia((*nba).listaFranquias[f]));
        }else {
            if (strcmp(GetConferenciaFranquia((*nba).listaFranquias[f]), "LESTE") == 0) {
                vitoriasLeste += (GetVitoriaCasaFranquia((*nba).listaFranquias[f]) + GetVitoriaForaFranquia((*nba).listaFranquias[f]));
                derrotasLeste += (GetDerrotaCasaFranquia((*nba).listaFranquias[f]) + GetDerrotaForaFranquia((*nba).listaFranquias[f]));
            }
        }
    }
    if (vitoriasLeste > 0) {
        porcentagemLeste = (double)(vitoriasLeste * 100) / (double)(vitoriasLeste + derrotasLeste);
    }
    if (vitoriasOeste > 0) {
        porcentagemOeste = (double)(vitoriasOeste * 100) / (double)(vitoriasOeste + derrotasOeste);
    }

    printf("LESTE %d %d %.2f\n", vitoriasLeste, derrotasLeste, porcentagemLeste);
    printf("OESTE %d %d %.2f\n", vitoriasOeste, derrotasOeste, porcentagemOeste);
}

void LiberaNBA(tNBA nba) {
    int f, p;

    if (nba != NULL) {
        if ((*nba).listaFranquias != NULL) {
            for (f = 0; f < (*nba).qtdFranquias; f++) {
                LiberaFranquia((*nba).listaFranquias[f]);
            }
            free((*nba).listaFranquias);
            nba->listaFranquias = NULL;
        }
        if ((*nba).listaPartidas != NULL) {
            for (p = 0; p < (*nba).qtdPartidas; p++) {
                LiberaPartida((*nba).listaPartidas[p]);
            }
            free((*nba).listaPartidas);
            nba->listaPartidas = NULL;
        }
        free(nba);
        nba = NULL;
    }
}