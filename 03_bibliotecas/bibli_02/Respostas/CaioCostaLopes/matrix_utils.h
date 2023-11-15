#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

/**
 * @brief Le os valores da matriz especificada a partir da entrada padrao;
 * 
 * @param rows Numero de linhas da matriz;
 * @param cols numero de colunas da matriz;
 * @param matrix matriz a ser preenchida;
 */
void matrix_read(int rows, int cols, int matrix[rows][cols]);

/**
 * @brief Imprime a matriz especificada na saida padrao; 
 * 
 * @param rows Numero de linhas da matriz;
 * @param cols Numero de colunas da matriz;
 * @param matrix Matriz a ser impressa;
 */
void matrix_print(int rows, int cols, int matrix[rows][cols]);

/**
 * @brief Verifica se e possivel somar as duas matrizes;
 * 
 * @param rows1 Numero de linhas da primeira matriz;
 * @param cols1 Numero de colunas da primeira matriz;
 * @param rows2 Numero de linhas da segunda matriz;
 * @param cows2 Numero de colunas da segunda matriz;
 * @return int 1 se for posivel somar as matrizes ou 0, caso contrario;
 */
int possible_matrix_sum(int rows1, int cols1, int rows2, int cows2);

/**
 * @brief Verifica se e possivel subtrair as duas matrizes;
 * 
 * @param rows1 Numero de linhas da primeira matriz;
 * @param cols1 Numero de colunas da primeira matriz;
 * @param rows2 Numero de linhas da segunda matriz;
 * @param cols2 Numero de colunas da segunda matriz;
 * @return int 1 se for possivel subtrair as matrizes ou 0, caso contrario;
 */
int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2);

/**
 * @brief Verifica se e possivel mutiplicar as duas matrizes;
 * 
 * @param cols1 Numero de colunas da primeira matriz;
 * @param rows2 Numero de colunas da segunda matriz;
 * @return int 1 se for possivel multiplicar as matrizes ou 0, caso contrario;
 */
int possible_matrix_multiply(int cols1, int rows2);

/**
 * @brief Soma duas matrizes e armazena o resultado na primeira matriz;
 * 
 * @param rows1 Numero de linhas da primeira matriz;
 * @param cols1 Numero de colunas da segunda matriz;
 * @param matrix1 Primeira matriz;
 * @param rows2 Numero linhas da segunda matriz;
 * @param cols2 Numero de colunas da segunda matriz;
 * @param matrix2 Segunda matriz;
 * @param result Matriz que armazenará o resultado da soma;
 */
void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]);

/**
 * @brief Subtrai duas matrizes e armazena o resultado na primeira matriz;
 * 
 * @param rows1 Numero de lihas da primeira matriz;
 * @param cols1 Numero de colunas da primeira matriz;
 * @param matrix1 Primeira matriz;
 * @param rows2 Numero de linhas da segunda matriz;
 * @param cols2 Numero de colunas da segunda matriz;
 * @param matrix2 Segunda matriz;
 * @param result Matriz que armazenara o resultado da subtracao;
 */
void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]);

/**
 * @brief Multiplica duas matrizes e armazena o resultado na primeira matriz;
 * 
 * @param rows1 Numero de linhas da primeira matrz;
 * @param cols1 Numero de colunas da primeira matriz;
 * @param matrix1 Primeira matriz;
 * @param rows2 Numero de linhas da segunda matriz;
 * @param cols2 Numero de colunas da segunda matriz;
 * @param matrix2 Segunda matriz;
 * @param result Matriz que armazenara o resultado da multiplicacao;
 */
void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]);

/**
 * @brief Transpoe a matriz especificada;
 * 
 * @param rows Numero de linhas da matriz;
 * @param cols Numero de colunas da matriz;
 * @param matrix Matriz a ser transposta;
 * @param result Matriz que arnmazenara o resultado da transposicao;
 */
void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]);

/**
 * @brief Multiplica a matriz especificada poor um escalar; 
 * 
 * @param rows Numero de linhas da matriz;
 * @param cols Numero de clunas da matriz;
 * @param matrix Matriz a ser multiplicada;
 * @param scalar Escalar a ser multiplicado;
 */
void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar);

#endif