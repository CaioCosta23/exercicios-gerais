#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

#define VAZIO '-'

struct Tabuleiro {
    char **posicoes;
    char peca1;
    char peca2;
    char pecaVazio;
};

tTabuleiro *CriaTabuleiro() {
    int m, l, c;
    tTabuleiro *tabuleiro = (tTabuleiro*)malloc(sizeof(tTabuleiro));

    if (tabuleiro == NULL) {
        printf("Erro na alocacao do tabuleiro!\n");
        return tabuleiro;
    }

    tabuleiro->posicoes = (char**)malloc(TAM_TABULEIRO * sizeof(char*));
    if ((*tabuleiro).posicoes == NULL) {
        DestroiTabuleiro(tabuleiro);
        printf("Erro na alocacao da matriz das posições do tabuleiro!\n");
        return tabuleiro;
    }

    for (m = 0; m < TAM_TABULEIRO; m++) {
        tabuleiro->posicoes[m] = (char*)malloc(TAM_TABULEIRO * sizeof(char));
        if ((*tabuleiro).posicoes[m] == NULL) {
            printf("Erro na alocacao da posicao %d da matriz do tabuleiro do jogo!\n", m);
            DestroiTabuleiro(tabuleiro);
            return tabuleiro;
        }
    }

    tabuleiro->pecaVazio = VAZIO;

    for (l = 0; l < TAM_TABULEIRO; l++) {
        for (c = 0; c < TAM_TABULEIRO; c++) 
        tabuleiro->posicoes[l][c] = (*tabuleiro).pecaVazio;
    }

    tabuleiro->peca1 = 'X';
    tabuleiro->peca2 = '0';

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro) {
    int l, c;

    for (l = 0; l < TAM_TABULEIRO; l++) {
        for (c = 0; c < TAM_TABULEIRO; c++) {
            if ((*tabuleiro).posicoes[l][c] == (*tabuleiro).pecaVazio) {
                return 1;
            }
        }
    }
    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y) {
    return (((x >= 0) && (x < TAM_TABULEIRO)) && ((y >= 0) && (y < TAM_TABULEIRO)));
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y, int peca) {
    char marcacao;

    if (peca == PECA_1) {
        marcacao = (*tabuleiro).peca1;
    }else {
        marcacao = (*tabuleiro).peca2;
    }

    return ((*tabuleiro).posicoes[y][x] == marcacao);
}

int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y) {
    return ((*tabuleiro).posicoes[y][x] == (*tabuleiro).pecaVazio);
}

void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y) {
    char marcacao;

    if (peca == PECA_1) {
        marcacao = (*tabuleiro).peca1;
    }else {
        marcacao = (*tabuleiro).peca2;
    }

    (*tabuleiro).posicoes[y][x] = marcacao;
}

void ImprimeTabuleiro(tTabuleiro *tabuleiro) {
    int l, c;

    for (l = 0; l < TAM_TABULEIRO; l++) {
        for (c = 0; c < TAM_TABULEIRO; c++) {
            printf("%c", (*tabuleiro).posicoes[l][c]);
        }
        printf("\n");
    }
}

void DestroiTabuleiro(tTabuleiro *tabuleiro) {
    int m;
    
    if (tabuleiro != NULL) {
        if ((*tabuleiro).posicoes != NULL) {
            for(m = 0; m < TAM_TABULEIRO; m++) {
                if ((*tabuleiro).posicoes[m] != NULL) {
                    free((*tabuleiro).posicoes[m]);
                    tabuleiro->posicoes[m] = NULL;
                }
            }
            free((*tabuleiro).posicoes);
            tabuleiro->posicoes = NULL;
        }
        free(tabuleiro);
        tabuleiro = NULL;
    }
}