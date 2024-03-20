#ifndef _JOGADOR_H
#define _JOGADOR_H

#include "tabuleiro.h"

#define ID_JOGADOR_1 1
#define ID_JOGADOR_2 2


typedef struct {
    int id;
}tJogador;


/**
 * @brief Aloca e retorna uma estrutura do tipo tJogador.
 * Se falhar, o programa é encerrado;
 * 
 * @param idJogador ID do jogador (1 ou 2);
 * @return tJogador* Estrutura odotipo "tJogador";
 */
tJogador *CriaJogador(int idJogador);

/**
 * @brief Libera a memória de uma estrutura do tipo "tJogador";
 * 
 * @param jogador A estrutura do tipo tJogador a ser liberada;
 */
void DestroiJogador(tJogador *jogador);

/**
 * @brief Lê uma jogada e armazena em uma estrutura do tipo "tJogada";
 * 
 * @param jogador Jogador atual;
 * @param tabuleiro Tabuleiro atual;
 */
void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro);

/**
 * @brief Verifica se o jogador venceu o jogo;
 * 
 * @param jogador Jogador atual;
 * @param tabuleiro Tabuleiro atual;
 * @return int 1 se o jogador venceu, 0 caso contrário;
 */
int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro);

#endif