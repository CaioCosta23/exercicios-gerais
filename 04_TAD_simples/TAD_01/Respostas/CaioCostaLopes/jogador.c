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