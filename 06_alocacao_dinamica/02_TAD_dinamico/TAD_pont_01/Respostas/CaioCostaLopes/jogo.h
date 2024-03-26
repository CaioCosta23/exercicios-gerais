#ifndef _JOGO_H
#define _JOGO_H

#include "jogador.h"
#include "tabuleiro.h"

typedef struct {
    tTabuleiro *tabuleiro;
    tJogador *jogador1;
    tJogador *jogador2;

}tJogo;

/**
 * @brief Aloca e retona uma estrutura do tipo "tJogo";
 *  Se a alocação falhar, o programa é encerrao;
 * 
 * @return tJogo* a estrutura do tipo "tJogo" alocada;
 */
tJogo *CriaJogo();

/**
 * @brief Inicia o jogo definindo o tabuleiro e os jogadores;
 * 
 * @param jogo O jogo a ser iniciado;
 */
void ComecaJogo(tJogo *jogo);

/**
 * @brief Verifica se o jogo acabou (se não há mais posições livres no tabuleiro);
 * 
 * @param jogo O jogo atual;
 * @return int 1 se o joo acabou, 0 caso contrário;
 */
int AcabouJogo (tJogo *jogo);

/**
 * @brief Veifica se o usuário deseja jogar novamente;
 * 
 * @return int 1 se  o usuário deseja jogar novamene, 0 caso contrário;
 */
int ContinuaJogo();

/**
 * @brief Libera a memória de uma estrutura do tipo "tJogo";
 * 
 * @param jogo A estrutura do tipo "tJogo" a ser liberada;
 */
void DestroiJogo(tJogo *jogo);


#endif