#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dracomania.h"

tDracomania CriaDracomania() {
    tDracomania dracomania = (tDracomania)malloc(sizeof(struct dracomania));

    if (dracomania == NULL) {
        printf("Erro na alocacao de memoria do jogo dracomania!\n");
        exit(1);
    }

    dracomania->listacartas = (tCarta)malloc(TAM_LISTA * sizeof(struct carta));
    if ((*dracomania).listacartas == NULL) {
        printf("Erro na alocacao de memoria do vetor/lista de cartas do jogo de Dracomania!\n");
        LiberaDracomania(dracomania);
        exit(1);
    }

    dracomania->qtdcartas = 0;
    dracomania->maxcartas = TAM_LISTA;

    dracomania->listaduelos = (tDuelo)malloc(TAM_LISTA * sizeof(struct duelo));
    if ((*dracomania).listaduelos == NULL) {
        printf("Erro na alocacao de memoria no vetor/lista de duelos do jogo de Dracomania!\n");
        LiberaDracomania(dracomania);
        exit(1);
    }

    dracomania->qtdduelos = 0;
    dracomania->maxduelos = 0;
    dracomania->descartes = 0;

    return dracomania;
}

tDracomania RodaDracomania(tDracomania d) {
    char acao;
    int c, posicaoCarta1, posicaoCarta2;
    bool jaExiste, carta1Encontrada, carta2Encontrada;
    tCarta carta;
    tDuelo duelo;

    while (1) {
        scanf("%c\n", &acao);
        
        if (acao == CADASTRAR) {
            carta = LeCarta();

            if (carta == NULL) {
                printf("%d!\n", ((*d).qtdcartas + 1));
                LiberaDracomania(d);
                exit(1);
            }
            if (EhCartaValida == true) {
                if ((*d).maxcartas == (*d).qtdcartas) {
                    d->maxcartas += TAM_LISTA;
                    d->listacartas = (tCarta*)realloc((*d).listacartas, (*d).maxcartas * sizeof(tCarta));
                    if (d->listacartas == NULL) {
                        printf("Erro na realocacao no vetor/lista de cartas na carta %d!\n", (*d).qtdcartas);
                        LiberaDracomania(d);
                        exit(1);
                    }
                }
                if ((*d).qtdcartas > 0) {
                    jaExiste = false;
                    for (c = 0; c < (*d).qtdcartas; c++) {
                        if (EhMesmoIdCarta(carta, (*d).listacartas[c])) {
                            d->listacartas[c] = carta;
                            jaExiste = true;
                            break;
                        }
                    }
                    if (jaExiste == true) {
                        continue;
                    }
                }
                d->listacartas[(*d).qtdcartas] = carta;
                d->qtdcartas += 1;
            }else {
                d->descartes += 1;
                LiberaCarta(carta);
            }
        }else {
            if (acao == LUTAR) {
                duelo = LeDuelo();
                if (duelo == NULL) {
                    printf("%d!\n", ((*d).qtdduelos + 1));
                    LiberaDracomania(d);
                    exit(1);
                }
                if ((*d).qtdcartas > 1) {
                    carta1Encontrada = false;
                    carta2Encontrada = false;
                    for (c = 0; c < (*d).qtdcartas; c++) {
                        if ((carta1Encontrada == true) && (carta2Encontrada == true)) {
                            RealizaDuelo(duelo, (*d).listacartas[posicaoCarta1], (*d).listacartas[posicaoCarta2]);
                            break;
                        }
                        if ((carta1Encontrada == false) && (GetC1Duelo(duelo) == GetIdCarta((*d).listacartas[c]))) {
                            carta1Encontrada = true;
                            posicaoCarta1 = c;
                            continue;
                        }
                        if ((carta2Encontrada == false) && (GetC2Duelo(duelo) == GetIdCarta((*d).listacartas[c]))) {
                            carta2Encontrada = true;
                            posicaoCarta2 = c;
                            continue;
                        }
                    }
                    if ((carta1Encontrada == true) && (carta2Encontrada == true)) {
                        d->maxduelos += TAM_LISTA;
                        d->listaduelos = (tDuelo*)realloc((*d).listaduelos, (*d).maxduelos * sizeof(tDuelo));
                        if ((*d).listaduelos == NULL) {
                            printf("Erro na realocacao da lista de duelos no duelo %d!\n", ((*d).qtdduelos + 1));
                            LiberaDracomania(d);
                            exit(1);
                        }
                        d->listaduelos[(*d).qtdduelos] = duelo;
                        d->qtdduelos += 1;
                    }else {
                        LiberaDuelo(duelo);
                    }
                }else {
                    LiberaDuelo(duelo);
                }
            }else {
                if (acao == FINALIZAR) {
                    break;
                }
            }
        }
    }
    return d;
}

void ImprimeRelatorioDracomania(tDracomania d) {
    int l, c, maisVitorias, maiorDiferenca;
    int qtdDesempates = 0;
    char cartaVitoriosa[MAX_NOME];

    printf("Quantidade de Cartas: %d\n", (*d).qtdcartas);
    printf("Quantidade de descartadas: %d\n", (*d).descartes);
    printf("Quantidade de lutas: %d\n", (*d).qtdduelos);

    if ((*d).qtdduelos > 0) {
        for (l = 0; l < (*d).qtdduelos; l++) {
            if (GetDesempateDuelo((*d).listaduelos[l]) == true) {
                qtdDesempates += 1;
            }
            if ((l == 0) || (GetDiferencaDuelo((*d).listaduelos[l] < maiorDiferenca))) {
                maiorDiferenca = GetDiferencaDuelo((*d).listaduelos[l]);
            }
            
        }
        printf("Lutas que foram desempatadas: %d\n", qtdDesempates);
        for (c = 0; c < (*d).qtdcartas; c++) {
            if ((c == 0) || (GetNumVitCarta((*d).listacartas[c]) < maisVitorias)) {
                maisVitorias = GetNumVitCarta((*d).listacartas[c]);
                strcpy(cartaVitoriosa, GetNomeCarta((*d).listacartas[c]));
            }
        }
        printf("Carta mais vitoriosa: %s\n", cartaVitoriosa);
        printf("Luta com Maior Diferenca: %d\n", maiorDiferenca);
    }
}

void LiberaDracomania(tDracomania d) {
    int c, l;

    if (d != NULL) {
        if ((*d).listacartas != NULL) {
            for (c = 0; c < (*d).qtdcartas; c++) {
                LiberaCarta((*d).listacartas[c]);
            }
            free((*d).listacartas);
            d->listacartas = NULL;
        }
        if ((*d).listaduelos != NULL) {
            for (l = 0; l < (*d).listaduelos; l++) {
                LiberaDuelo((*d).listaduelos[l]);
            }
            free((*d).listaduelos);
            d->listaduelos = NULL;
        }
        d = NULL;
    }
}