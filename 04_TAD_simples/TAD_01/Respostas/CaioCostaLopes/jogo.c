#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"


tJogo CriaJogo() {
    tJogo jogo;

    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(JOGADOR_1);
    jogo.jogador2 = CriaJogador(JOGADOR_2);

    return jogo;
}

int AcabouJogo(tJogo jogo) {
    if(!(TemPosicaoLivreTabuleiro(jogo.tabuleiro))) {
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
                printf("Jogador %d venceu!\n", JOGADOR_1);
                break;
            }
        }else {
            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
            if (VenceuJogador(jogo.jogador2, jogo.tabuleiro)) {
                printf("Jogador %d venceu!\n", JOGADOR_2);
                break;
            }
        }
        j++;

    }while(!(AcabouJogo(jogo)));
}

int ContinuaJogo() {
    char opcao;

    printf("Jogar novamente? (s,n) ");
    scanf("%*[^\n]");
    scanf("%*c");
    scanf("%c", &opcao);

    if (opcao == 's') {
        return 1;
    }else {
        if (opcao == 'n') {
            return 0;
        }
    }
    return - 1;
}