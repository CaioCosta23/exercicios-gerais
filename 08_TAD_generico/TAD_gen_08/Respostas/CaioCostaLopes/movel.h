#if !defined(_MOVEL_H_)
#define _MOVEL_H_

typedef struct Movel tMovel;

/**
 * @brief Cria (aloca a memória dinâmicamente de) um móvel;
 * 
 * @param nome Nome do móvel;
 * 
 * @return Ponteiro para a estrutura do tipo "tMovel" que contém os campos de dados de um móvel inicializados;
 */
tMovel *CriaMovel(char *nome);

/**
 * @brief Lê os dados movel;
 * 
 * @return Ponteiro para a estrutura do tipo "tMovel" que contém dados atualizados;
 */
tMovel *LeMovel();

/**
 * @brief Imprime o nome de um movel;
 * 
 * @param m Ponteiro para a estrutura do tipo "tMovel" que contém dados atualizados;
 */
void ImprimeMovel(tMovel *m);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) um móvel;
 * @param m Ponteiro para a estrutura do tipo "tMovel" que contém dados atualizados do móvel a ser destruído;
 */
void DestroiMovel(tMovel *m);

#endif