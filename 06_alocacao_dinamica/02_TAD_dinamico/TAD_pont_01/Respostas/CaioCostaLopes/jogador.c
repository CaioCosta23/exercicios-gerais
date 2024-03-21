#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "jogada.h"
#include "tabuleiro.h"

tJogador *CriaJogador(int idJogador) {
    // Aloca dinamicamente a estrutura do jogador; 
    tJogador *jogador = (tJogador *)malloc (sizeof(tJogador));

    jogador->id = idJogador;

    return jogador;
}

void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro) {
    tJogada *jogada;

    jogada = CriaJogada();

    while(1) {
        printf("Jogador %d\n", (*jogador).id);

        LeJogada(jogada);

        // verifica se a jogada foi bem sucedida (se a leitura dos dados foi correta), se não, limpa o buffer e tenta a leitura novamente;
        if (!(FoiJogadaBemSucedida(jogada))) {
            scanf("%*[^\n]\n");
        }else {
            // Verifica se a posição digitada na jogada está dentro do tabuleiro;
            if (EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
                // Verifica se a posição no tabuleiro não está marcada com uma peça do próprio jogador;
                if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada), (*jogador).id))) {
                    // Verifica se a posição não está marcada com uma peça do adversário;
                    if (EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
                        printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                        // Caso as condicionais acima forem todas verdadeiras, a peça do jogador é marcada o tabuleiro;
                        MarcaPosicaoTabuleiro(tabuleiro, (*jogador).id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                        break;
                    }else {
                        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                    }
                }else {
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                }
            }else {
                printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            }
        }
    }
    // Desaloca a jogada;
    DestroiJogada(jogada);
}

int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro) {
    int l, c, d;
    int horizontal, vertical, primeDiagonal;
    char marcacao;

    // Se o ID do jogador é igual o da peça, então a marcação vai (caractere referente ao jogador) será registrado;
    if ((*jogador).id == PECA_1) {
        marcacao = (*tabuleiro).peca1;
    }else {
        marcacao = (*tabuleiro).peca2;
    }

    // Verifica se uma carreira completa de três peças do mesmo jogador foi feita na vertical ou a horizontal;
    for (l = 0; l < TAM_TABULEIRO; l++) {
        horizontal = 0;
        vertical = 0;
        for(c = 0; c < TAM_TABULEIRO; c++) {
            if ((*tabuleiro).posicoes[l][c] == marcacao) {
                horizontal += 1;
            }
            if ((*tabuleiro).posicoes[c][l] == marcacao) {
                vertical += 1;
            }
        }
        if ((horizontal == 3) || (vertical == 3)) {
            return 1;
        }
    }

    primeDiagonal = 0;

    //Verifica se uma fileira de 3 peças foi feita na diagonal esquerda;
    for (d = 0; d < TAM_TABULEIRO; d++) {
        if ((*tabuleiro).posicoes[d][d] == marcacao) {
            primeDiagonal += 1;
        }
    }
    if (primeDiagonal == 3) {
        return 1;
        /* Verifica as extremidades diagonais do jogo, para ver se o jogador formou uma sequencia na dioganal primária
         *(onde os índices de linha e coluna são os mesmos - "primeDiagonal");
         */
    }

    // Verifica se o jogador venceu na diagonal "secundária" (diagonal onde os indíces da linha e da coluna não tem o mesmo valor);
    if (((*tabuleiro).posicoes[0][TAM_TABULEIRO - 1] == marcacao) && ((*tabuleiro).posicoes[TAM_TABULEIRO / 2][TAM_TABULEIRO / 2] == marcacao) &&
        ((*tabuleiro).posicoes[TAM_TABULEIRO - 1][0] == marcacao)) {
        return 1;
    }
    return 0;
}

void DestroiJogador(tJogador *jogador) {
    free(jogador);
}