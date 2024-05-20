#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "jogada.h"

struct Jogador {
    int id;
};

tJogador *CriaJogador(int idJogador) {
    tJogador *jogador = (tJogador*)malloc(sizeof(tJogador));

    if (jogador == NULL) {
        printf("Erro na alocacao do jogador");
        return jogador;
    }

    jogador->id = idJogador;

    return jogador;
}

void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro) {
    tJogada *jogada;

    jogada = CriaJogada();
    
    if (jogada == NULL) {
        DestroiJogador(jogador);
    }else {
        while (1) {
            printf("Jogador %d\n", (*jogador).id);

            LeJogada(jogada);

            if (!(FoiJogadaBemSucedida(jogada))) {
                scanf("%*[^\n]\n");
            }else {
                if (EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
                    if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada), (*jogador).id))) {
                        if (EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJgadaY(jogada))) {
                            MarcaPosicaoTabuleiro(tabuleiro, (*jogador).id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                            break;
                        }else {
                            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                        }
                        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                    }
                    printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                }
            }
        }
        DestroiJogada(jogada);
    }
}

int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro) {
    int v;

    for (v = 0; v < TAM_TABULEIRO; v++) {
        if ((EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, v, 0, (*jogador).id)) &&
            (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, v, 1, (*jogador).id)) &&
            (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, v, 2, (*jogador).id))) {
                return 1;
        }
        if ((EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, v, (*jogador).id)) &&
            (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, v, (*jogador).id)) &&
            (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, v, (*jogador).id))) {
                return 1;
        }
        if ((EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, v, v, (*jogador).id)) &&
            (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, v, v, (*jogador).id)) &&
            (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, v, v, (*jogador).id))) {
                return 1;
        }
    }

    if ((EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, (*jogador).id)) &&
        (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, (*jogador).id)) &&
        (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, (*jogador).id))) {
            return 1;
    }

    return 0;
}

void DestroiJogador(tJogador *jogador) {
    if (jogador != NULL) {
        free(jogador);
        jogador = NULL;
    }
}