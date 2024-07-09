#ifndef _nba
#define _nba

#include "franquia.h"
#include "partida.h"

#define MAX_FR 10 // Número máximo de franquias;
#define MAX_PT 10 // Número máximo de partidas;
#define CAD_FRANQUIA 'F' // Caractere de cadastro da franquia;
#define CAD_PARTIDA 'P' // Caracttere de cadastro da partida;
#define ENCERRAR 'E' // Caractere para encerra a NBA;

typedef struct nba *tNBA;

/**
 * @brief Cria (aloca a memória alocada dinâmicamente da) NBA (com seus atributos inicializados);
 * 
 * @return tNBA Estrutura (do tipo ponteiro) do tipo "tNBA" que contém os dados da NBA;
 */
tNBA CriaNBA();

/**
 * @brief Roda a NBA permitindo a ainteração com o usuário;
 * 
 * @param nba Estrutura (do tipo ponteiro) do tipo "tNBA" que contém os dados da NBA;
 * @return tNBA Estrutura (do tipo ponteiro) do tipo "tNBA" com os dados atualizado após a realização da NBA;
 */
tNBA RodaNBA(tNBA nba);

/**
 * @brief Imprime o relatório final da NBA;
 * 
 * @param nba Estrutura (do tipo ponteiro) do tipo "tNBA" que contém os dados da NBA que serão impressos;
 */
void ImprimeRelatorioNBA(tNBA nba);

/**
 * @brief Libera (a memória alocada dinamicamente da) NBA;
 * 
 * @param nba Estrutura (do tipo ponteiro) do tipo "tNBA" com os dados da NBA (e que serão liberados);
 */
void LiberaNBA(tNBA nba);

#endif