#ifndef _JOGADOR_H
#define _JOGADOR_H

#include "tabuleiro.h"

#define ID_JOGADOR_1 1
#define ID_JOGADOR_2 2

typedef struct Jogador tJogador;

/**
 * @brief Cria (aloca a memória dinamicamente) um jogador;
 * 
 * @param idJogador ID (Identificador) de um jogador;
 * @return tJogador* Ponteiro para a estrutura do tipo "tJogador" que contém os dados (inicializados) do jogador;
 */
tJogador *CriaJogador (int idJogador);

/**
 * @brief Lê uma jogada e armazena em uma estrutura do tipo "tJogada";
 * 
 * @param jogador Ponteiro para a estrutura do tipo "tJogador" que contém os dados do jogador;
 * @param tabuleiro Ponteiro para a estrutura do tipo "tTabuleiro" em que será realizada a jogada do jogador;
 */
void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro);

/**
 * @brief Verifica se um jogador venceu o jogo;
 * 
 * @param jogador Ponteiro para a estrutura do tipo "tJogador" que contém os dados do jogador;
 * @param tabuleiro Ponteiro para a estrutura do tipo "tTabuleiro" em que será realizada a jogada do jogador;
 * @return int 
 */
int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro);

/**
 * @brief Destrói (libera a memória alocada dinamicamente de) um jogador; 
 * 
 * @param jogador Ponteiro para a estrutura do tipo "tJogador" que será destruída (desalocada);
 */
void DestroiJogador(tJogador *jogador);

#endif