#include <stdio.h>
#include <stdlib.h>
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

    while (1) {
        printf("Jogador %d\n", jogador.id);
        printf("Digite uma posicao (x e y):\n");

        jogada = LeJogada();

        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);
        
        if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, x, y, jogador.id))) {
            if (EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) {
                if (FoiJogadaBemSucedida(jogada)) {
                    jogada.sucesso = 1;
                    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);
                    ImprimeTabuleiro(tabuleiro);
                    break;
                }else {
                    printf("Posicao invalida (FORA DO TABULEIRO - [%d, %d]!)\n", jogada.x, jogada.y);
                }
            }else {
                printf("Posicao invalida (OCUPADA - [%d, %d]!)\n", jogada.x, jogada.y);
            }
        }else {
            printf("Posicao invalida (OCUPADA - [%d, %d]!)\n", jogada.x, jogada.y);
        }
    }
    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
    int l, c, d;
    int horizontal, vertical, diagonal;

    for (l = 0; l < TAM_TABULEIRO; l++) {
        horizontal = 0;
        for (c = 0; c < TAM_TABULEIRO; c++) {
            if (tabuleiro.posicoes[l][c] == jogador.id) {
                horizontal += 1;
            }
        }
        if (horizontal == 3) {
            return 1;
        }
    }

    for (c = 0; c < TAM_TABULEIRO; c++) {
        vertical = 0;
        for (l = 0; l < TAM_TABULEIRO; l++) {
            if (tabuleiro.posicoes[l][c] == jogador.id) {
                vertical += 1;
            }
        }
        if (vertical == 3) {
            return 1;
        }
    }

    diagonal = 0;

    for (d = 0; d < TAM_TABULEIRO; d++) {
        if ((tabuleiro.posicoes[d][d] == jogador.id) || (tabuleiro.posicoes[0][TAM_TABULEIRO - 1] == jogador.id)
         || (tabuleiro.posicoes[TAM_TABULEIRO - 1][0] == jogador.id)) {
            // Verifica as extremidades diagonais do jogo, para ver se o jogador formou uma sequencia em uma das diagonais;
            diagonal += 1;
        }
    }
    if (diagonal == 3) {
        return 1;
    }
    return 0;
}