#ifndef _TABULEIRO_H
#define _TABULEIRO_H

#define TAM_TABULEIRO 3
#define PECA_1 1
#define PECA_2 2

typedef struct{
    char posicoes[TAM_TABULEIRO][TAM_TABULEIRO];
    char peca1;
    char peca2;
    char pecaVazio;

}tTabuleiro;

/**
 * @brief Cria o e retorna o tabuleiro do jogo; 
 * 
 * @return tTabuleiro Tabuleiro criado;
 */
tTabuleiro CriaTabuleiro();

/**
 * @brief Marca uma posição do tabuleiro com a peça do jogador e retorna o tabuleiro marcado;
 * 
 * @param peca Peça do jogador (1 ou 2);
 * @param x Coordenada X da posição a ser marcada;
 * @param y Coordenada Y da posição a ser marcada;
 * @return tTabuleiro Tabuleiro Atualizado;
 */
tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro, int peca, int x, int y);

/**
 * @brief Verifica se tem uma posição livre no tabuleiro;
 * 
 * @param tabuleiro Tabuleiro atual;
 * @return int 1 se a posição está livre e 0, caso contrário;
 */
int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro);

/**
 * @brief Verifica se a posição no tabuleiro está marcada com a peça do jogador;
 * 
 * @param tabuleiro Tabuleiro atual;
 * @param x Coordenada X da posição a ser verificada;
 * @param y Coordenada Y da posição a ser verificada;
 * @param peca Peça do jogador (1 ou 2);
 * @return int 1 se a posição está marcada com a peça dp jogador e 0, caso contrário;
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca);

/**
 * @brief Verifica se a posição do tabuleiro está livre;
 * 
 * @param tabuleiro Tabuleiro atual;
 * @param x Coordenada X da posição a ser verificada;
 * @param y Coordenada Y da posição a ser verificada;
 * @return int 1 se a posição está livre e 0, caso contrário;
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y);

/**
 * @brief Verifica se a posição do tabuleiro é válida;
 * 
 * @param x Coordenada X da posição a ser verificada;
 * @param y Coordenada Y da posição a ser verificada;
 * @return int 1 se a posição for válida e 0, caoso contrário;
 */
int EhPosicaoValidaTabuleiro(int x, int y);

/**
 * @brief Imprime o tabuleiro atual e verifica se o mesmo está cheio;
 * 
 * @param tabuleiro Tabuleiro atual;
 */
void ImprimeTabuleiro(tTabuleiro tabuleiro);

#endif