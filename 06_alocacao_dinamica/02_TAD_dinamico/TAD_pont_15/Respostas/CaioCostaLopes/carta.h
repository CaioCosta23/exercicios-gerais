#ifndef _cartas
#define _cartas

#include <stdbool.h>

#define MAX_NOME 100

typedef struct carta *tCarta;

struct carta {
    int id;
    char *nome;
    int magia;
    int ataque;
    int fogo;
    int num_vit;
    int num_duelos;
};

/**
 * @brief Cria (aloca a memória dinamicamente) e lê as informações de uma carta do jogo;
 * 
 * @return tCarta Estrutura (do tipo ponteiro) do tipo "tCarta" com os dados da carta; 
 */
tCarta LeCarta();

/**
 * @brief Obtém o ID (identificador) da carta;
 * 
 * @param c Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o ID (identificador) da carta;
 * @return int ID (identificador) da carta;
 */
int GetIdCarta(tCarta c);

/**
 * @brief Obtém o (ponteiro do) nome da carta;
 * 
 * @param c Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o nome da carta;
 * @return char* 
 */
char *GetNomeCarta(tCarta c);

/**
 * @brief Obtém o número de vitórias em duelos da carta;
 * 
 * @param c Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o número de vitórias em duelos da carta;
 * @return int Número de vitórias em duelos da carta;
 */
int GetNumVitCarta(tCarta c);

/**
 * @brief Obtém o valor do peder de magia da carta;
 * 
 * @param c Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o valor do poder de magia da carta;
 * @return int Valor do poder de magia da carta;
 */
int GetMagiaCarta(tCarta c);

/**
 * @brief Obtém o poder de ataque da carta;
 * 
 * @param c Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o poder de ataque da carta;
 * @return int Poder de ataque da carta;
 */
int GetAtaqueCarta(tCarta c);

/**
 * @brief Obtém o poder de fogo da carta;
 * 
 * @param c Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o poder de fogo da carta;
 * @return int Poder de fogo da carta;
 */
int GetFogoCarta(tCarta c);

/**
 * @brief Verifica se uma carta é válida;
 * 
 * @param c Estrutura (do tipo ponteiro) do tipo "tCarta" que contém os dados da carta;
 * @return true Se a carta for válida;
 * @return false Se a carta não for válida;
 */
bool EhCartaValida(tCarta c);

/**
 * @brief Verifica se duas cartas possuem o mesmo ID (Identificador);
 * 
 * @param c1 Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o ID (identificador) da primeira carta;
 * @param c2 Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o ID (identificador) da segunda carta;
 * @return true Se a primeira carta possui o mesmo ID (identificador) da segunda carta;
 * @return false Se a primeira carta não possui o mesmo ID (identificador) da segunda carta;
 */
bool EhMesmoIdCarta(tCarta c1, tCarta c2);

/**
 * @brief Compara o ID (Identificador) de duas cartas;
 * 
 * @param c1 Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o ID (identificador) da primeira carta;
 * @param c2 Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o ID (identificador) da segunda carta;
 * @return int Valor negativo se o ID (identificador) da primeira carta for maior que o da segunda, Valor positivo se o ID (identificador) da primeira carta for menor que o da segunda,
 *  e 0 se o ID (identificador) das cartas for igual;
 */
int ComparaIdCarta(tCarta c1, tCarta c2);

/**
 * @brief Compara o poder de magia de duas cartas;
 * 
 * @param c1 Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o poder de magia da primeira carta;
 * @param c2 Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o poder de magia da segunda carta;
 * @return int Valor negativo se o poder de magia da primeira carta for maior que o da segunda, valor positivo se o poder de maigia da primeira carta for menor que o da segunda,
 *  e 0 se o poder de magia das cartas for igual;
 */
int ComparaMagiaCarta(tCarta c1, tCarta c2);

/**
 * @brief Compara o poder de ataque de duas cartas;
 * 
 * @param c1 Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o poder de ataque da primeira carta;
 * @param c2 Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o poder de ataque da segunda carta;
 * @return int Valor negativo se o poder de atauqe da primeira carta for maior que o da segunda, valor positivo se o poder de ataque da primeira carta for menor que o da segunda,
 *  e 0 se o poder de ataque das cartas for igual;
 */
int ComparaAtaqueCarta(tCarta c1, tCarta c2);

/**
 * @brief Compara o poder de fogo de duas cartas;
 * 
 * @param c1 Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o poder de fogo da primeira carta;
 * @param c2 Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o poder de fogo da segunda carta;
 * @return int Valor negativo se o poder de fogo da primeira carta for maior que o da segunda, valor positivo se o poder de fogo da primeira carta for menor que o da segunda,
 *  e 0 se o poder de fogo das cartas for igual;
 */
int ComparaFogoCarta(tCarta c1, tCarta c2);

/**
 * @brief Adiciona uma vitória para uma carta;
 * 
 * @param c Estrutura (do tipo ponteiro) do tipo "tCarta" que contém o número de vitórias;
 * @return int Número de vitórias em duelos de uma carta (incrementado);
 */
int AdicionaVitoriaCarta(tCarta c);

/**
 * @brief Imprime os dados de uma carta;
 * 
 * @param c Estrutura (do tipo ponteiro) do tipo "tCarta" que contém os dados da carta;
 */
void ImprimeCarta(tCarta c);

/**
 * @brief Libera (a memória alocada dinamicamente de) uma carta;
 * 
 * @param c Estrutura (do tipo ponteiro) do tipo "tCarta" que será apagada;
 */
void LiberaCarta(tCarta c);

#endif