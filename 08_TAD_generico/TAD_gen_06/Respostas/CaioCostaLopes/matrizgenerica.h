#ifndef _MATRIZ_GENERICA_H
#define _MATRIZ_GENERICA_H

typedef struct matrizgenerica tMatrizGenerica;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma matriz genérica (que recebe qualquer tipo de dado);
 *
 * @param linhas Número de linhas da matriz;
 * @param colunas Número de colunas da matriz;
 * @param numByteElem Número de Bytes de cada elemento da matriz;
 * OBS: Cria a matriz genérica desde que esse tipo ocupe determinado número de bytes;
 * @return Ponteiro para a etrutura do tipo "tMatrizGenerica" que contém os campos de dados da matriz genérica inicializados;
 */
tMatrizGenerica *CriaMatrizGenerica(int linhas, int colunas, int numByteElem);

/**
 * @brief Obtém o número de linhas da matriz;
 *
 * @param mat Ponteiro para a estrutura do tipo "tMatrizGenerica" que contém os dados atuailzados da matriz genérica;
 *
 * @return Número de linhas da matriz;
 */
int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica *mat);

/**
 * @brief Obtém o número de colunas da matriz;
 *
 * @param mat Ponteiro para a estrutura do tipo "tMatrizGenerica" que contém os dados atuailzados da matriz genérica;
 *
 * @return Número de colunas da matriz;
 */
int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica *mat);

/**
 * @brief Obtém um elemento da matriz genérica;
 *
 * @param mat Ponteiro para a estrutura do tipo "tMatrizGenerica" que contém os dados atuailzados da matriz genérica;
 * @param linha Linha em que o elemento está localizado na matriz geérica;
 * @param coluna Coluna que o elemento está localizado na matriz genérica;
 *
 * @return Ponteiro vazio para o elemento da matriz que está na linha e coluna passadas como parâmetro;
 */
void *ObtemElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna);

/**
 * @brief Atribui um elemento a uma posição de uma matriz;
 *
 * @param mat Ponteiro para a estrutura do tipo "tMatrizGenerica" que contém os dados atuailzados da matriz genérica;
 * @param linha Linha da matriz em que o elemento será atribuido;
 * @param coluna Coluna da matriz em que o elemento será atribuido;
 * @param elem Elemento que será adicionando a matriz;
 */
void AtribuiElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna, void *elem);

/**
 * @brief Encontra a transposta de uma matriz;
 *
 * @param mat Ponteiro para a estrutura do tipo "tMatrizGenerica" que contém os dados atuailzados da matriz genérica;
 *
 * @return Ponteiro para a matriz do tipo "tMatrizGeérica" criada à partir da matriz transposta;
 */
tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat);

/**
 * @brief Calcula a multiplicação entre duas matrizes;
 *
 * @param mat1 Ponteiro para a estrutura do tipo "tMatrizGenerica" que contém os dados atuailzados da matriz genérica 1;
 * @param mat2 Ponteiro para a estrutura do tipo "tMatrizGenerica" que contém os dados atuailzados da matriz genérica 2;
 * @param numByteTarget Número de bytes do elemento resultante da multiplicação entre os elementos de duas matrizes
 * @param multi_elem Ponteiro para a função que multiplica elementos de duas matrizes elemento;
 * @param soma_elem Ponteiro para a função que multiplica elementos de soma matrizes elemento;
 *
 * @return Ponteiro para a matriz do tipo "tMatrizGeérica" criada à partir da matriz resultante da multiplicação de duas outras matrizes genéricas;
 */
tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1, tMatrizGenerica *mat2, int numByteTarget, void* (*multi_elem)(void*, void*), void* (*soma_elem)(void*,void*));


/**
 * @brief Converte o tipo da matriz;
 *
 * @param mat Ponteiro para a estrutura do tipo "tMatrizGenerica" que contém os dados atuailzados da matriz genérica que terá seu tipo convertido;
 * @param novoNumByteElem Número de bytes do novo tipo da matriz;
 * @param converte_elem  Ponteiro para função que tem a capacidade de converter o elemento do tipo original para o novo tipo;
 *
 * @return Ponteiro para a estrutura do tipo "tMatrizGenerica" que possui um novo tipo;
 */
tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem, void* (*converte_elem)(void*));

/**
 * @brief Imprime os elementos da matriz;
 *
 * @param mat Ponteiro para a estrutura do tipo "tMatrizGenerica" que contém os dados atuailzados da matriz genérica;
 * @param imprime_elemento Ponteiro para a função de impressão de um elemento;
 */

void ImprimirMatrizGenerica(tMatrizGenerica *mat, void (imprime_elemento(void*)));

/**
 * @brief Destrói (a memória alocada dinamicamente de) uma matriz;
 *
 * @param mat Ponteiro para a estrutura do tipo "tMatrizGenerica" que contém os dados atuailzados da matriz genérica;
 */
void DestroiMatrizGenerica(tMatrizGenerica *mat);

#endif