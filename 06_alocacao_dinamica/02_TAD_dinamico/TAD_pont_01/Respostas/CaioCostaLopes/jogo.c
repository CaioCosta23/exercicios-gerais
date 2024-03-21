#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include "jogador.h"
#include "tabuleiro.h"

tJogo *CriaJogo() {
    // Aloca dinmicamente uma estrutura do tipo "tJogo";
    tJogo *jogo = (tJogo *) malloc(sizeof(tJogo));

    // Se a alocação falhar (ou seja, o ponteiro apontar para uma área nula, então hove erro na alocação e o programa é encerrado imediatamente);
    if (jogo == NULL) {
        printf("Erro na alocacao!");
        exit(1);
    }

    jogo->tabuleiro = CriaTabuleiro();
    jogo->jogador1 = CriaJogador(PECA_1);
    jogo->jogador2 = CriaJogador(PECA_2);

    return jogo;
}

int AcabouJogo(tJogo *jogo) {
    if (!(TemPosicaoLivreTabuleiro((*jogo).tabuleiro))) {
        return 1;
    }
    return 0;
}

void ComecaJogo(tJogo *jogo) {
    while (1) {
        JogaJogador((*jogo).jogador1, (*jogo).tabuleiro);
        ImprimeTabuleiro((*jogo).tabuleiro);

        if(VenceuJogador((*jogo).jogador1, (*jogo).tabuleiro)) {
            printf("JOGADOR %d Venceu!\n", PECA_1);
            break;
        }
        if(AcabouJogo(jogo)) {
            printf("Sem vencedor!\n");
            break;
        }

        JogaJogador((*jogo).jogador2, (*jogo).tabuleiro);
        ImprimeTabuleiro((*jogo).tabuleiro);

        if(VenceuJogador((*jogo).jogador2, (*jogo).tabuleiro)) {
            printf("JOGADOR %d Venceu!\n", PECA_2);
            break;
        }
        if(AcabouJogo(jogo)) {
            printf("Sem vencedor!\n");
            break;
        }
    }
}

int ContinuaJogo() {
    char opcao;

    printf("Jogar novamente? (s,n) ");

    scanf("%*[^sn]");
    scanf("%c", &opcao);

    printf("\n");

    if (opcao == 's') {
        return 1;
    }
    
    return 0;
}

void DestroiJogo(tJogo *jogo) {
    free((*jogo).tabuleiro);
    free((*jogo).jogador1);
    free((*jogo).jogador2);
    free(jogo);
}