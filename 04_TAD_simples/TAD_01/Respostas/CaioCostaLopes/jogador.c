#include <stdio.h>
#include "jogador.h"
#include "jogada.h"
#include "tabuleiro.h"

tJogador CriaJogador(int id_Jogador) {
    tJogador jogador;

    jogador.id = id_Jogador;

    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    tJogada jogada;
    int x, y;

    jogada = LeJogada();
    x = ObtemJogadaX(jogada);
    y = ObtemJogadaY(jogada);
    
    if (EhPosicaoValidaTabuleiro(x, y)) {
        if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, x, y, jogador.id))) {
            if (EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) {
                tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);
            }
        }
    }
    
    /*
        printf("Posicao invalida (OCUPADA - [%d, %d]!)", jogada.x, jogada.y);
        printf("Posicao invalida (OCUPADA - [%d, %d]!)", jogada.x, jogada.y);
        printf("Posicao invalida (FORA DO TABULEIRO - [%d, %d]!)", jogada.x, jogada.y);
    */
}