#ifndef _JOGADOR_H
#define _JOGADOR_H

#include "tabuleiro.h"

#define JOGADOR_1 1
#define JOGADOR_2 2

typedef struct {
    int id;
}tJogador;

/**
 * @brief Cria um jogador com o ID passado como parâmetro e retorna o jogador criado;
 * 
 * @param idJogador ID do jogador (1 ou 2);
 * @return tJogador Jogador criado;
 */
tJogador CriaJogador(int idJogador);

/**
 * @brief Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada executada pelo jogador;
 * 
 * @param jogador Jogador que realizará a jogada;
 * @param tabuleiro Tabuleiro atual;
 * @return tTabuleiro Tabuleiro atualizado com a jogada do jogador;
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro);

/**
 * @brief Recebe um jogador e o tabuleiro e verifica se esse jogador venceu ou não a partida;
 * 
 * @param jogador Jogador a ser verificado;
 * @param tabuleiro Tabuleiro atual;
 * @return int 1 se o jogador venceu e 0, caso contrário;
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro);

#endif