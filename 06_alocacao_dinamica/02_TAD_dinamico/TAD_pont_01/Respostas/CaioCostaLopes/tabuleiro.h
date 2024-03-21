#ifndef _TABULEIRO_H
#define _TABULEIRO_H

#define TAM_TABULEIRO 3
#define PECA_1 1
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

/**
 * @brief Verifica se a posição do tabuleiro está marcada com uma peça de algum jogador;
 * 
 * @param tabuleiro Tabuleiro atual;
 * @return int 1 se a posição está marcada, 0 caso contrário;
 */
int TemPosicaoLivreTabueiro(tTabuleiro *tabuleiro);

/**
 * @brief Verifica se a posição do tabuleiro está marcada com a peça o jogador;
 * 
 * @param tabuleiro Tabuleiro atual;
 * @param x Coordenada X da posição;
 * @param y Coordenada Y da posição;
 * @return int 1 se a posição está marcada com a peça do jogador , 0 caso contrário;
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y, int peca);

/**
 * @brief Verifica se a posição do tabuleiro está livre;
 * 
 * @param tabuleiro Tabuleiro atual;
 * @param x Coordenada X da posição;
 * @param y Coordenada Y do jogo;
 * @return int 1 se a posição está livre, 0 caso contrário;
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y);

/**
 * @brief Verifica se a posição do tabuleiro é válida;
 * 
 * @param x Coordenada X da posição;
 * @param y Coordenada Y da posição;
 * @return int 1 se  a posição é válida, 0 caso contrário;
 */
int EhPosicaoValida(int x, int y);

/**
 * @brief Imprime o tabuleiro;
 * 
 * @param tabuleiro Tabuleiro atual;
 */
void ImprimeTabuleiro(tTabuleiro *tabuleiro);

#endif