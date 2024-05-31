#ifndef _nba
#define _nba

#include "franquia.h"
#include "partida.h"

#define MAX_FR 10 // Número máximo de franquias;
#define MAX_PT 10 // Número maximo de partidas;
#define CAD_FRANQUIA 'F' // Caractere para cadastro de franquia;
#define CAD_PARTIDA 'P' // Caractere para cadastro de partida;
#define ENCERRAR 'E' // Caractere para encerrar a NBA;

// Estrutura do tipo ponteiro;
typedef struct nba *tNBA;

struct nba {
    tFranquia *listafranquias;
    int qtdfranquias;
    int maxfranquias;
    tPartida * listapartidas;
    int qtdpartidas;
    int maxpartidas;
};

/**
 * @brief Cria (aloca a memória dinamicamente) uma estrutura para a NBA que conterá seus dados; 
 * 
 * @return tNBA Estrutura (do tipo ponteiro) do tipo "tNBA";
 */
tNBA CriaNBA();

/**
 * @brief Roda o programa que simula o andamento campeonato da NBA;
 * 
 * @param nba Estrutura (do tipo ponteiro) do tipo "tNBA" que contém as informações do torneio;
 * @return tNBA  Campeonato da NBA com seus dados atualizados de acordo com seu andamento;
 */
tNBA RodaNBA(tNBA nba);

/**
 * @brief Imprime o relatório final da NBA;
 * 
 * @param nba Estrutura (do tipo pontiro) do tipo "tNBA" que contém as informações finais do campeonato da NBA;
 */
void ImprimeRelatorioNBA(tNBA nba);

/**
 * @brief Libera (a memória a locada dinamicamente e) a NBA;
 * 
 * @param nba Estrutura (do tipo Ponteiro) do tipo "tNBA" que será liberada;
 */
void LiberaNBA(tNBA nba);

#endif