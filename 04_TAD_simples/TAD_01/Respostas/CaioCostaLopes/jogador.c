#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "jogada.h"
#include "tabuleiro.h"

tJogador CriaJogador(int id_Jogador)
{
    tJogador jogador;

    jogador.id = id_Jogador;

    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    tJogada jogada;

    while (1)
    {
        printf("Jogador %d\n", jogador.id);

        jogada = LeJogada();

        if (!(FoiJogadaBemSucedida(jogada)))
        {
            scanf("%*[^\n]\n");
        }
        else
        {
            if (EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)))
            {
                if (!(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada), jogador.id)))
                {
                    if (EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)))
                    {
                        printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                        break;
                    }
                    else
                    {
                        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                    }
                }
                else
                {
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                }
            }
            else
            {
                printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            }
        }
    }
    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    int l, c, d;
    int horizontal, vertical, primeDiagonal;
    char marcacao;

    for (l = 0; l < TAM_TABULEIRO; l++)
    {

        for (c = 0; c < TAM_TABULEIRO; c++)
        {
            printf("%c", tabuleiro.posicoes[l][c]);
        }
        printf("\n");
    }

    marcacao = (char)(jogador.id + '0');

    for (l = 0; l < TAM_TABULEIRO; l++)
    {
        horizontal = 0;
        vertical = 0;
        for (c = 0; c < TAM_TABULEIRO; c++)
        {
            if (tabuleiro.posicoes[l][c] == marcacao)
            {
                horizontal += 1;
            }
            if (tabuleiro.posicoes[c][l] == marcacao)
            {
                vertical += 1;
            }
        }
        if ((horizontal == 3) || (vertical) == 3)
        {
            return 1;
        }
    }

    primeDiagonal = 0;

    for (d = 0; d < TAM_TABULEIRO; d++)
    {
        // Diagonal onde os elementos que formam a diagonal tem tanto o índice da linha quanto da coluna tendo o mesmo valor;
        if ((tabuleiro.posicoes[d][d] == marcacao))
        {
            primeDiagonal += 1;
        }
    }

    if (primeDiagonal == 3)
    {
        return 1;
        /* Verifica as extremidades diagonais do jogo, para ver se o jogador formou uma sequencia na dioganal primária
         *(onde os índices de linha e coluna são os mesmos - "primeDiagonal");
         */
    }

    // Verifica se o jogador venceu na diagonal "secundária" (diagonal onde os indíces da linha e da coluna não tem o mesmo valor);
    if ((tabuleiro.posicoes[0][TAM_TABULEIRO - 1] == marcacao) && (tabuleiro.posicoes[TAM_TABULEIRO / 2][TAM_TABULEIRO / 2] == marcacao) &&
        (tabuleiro.posicoes[TAM_TABULEIRO - 1][0] == marcacao))
    {
        return 1;
    }

    return 0;
}