#ifndef _missil
#define _missil

#define MAX_TAM 100 // Tamanho máximo do nome do míssil;

// A estrutura tMissil contém o nome do míssil, as coordenadas x e y, e o poder de ataque;
typedef struct missil *tMissil;

/**
 * @brief Lê os dados (e cria, alocando a memória dinamicamente de) um missíl;
 * 
 * @return tMissil .
 */
tMissil LeMissil();

/**
 * @brief Imprime as informações do míssil.
 * 
 * @param missil Estrutura (do tipo ponteiro) "tMissil" que contém os dados inicializados do missíl;
 */
void ImprimeMissil(tMissil missil);

/**
 * @brief Obtém a coordenada y do míssil;
 * 
 * @param missil Estrutura (do tipo ponteiro) "tMissil" que contém os dados atualizados do missíl;
 * @return float Coordenada y do míssil;
 */
float GetMissilY(tMissil missil);

/**
 * @brief Obtém a coordenada x do míssil;
 * 
 * @param missil Estrutura (do tipo ponteiro) "tMissil" que contém os dados atualizados do missíl;
 * @return float Coordenada x do míssil;
 */
float GetMissilX(tMissil missil);

/**
 * @brief Obtém o (nível de) poder de ataque do míssil;
 * 
 * @param missil Estrutura (do tipo ponteiro) "tMissil" que contém os dados atualizados do missíl;
 * @return float Poder de ataque do míssil;
 */
float GetMissilPoder(tMissil missil);

/**
 * @brief Reduz o (nível de) poder de ataque do míssil;
 * 
 * @param missil Estrutura (do tipo ponteiro) "tMissil" que contém os dados atualizados do missíl;
 * @param valor Valor a ser subtraído do poder de ataque do míssil;
 */
void ReduzPoder(tMissil missil, float valor);

/**
 * @brief Libera (desaloca a memória dinamicamente de) um míssil;
 * 
 * @param missil Estrutura (do tipo ponteiro) "tMissil" que contém os dados atualizados do missíl;
 */
void LiberaMissil(tMissil missil);

#endif