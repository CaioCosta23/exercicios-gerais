#ifndef _TABULEIRO_H
#define _TABULEIRO_H

#define TAM_TABULEIRO 3
#define PECA_1 1
#define PECA_2 2

typedef struct Tabuleiro tTabuleiro;

/**
 * @brief Cria (aloca memória dinamicamente) um tabuleiro;
 * 
 * OBS: Se a alocação de memória falhar, encerra o programa;
 * 
 * @return tTabuleiro* Ponteiro para uma estrutura do tipo "tTabuleiro" com os dados do tabuleiro inicializados;
 */
tTabuleiro *CriaTabuleiro();

/**
 * @brief Marca uma posição do tabuleiro com a peça do jogador;
 * 
 * @param tabuleiro Ponteiro para a estrutura do tipo "tTabuleiro" que contém o estado atual do jogo (no tabuleiro);
 * @param peca Peça do jogador (1 ou 2);
 * @param x Coordenada X da posição em que será feita a jogada;
 * @param y Coordenada Y da posição em que será feita a jogada;
 */
void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y);

/**
 * @brief Verifica se há alguma posição livre no tabuleiro;
 * 
 * @param tabuleiro Ponteiro para a estrutura do tipo "tTabuleiro" que contém o estado atual do tabuleiro no jogo;
 * @return int 1 se houver alguma posição livre, 0 caso contrário;
 */
int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro);

/**
 * @brief Verifica se a posição do tabuleiro está livre;
 * 
 * @param tabuleiro Ponteiro para a estrutura do tipo "tTabuleiro" que contém os dados e o estado atual do tabuleiro
 * @param x Coordenada X da posição a ser verificada;
 * @param y Coordenada Y da posição a ser vreificada;
 * @param peca Peça do jogador (1 ou 2);
 * @return int 1 se a posição estiver marcada, 0 caso contrário;
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y, int peca);

/**
 * @brief Verifica se a posição do tabuleiro está livre (se não há uma peça do próprio jogado ou do adversário na posição);
 * 
 * @param tabuleiro Ponteiro para a estrutura do tipo;
 * @param x Coordenada X da posição a ser verificada;
 * @param y Coordenada Y da posição a ser verificada;
 * @return int 1 se a posição está livre, 0 caso contrário;
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y);

/**
 * @brief Verifica se uma posição é válida no tabuleiro;
 * 
 * @param x A coordenada X a ser verificada;
 * @param y A coordenada Y a ser verificada;
 * @return int 1 se a posição é válida, 0 caso contrário;
 */
int EhPosicaoValidaTabuleiro(int x, int y);

/**
 * @brief Imprime o tabuleiro do jogo;
 * 
 * @param tabuleiro Ponteiro para a estrutura do tipo "tTabuleiro" do tabuleiro que será impresso;
 */
void ImprimeTabuleiro(tTabuleiro *tabuleiro);

/**
 * @brief Destrói (libera a memória alocada dinamicamente do) tabuleiro;
 * 
 * @param tabuleiro Ponetro para a estrutura do tipo "tTabuleiro" que será destruida (desalocada);
 */
void DestroiTabuleiro(tTabuleiro *tabuleiro);

#endif