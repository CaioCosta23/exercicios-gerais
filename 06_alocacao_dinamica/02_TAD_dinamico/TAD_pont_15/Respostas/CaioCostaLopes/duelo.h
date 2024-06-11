#ifndef _duelo
#define _duelo

#include "carta.h"
#include <stdbool.h>

#define MAGIA 'M' // Opção para duelo de magia;
#define FORCA 'F' // Opção para duelo de força (ataque);
#define FOGO 'G' // Opção para duelo de fogo;

typedef struct duelo *tDuelo;
struct duelo {
    int id;
    int c1;
    int c2;
    char atributo;
    bool desempate;
    int vencedor;
    int diferenca;
};

/**
 * @brief Cria (e aloca a memória dinamicamente) e lê as informações do duelo;
 * 
 * @return tDuelo Estrutura (do tipo ponteiro) do tipo "tDuelo" que contém os dados do duelo;
 */
tDuelo LeDuelo();

/**
 * @brief Realiza um duelo entre duas cartas;
 * 
 * @param d Estrutura (do tipo ponteiro) do tipo "tDuelo" que contém os dados do duelo;
 * @param c1 Estrutura (do tipo ponteiro) do tipo "tCarta" que contém os dados da primeira carta;
 * @param c2 Estrutura (do tipo ponteiro) do tipo "tCarta" que contém os dados da segunda carta;
 */
void RealizaDuelo(tDuelo d, tCarta c1, tCarta c2);

/**
 * @brief Obtém o ID (identificador) da primeira carta do duelo;
 * 
 * @param d Estrutura (do tipo ponteiro) do tipo "tDuelo" que contém os dados do duelo;
 * @return int ID (identificador) da primeira carta do duelo;
 */
int GetC1Duelo(tDuelo d);

/**
 * @brief Obtém o ID (identificador) da segunda carta do duelo;
 * 
 * @param d Estrutura (do tipo ponteiro) do tipo "tDuelo" que contém os dados do duelo;
 * @return int ID (identificador) da segunda carta do duelo;
 */
int GetC2Duelo(tDuelo d);

/**
 * @brief Verifica se houve necessidade de desempate no duelo;
 * 
 * @param d Estrutura (do tipo ponteiro) do tipo "tDuelo" que contém os dados do duelo;
 * @return true Se houve necessidade de um critério de desempate;
 * @return false Se houve não necessidade de um critério de desempate;
 */
bool GetDesempateDuelo(tDuelo d);

/**
 * @brief Obtém a diferença de pontos entre as cartas em um duelo;
 * 
 * @param d Estrutura (do tipo ponteiro) do tipo "tDuelo" que contém os dados do duelo;
 * @return int Diferença de pontos entre duas cartas em um duelo;
 */
int GetDiferencaDuelo(tDuelo d);

/**
 * @brief Obtém o ID (Identificador) de um duelo;
 * 
 * @param d Estrutura (do tipo ponteiro) do tipo "tDuelo" que contém os dados do duelo;
 * @return int ID (identificador) do duelo;
 */
int GetIdDuelo(tDuelo d);

/**
 * @brief Imprime os dados de um duelo;
 * 
 * @param d Estrutura (do tipo ponteiro) do tipo "tDuelo" que contém os dados do duelo;
 */
void ImprimeDuelo(tDuelo d);

/**
 * @brief Libera (a memória alocada dinamicamente de) um duelo;
 * 
 * @param d Estrutura (do tipo ponteiro) do tipo "tDuelo" que contém os dados do duelo;
 */
void LiberaDuelo(tDuelo d);

#endif