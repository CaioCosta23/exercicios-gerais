#ifndef _jogo
#define _jogo

#include <math.h>

typedef struct Jogo tJogo;

/**
 * @brief Cria (aloca a memória dinamicamente de) um jogo;
 * 
 * @return tJogo* Ponteiro para a estrutura do tipo "tJogo" que contém os campos de dados incializados;
 */
tJogo *CriaJogo();

/**
 * @brief Define o valor máximo do intervalo que o jogo deve considerar;
 * 
 * @param jogo Ponteiro para a estrutura do tipo "tJogo" que contém os dados do jogo;
 * @param max Valor máximo do intervalo do jogo;
 */
void DefineMaximo(tJogo *jogo, int max);

/**
 * @brief Define o valor mínimo do intervalo que o jogo deve considerar;
 * 
 * @param jogo Ponteiro para a estrutura do tipo "tJogo" que contém os dados do jogo;
 * @param min Valor mínimo do intervalo do jogo;
 */
void DefineMinimo(tJogo *jogo, int min);

/**
 * @brief Cálcula o número a ser adivinhado pelo jogador;
 * 
 * @param jogo Ponteiro para a estrutura do tipo "tJogo" que contém os dados do jogo;
 * @param n Valor do número a ser adivinhado;
 */
void CalculaValorASerAdivinhado(tJogo *jogo, int n);

/**
 * @brief Cálcula o número de tentativas que o usuário terá para adivinhar o número;
 * 
 * @param jogo Ponteiro para a estrutura do tipo "tJogo" que contém os dados do jogo;
 */
void CalculaNumeroTentativas(tJogo *jogo);

/**
 * @brief Executa o jogo, lê as tentativas e realiza os cálculos do jogo;
 * 
 * @param jogo Ponteiro para a estrutura do tipo "tJogo" que contém os dados do jogo;
 * @return int 1 se o usuario venceu o jogo, 0 caso contrário;
 */
int ProcessaTentativas(tJogo *jogo);

/**
 * @brief Destroi (libera a memória alocada dinamicamente do) jogo;
 * 
 * @param jogo Ponteiro para a estrutura do tipo "tJogo" que contém os dados do jogo que será destruído;
 */
void DestroiJogo(tJogo *jogo);

#endif