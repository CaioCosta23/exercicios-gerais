#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"


tJogo CriaJogo() {
    tJogo jogo;

    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(JOGADOR_1);
    jogo.jogador2 = CriaJogador(JOGADOR_2);

    return jogo;

}

void ComecaJogo(tJogo jogo) {
    tJogo jogo;
    tJogada jogada;
    int j = 0;
    char peca;

    jogo = CriaJogo();

    do {
        if (j % 2 == 0) {
            peca = PECA_1;
        }else {
            peca = PECA_2;
        }

        jogada = LeJogada();

        if (EhPosicaoValidaTabuleiro(jogada.x, jogada.y)) {
            if (!(EstaMarcadaPosicaoPecaTabuleiro(jogo.tabuleiro, jogada.x, jogada.y, peca))) {
                if (EstaLivrePosicaoTabuleiro(jogo.tabuleiro, jogada.x, jogada.y)) {
                    jogo.tabuleiro = MarcaPosicaoTabuleiro(jogo.tabuleiro, peca, jogada.x, jogada.y);
                }else {
                    printf("Posicao invalida (OCUPADA - [%d, %d]!)", jogada.x, jogada.y);
                }
            }else {
                printf("Posicao invalida (OCUPADA - [%d, %d]!)", jogada.x, jogada.y);
            }
        }else {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d, %d]!)", jogada.x, jogada.y);
        }

        j++;

    }while(AcabouJogo(jogo));
}