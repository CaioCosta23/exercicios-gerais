#ifndef _TABULEIRO_H
#define _TABULEIRO_H

#define TAM_TABULEIRO 3
#define PECA1 1
#define PECA_2 2

typedef struct{
    char **posicoes;
    char peca1;
    char peca2;
    char pecaVazio;
}tTabuleiro;

/**
 * @brief Aloca e retona uma estrutura do tipo "tTabuleiro;
 * 
 * @return tTabuleiro* esrutua do tipo Tableiro alocada;
 */
tTabuleiro *CriaTabuleiro();

/**
 * @brief Libera memória de uma estrutura do tipo "tTabuleiro";
 * 
 * @param tabuleiro A estruura do tipo "tTabuleiro" a ser liberada;
 */
void DestroiTabuleiro(tTabuleiro *tabuleiro);

/**
 * @brief Marca uma posição do tabuleiro com a peça do jogador;
 * 
 * @param tabuleiro Tabuleiro atual;
 * @param peca A peca do jogado (1 ou 2);
 * @param x A coordenada X da posição;
 * @param y A coordenada Y da posição;
 */
void MarcaPosicaoTabuleiro (tTabuleiro *tabuleiro, int peca, int x, int y);


#endif