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
        printf("Erro na alocacao do jogo!");
        exit(1);
    }

    // Cria e atribui o tabuleiro e os jogadores a cada dado da estrutura do jogo;
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
        // Vez do Jogador 1 realizar sua jogada;
        JogaJogador((*jogo).jogador1, (*jogo).tabuleiro);
        // A cada jogada (independente de qual jogador fez a jogada), o tabuleiro é impresso na tela com o estado atual do jogo;
        ImprimeTabuleiro((*jogo).tabuleiro);

        // Verifica se o jogador 1 venceu e, caso sim, informa ao usuário do programa com uma mensagem encerra o jogo atual;
        if(VenceuJogador((*jogo).jogador1, (*jogo).tabuleiro)) {
            printf("JOGADOR %d Venceu!\n", PECA_1);
            break;
        }
        // Verifica se o jogo sem um vencedor;
        if(AcabouJogo(jogo)) {
            printf("Sem vencedor!\n");
            break;
        }

        // Verifica se o jogador 1 venceu e, caso sim, informa ao usuário do programa com uma mensagem encerra o jogo atual;
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

    // Consome tudo que o usuário digitar que seja diferente de 's' ou 'n';
    scanf("%*[^sn]");
    // Caso o usuário digite um 's' ou 'n', a varíável coleta a informação;
    scanf("%c", &opcao);

    printf("\n");

    // Se 's' (sim), o programa continuará rodando, se 'n' (não) a função retorna falso (0), indicando que o jogo não continuará (assim encerrando o programa);
    if (opcao == 's') {
        return 1;
    }
    
    return 0;
}

void DestroiJogo(tJogo *jogo) {
    // Chama as funções para destruir/ desalocar cada dado pertencente a estrutua do jogo;
    DestroiTabuleiro((*jogo).tabuleiro);
    DestroiJogador((*jogo).jogador1);
    DestroiJogador((*jogo).jogador2);

    // Desaloca a estrutura do jogo;
    free(jogo);
}