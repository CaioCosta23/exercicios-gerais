#include <stdio.h>
#include <stdlib.h>
#include "dracomania.h"

tDracomania CriaDracomania() {
    tDracomania dracomania = (tDracomania)malloc(sizeof(struct dracomania));

    if (dracomania == NULL) {
        printf("Erro na alocacao de memoria do jogo dracomania!\n");
        exit(1);
    }

    dracomania->qtdcartas = 0;
    dracomania->maxcartas = TAM_LISTA;
    dracomania->qtdduelos = 0;
    dracomania->maxduelos = TAM_LISTA;
    dracomania->descartes = 0;

    dracomania->listacartas = (tCarta*)malloc(TAM_LISTA * sizeof(tCarta));
    if ((*dracomania).listacartas == NULL) {
        printf("Erro na alocacao de memoria do vetor/lista de cartas do jogo de Dracomania!\n");
        LiberaDracomania(dracomania);
        exit(1);
    }

    dracomania->listaduelos = (tDuelo*)malloc(TAM_LISTA * sizeof(tDuelo));
    if ((*dracomania).listaduelos == NULL) {
        printf("Erro na alocacao de memoria no vetor/lista de duelos do jogo de Dracomania!\n");
        LiberaDracomania(dracomania);
        exit(1);
    }
    return dracomania;
}

tDracomania RodaDracomania(tDracomania d) {
    char acao;
    int c, posicaoCarta1, posicaoCarta2;
    bool jaExiste, carta1Encontrada, carta2Encontrada;
    tCarta carta;
    tDuelo duelo;

    while (1) {
        scanf("%c", &acao);

        if (acao == FINALIZAR) {
            break;
        }else {
            if (acao == CADASTRAR) {
                carta = LeCarta();
                if (carta == NULL) {
                    printf("%d!", ((*d).qtdcartas + 1));
                    LiberaDracomania(d);
                    exit(1);
                }
                if (EhCartaValida(carta) == true) {
                    if ((*d).qtdcartas == (*d).maxcartas) {
                        d->maxcartas += TAM_LISTA;
                        d->listacartas = (tCarta*)realloc((*d).listacartas, (*d).maxcartas * sizeof(tCarta));
                        if ((*d).listacartas == NULL) {
                            printf("Erro na realocacao de memoria do vetor/lista de cartas!\n");
                            LiberaDracomania(d);
                            exit(1);
                        }
                    }
                    jaExiste = false;
                    for (c = 0; c < (*d).qtdcartas; c++) {
                        if (EhMesmoIdCarta(carta, (*d).listacartas[c]) == true) {
                            jaExiste = true;
                            break;
                        }
                    }
                    if (jaExiste == false) {
                        d->listacartas[(*d).qtdcartas] = carta;
                        d->qtdcartas += 1;
                    }else {
                        LiberaCarta((*d).listacartas[c]);
                        d->listacartas[c] = NULL;
                        d->listacartas[c] = carta;
                    }

                }else {
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
                        if ((*d).maxduelos == (*d).qtdduelos) {
                            d->maxduelos += TAM_LISTA;
                            d->listaduelos = (tDuelo*)realloc((*d).listaduelos, (*d).maxduelos * sizeof(tDuelo));
                            if ((*d).listaduelos == NULL) {
                                printf("Erro na realocacao de memoria do vetor/lista de duelos!\n");
                                LiberaDracomania(d);
                                exit(1);
                            }
                        }
                        carta1Encontrada = false;
                        carta2Encontrada = false;
                        for (c = 0; c < (*d).qtdcartas; c++) {
                            if ((carta1Encontrada == true) && (carta2Encontrada == true)) {
                                break;
                            }

                            if ((GetC1Duelo(duelo) == GetIdCarta((*d).listacartas[c])) && carta1Encontrada == false) {
                                carta1Encontrada = true;
                                posicaoCarta1 = c;
                                continue;
                            }
                            if ((GetC2Duelo(duelo) == GetIdCarta((*d).listacartas[c])) && carta2Encontrada == false) {
                                carta2Encontrada = true;
                                posicaoCarta2 = c;
                                continue;
                            }
                        }
                        if ((carta1Encontrada == true) && (carta2Encontrada == true)) {
                            RealizaDuelo(duelo, (*d).listacartas[posicaoCarta1], (*d).listacartas[posicaoCarta2]);
                            d->listaduelos[(*d).qtdduelos] = duelo;
                            d->qtdduelos += 1;
                        }else {
                            LiberaDuelo(duelo);
                        }
                    }else {
                        LiberaDuelo(duelo);
                    }
                }
            }
        }
    }
    return d;
}

void ImprimeRelatorioDracomania(tDracomania d) {
    int l, c, maisVitorias, cartaVitoriosa, lutaMaiorDiferenca;
    int qtdDesempates = 0, maiorDiferenca = 0;

    printf("Quantidade de Cartas: %d\n", (*d).qtdcartas);
    printf("Quantidade de descartadas: %d\n", (*d).descartes);
    printf("Quantidade de lutas: %d\n", (*d).qtdduelos);

    if (((*d).qtdduelos > 0)) {
        for (l = 0; l < (*d).qtdduelos; l++) {
            if (GetDesempateDuelo((*d).listaduelos[l]) == true) {
                qtdDesempates += 1;
            }
            if ((l == 0) || (GetDiferencaDuelo((*d).listaduelos[l]) > maiorDiferenca)) {
                maiorDiferenca = GetDiferencaDuelo((*d).listaduelos[l]);
                lutaMaiorDiferenca = GetIdDuelo((*d).listaduelos[l]);
            }
            
        }
        printf("Lutas que foram desempatadas: %d\n", qtdDesempates);
        for (c = 0; c < (*d).qtdcartas; c++) {
            if ((c == 0) || (GetNumVitCarta((*d).listacartas[c]) > maisVitorias)) {
                maisVitorias = GetNumVitCarta((*d).listacartas[c]);
                cartaVitoriosa = c;
                
            }
        }
        printf("Carta mais vitoriosa: %s\n", GetNomeCarta((*d).listacartas[cartaVitoriosa]));
        printf("Luta com Maior Diferenca: %d\n", lutaMaiorDiferenca);
    }
}

void LiberaDracomania(tDracomania d) {
    int c, l;

    if (d != NULL) {
        if ((*d).listacartas != NULL) {
            if ((*d).listaduelos != NULL) {
                for (l = 0; l < (*d).qtdduelos; l++) {
                    LiberaDuelo((*d).listaduelos[l]);
                }
                free((*d).listaduelos);
                d->listaduelos = NULL;
            }
            for (c = 0; c < (*d).qtdcartas; c++) {
                LiberaCarta((*d).listacartas[c]);
            }
            free((*d).listacartas);
            d->listacartas = NULL;
        }
        free(d);
        d = NULL;
    }
}