#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

struct Jogo {
    tTabuleiro *tabuleiro;
    tJogador *jogador1;
    tJogador *jogador2;
};

tJogo *CriaJogo() {
    tJogo *jogo = (tJogo*)malloc(sizeof(tJogo));

    if (jogo == NULL) {
        printf("Erro na alocação do jogo!\n");
        exit(1);
    }

    jogo->tabuleiro = CriaTabuleiro();
    if ((*jogo).tabuleiro == NULL) {
        DestroiJogo(jogo);
        exit(1);
    }

    jogo->jogador1 = CriaJogador(PECA_1);
    if ((*jogo).jogador1 == NULL) {
        DestroiJogo(jogo);
        printf("%d!\n", ID_JOGADOR_1);
        exit(1);
    }

    jogo->jogador2 = CriaJogador(PECA_2);
    if ((*jogo).jogador2 == NULL) {
        DestroiJogo(jogo);
        printf("%d\n", ID_JOGADOR_2);
        exit(1);
    }

    return jogo;
}

int AcabouJogo(tJogo *jogo) {
    if (!(TemPosicaoLivreTabuleiro((*jogo).tabuleiro))) {
        return 1;
    }
    return 0;
}

void ComecaJogo(tJogo *jogo) {
    while(1) {
        JogaJogador((*jogo).jogador1, (*jogo).tabuleiro);
        if ((*jogo).jogador1 == NULL) {
            DestroiJogo(jogo);
            exit(1);    
        }

        ImprimeTabuleiro((*jogo).tabuleiro);

        if (VenceuJogador((*jogo).jogador1, (*jogo).tabuleiro)) {
            printf("JOGADOR %d Venceu!\n", PECA_1);
            break;
        }
        if (AcabouJogo(jogo)) {
            printf("Sem vencedor!\n");
            break;
        }

        JogaJogador((*jogo).jogador2, (*jogo).tabuleiro);
        if ((*jogo).jogador2 == NULL) {
            DestroiJogo(jogo);
            exit(1);    
        }

        ImprimeTabuleiro((*jogo).tabuleiro);

        if (VenceuJogador((*jogo).jogador2, (*jogo).tabuleiro)) {
            printf("JOGADOR %d Venceu!\n", PECA_2);
            break;
        }
        if (AcabouJogo(jogo)) {
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
    if (jogo != NULL) {
        if ((*jogo).tabuleiro != NULL) {
            if ((*jogo).jogador1 != NULL) {
                if ((*jogo).jogador2 != NULL) {
                    DestroiJogador((*jogo).jogador2);
                }
                DestroiJogador((*jogo).jogador1);
            }
            DestroiTabuleiro((*jogo).tabuleiro);
        }
        free(jogo);
        jogo = NULL;
    }
}