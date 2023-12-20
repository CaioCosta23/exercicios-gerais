#ifndef _UTILS_H_
#define _UTILS_H_


/**
 * @brief Função que cria uma matriz de inteiros, alocada dinamicamente;
 * 
 * @param linhas Número de linhas da matriz;
 * @param colunas Número de colunas da matriz;
 * @return int** Ponteiro para a matriz alocada;
 * OBS: Se a alocação falhar, o programa deve ser encerrado;
 */
int **CriaMatriz(int linhas, int colunas);

/**
 * @brief Função que libera a memória alocada para uma matriz de inteiros;
 * 
 * @param matriz Ponteiro para a matriz a ser liberada;
 * @param linhas Número de linhas da matriz;
 */
void LiberaMatriz(int **matriz, int linhas);

/**
 * @brief Função que lê uma matriz de inteiros da entrada padrão;
 * 
 * @param matriz Ponteiro para a matriz a ser lida;
 * @param linhas Número de linhas da matriz;
 * @param colunas Número de colunas da matriz;
 */
void LeMatriz(int **matriz, int linhas, int colunas);

/**
 * @brief Imprime a matriz transposta da matriz dada;
 * 
 * @param matriz Ponteiro para a matriz;
 * @param linhas Número de linhas da matriz;
 * @param colunas Número de colunas da matriz;
 */
void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas);

#endif