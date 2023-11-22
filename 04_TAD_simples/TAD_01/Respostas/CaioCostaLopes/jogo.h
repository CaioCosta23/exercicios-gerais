#ifndef _JOGO_H
#define _JOGO_H

#include "tabuleiro.h"
#include "jogador.h"

typedef struct {
    tTabuleiro tabuleiro;
    tJogador jogador1;
    tJogador jogador2;
}tJogo;

/**
 * @brief Cria o jogo;
 * 
 * @return tJogo Jogo criado;
 */
tJogo CriaJogo();

/**
 * @brief Inicia o jogo, definindo tabuleiro e jogadores;
 * 
 * @param jogo Jogo a ser iniciado;
 */
void ComecaJogo(tJogo jogo);

/**
 * @brief Verifica se o jogo acabou (se não há mais posicões livres no tabuleiro); 
 * 
 * @param jogo jogo atual;
 * @return int 1 se o jogo acabou e 0 caos contrário;
 */
int AcabouJogo(tJogo jogo);

/**
 * @brief Verifica se o usuário deseja jogar novamente;
 * 
 * @return int 1 se o usuário deseja jogar novamente e 0, caos contrário;
 */
int ContinuaJogo();

#endif