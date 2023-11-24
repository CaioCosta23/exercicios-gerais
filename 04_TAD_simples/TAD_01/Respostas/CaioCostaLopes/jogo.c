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

int AcabouJogo(tJogo jogo) {
    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro)) {
        return 1;
    }
    return 0;
}

void ComecaJogo(tJogo jogo) {
    int j = 1;

    jogo = CriaJogo();

    do {
        if ((j % 2) != 0) {
            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
            if (VenceuJogador(jogo.jogador1, jogo.tabuleiro)) {
                printf("Jogador %d venceu!", JOGADOR_1);
                break;
            }
        }else {
            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
            if (VenceuJogador(jogo.jogador1, jogo.tabuleiro)) {
                printf("Jogador %d venceu!", JOGADOR_1);
                break;
            }
        }
        j++;

    }while(!(AcabouJogo(jogo)));
}

int ContinuaJogo() {
    char opcao;

    do{
        scanf("%*[^\n]\n%c", &opcao);

        if (opcao == 's') {
            return 1;
        }else {
            if (opcao == 'n') {
                return 0;
            }
        }
    }while((opcao != 's') && (opcao != 'n'));
}