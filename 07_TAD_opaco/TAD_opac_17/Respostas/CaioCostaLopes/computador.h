#ifndef _computador
#define _computador

#include "jogo.h"

typedef struct Computador tComputador;

/**
 * @brief Cria (aloca a memória dinamicamente de) um computador;
 * 
 * @return tComputador* Ponteiro para a estrutura do tipo "tComputador" com seus campos de dados inicializados;
 */
tComputador *CriaComputador();

/**
 * @brief Gerencia o jogo, recebendo dados (da entrada padrão) e executando ações necessárias para o funcionamento do jogo;
 * 
 * @param computador Ponteiro para a estrutura do tipo "tComputador" que contém os dados do computado (e consequentemente, do jogo);
 */
void GerenciaJogo(tComputador *computador);

/**
 * @brief Imprime o relatorio da rodada, mostrando o intervalo máximo de desejo do jogador, até onde o mesmo deseja jogar;
 * 
 * @param computador Ponteiro para a estrutura do tipo "tComputador" que possui os dados do computador (e consequentemente, do jogo);
 */
void ImprimeRelatorio(tComputador *computador);

/**
 * @brief Libera (desaloca a memória alocada dimnamicamente do) computador;
 * 
 * @param comp Ponteiro para a estrutura do tipo "tComputador" que contém os dados do computador (e consequentemente do jogo) que será destruído;
 */
void DestroiComputador(tComputador *comp);

#endif