#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include "jogada.h"


tJogo CriaJogo() {
    tJogo jogo;

    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(JOGADOR_1);
    jogo.jogador2 = CriaJogador(JOGADOR_2);

    return jogo;
}

int AcabouJogo(tJogo jogo) {
    if(TemPosicaiLivreTabuleiro(jogo.tabuleiro)) {
        return 1;
    }
    return 0;
}

void ComecaJogo(tJogo jogo) {
    tJogo jogo;
    tJogada jogada;
    int j = 0;

    jogo = CriaJogo();

    do {

        jogada = LeJogada();

        if (EhPosicaoValidaTabuleiro(jogada.x, jogada.y)) {
            if (j % 2 == 0) {
                jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);    
            }else {
                jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
            }
        }

        j++;

    }while(!(AcabouJogo(jogo)));
}

int ContinuaJogo() {
    char opcao;

    do{
        scanf("%*[^%c]%c", &opcao);

        if (opcao == 's') {
            return 1;
        }else {
            if (opcao == 'n') {
                return 0;
            }
        }
    }while((opcao != 's') && (opcao != 'n'));
}