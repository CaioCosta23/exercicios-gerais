#ifndef _JOGO_H
#define _JOGO_H

#include "jogador.h"
#include "tabuleiro.h"

typedef struct Jogo tJogo;

/**
 * @brief Cria (e aloca a memória dinamicamente) um jogo;
 * 
 * OBS: Caso a alocação de memória falhe, encerra o prgrama;
 * 
 * @return tJogo* Ponteiro para a estrutura do tipo "tJogo" (alocada dinamicamente) inicializada;
 */
tJogo *CriaJogo();

/**
 * @brief Inicia o jogo, definindo dados do tabuleiro e dos jogadores;
 *
 * @param jogo Estrutura do tipo "tJogo que receberá os dados (dos jogadores e tabuleiro) e o andamento do jogo" 
 */
void ComecaJogo(tJogo *jogo);

/**
 * @brief Verifica se o jogo acabou (se há posições livres no tabuleiro);
 * 
 * @param jogo Ponteiro para a estrutura do tipo do "tJogo" que contém os dados do jogo;
 * @return int 1 se o jogo terminou, 0 caso contrário;
 */
int AcabouJogo(tJogo *jogo);

/**
 * @brief Verifica se o usuário deseja jogar novamente;
 * 
 * @return int 1 se o usuário desejar continuar jogando, 0 caso contrário;
 */
int ContinuaJogo();

/**
 * @brief Destrói (libera a memória alocada dinamicamente) o jogo;
 * 
 * @param jogo Ponteiro para a estrutura do tipo "tJogo" que será destruido;
 */
void DestroiJogo(tJogo *jogo);

#endif