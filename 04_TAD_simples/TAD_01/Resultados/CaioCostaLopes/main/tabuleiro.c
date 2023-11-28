#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "jogada.h"
#include "tabuleiro.h"
#include "jogo.h"

#define VAZIO -1

tTabuleiro CriaTabuleiro()
{
    int l, c;
    tTabuleiro tabuleiro;

    tabuleiro.pecaVazio = VAZIO;

    for (l = 0; l < TAM_TABULEIRO; l++)
    {
        for (c = 0; c < TAM_TABULEIRO; c++)
        {
            tabuleiro.posicoes[l][c] = tabuleiro.pecaVazio;
        }
    }
    tabuleiro.peca1 = PECA_1;
    tabuleiro.peca2 = PECA_2;

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro)
{
    int l, c;

    for (l = 0; l < TAM_TABULEIRO; l++)
    {
        for (c = 0; c < TAM_TABULEIRO; c++)
        {
            if (tabuleiro.posicoes[l][c] == tabuleiro.pecaVazio)
            {
                return 1;
            }
        }
    }
    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y)
{
    return (((x >= 0) && (x < TAM_TABULEIRO)) && ((y >= 0) && (y < TAM_TABULEIRO)));
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca)
{
    return (tabuleiro.posicoes[y][x] == peca);
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y)
{
    return (tabuleiro.posicoes[y][x] == tabuleiro.pecaVazio);
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y)
{
    tabuleiro.posicoes[y][x] = peca;
    return tabuleiro;
}

void ImprimeTabuleiro(tTabuleiro tabuleiro)
{
    int l, c;

    for (l = 0; l < TAM_TABULEIRO; l++)
    {
        for (c = 0; c < TAM_TABULEIRO; c++)
        {
            if (tabuleiro.posicoes[l][c] == tabuleiro.peca1)
            {
                printf("X");
            }
            else
            {
                if (tabuleiro.posicoes[l][c] == tabuleiro.peca2)
                {
                    printf("0");
                }
                else
                {
                    printf("-");
                }
            }
        }
        printf("\n");
    }
}