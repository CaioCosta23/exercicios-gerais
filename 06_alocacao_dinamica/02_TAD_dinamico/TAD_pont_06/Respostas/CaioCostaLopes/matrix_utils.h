#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#define MAX_MATRIX_SIZE 10

typedef struct Matrix {
    int rows;
    int cols;
    int **data;
}tMatrix;

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado;
 * 
 * @param rows Número de linhas da matriz;
 * @param cols Número de colunas da matriz;
 * @return tMatrix* Matriz criada;
 */
tMatrix *MatrixCreate(int rows, int cols);

/**
 * @brief Lê os dados de uma matrix da entrada padrão;
 * 
 * @param matrix Matriz lida;
 */
void MatrixRead(tMatrix *matrix);

/**
 * @brief Verifica se é possiível somar duas matrizes;
 * 
 * @param matrix1 Primeira matriz;
 * @param matrix2 Segunda matriz;
 * @return int 1 se for possível somar as matrizes, 0 caso contrário;
 */
int PossibleMatrixSum(tMatrix *matrix1, tMatrix *matrix2);

/**
 * @brief Verifica se é possível subtrair duas matrizes;
 * 
 * @param matrix1 Primeira matriz;
 * @param matrix2 Segunda matriz;
 * @return int 1 se for possível subtrair as matrizes, 0 caso contrário;
 */
int PossibleMatrixSub(tMatrix *matrix1, tMatrix *matrix2);

/**
 * @brief Verifica se é possível subtrair duas matrizes;
 * 
 * @param matrix1 Primeira matriz;
 * @param matrix2 Segunda matriz;
 * @return int 1 se for possível subtrair as matrizes, 0 caso contrário;
 */
int PossibleMatrixMultiply(tMatrix *matrix1, tMatrix *matrix2);

/**
 * @brief Soma duas matrizes;
 * 
 * @param matrix1 Primeira matriz;
 * @param matrix2 Segunda matriz;
 * @return tMatrix* O resultado da soma das matrizes;
 */
tMatrix *MatrixAdd(tMatrix *matrix1, tMatrix *matrix2);

/**
 * @brief Subtrai duas matrizes;
 * 
 * @param matrix1 Primeira matriz;
 * @param matrix2 Segunda matriz;
 * @return tMatrix* O resultado da subtração das matrizes;
 */
tMatrix *MatrixSub(tMatrix *matrix1, tMatrix *matrix2);

/**
 * @brief Multiplica duas matrizes;
 * 
 * @param matrix1 Primeira matriz;
 * @param matrix2 Segunda matriz;
 * @return tMatrix* O resultado da multiplicação das matrizes;
 */
tMatrix *MatrixMultiply(tMatrix *matrix1, tMatrix *matrix2);

/**
 * @brief Transpõe uma matriz;
 * 
 * @param matrix Matriz a ser transposta;
 * @return tMatrix* Matriz transposta;
 */
tMatrix *TransposeMatrix(tMatrix *matrix);

/**
 * @brief Multiplica uma matriz por um escalar (valor constante);
 * 
 * @param matrix Matrix a ser multiplicada pelo escalar;
 * @param scalar Escalar pelo qual a matriz será multiplicada;
 * @return tMatrix* Resultado da multiplicação da matriz pelo escalar;
 */
tMatrix *MatrixMultiplyByScalar(tMatrix *matrix, int scalar);

/**
 * @brief Imprime uma matriz na saída padrão;
 * 
 * @param matrix Matriz a ser impressa;
 */
void MatrixPrint(tMatrix *matrix);

/**
 * @brief Libera (memória alocada da) matriz;
 * 
 * @param matrix Ponteiro pata a estrutura que armazena a matriz;
 */
void MatrixFree(tMatrix *matrix);

#endif