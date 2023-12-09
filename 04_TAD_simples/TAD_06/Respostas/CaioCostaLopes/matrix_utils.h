#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#define MAX_MATRIX_SIZE 10

typedef struct Matrix {
    int rows;
    int cols;
    int data[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
}tMatrix;

/**
 * @brief Cria uma matriz com o número de linhas e o número de colunas especificado; 
 * 
 * @param rows Número de linhas da matriz;
 * @param cols Número de colunas da matriz;
 * @return tMatrix Matriz criada;
 */
tMatrix MatrixCreate(int rows, int cols);

/**
 * @brief Lê uma matriz da entrada padrão;
 * 
 * @param matrix Matriz a ser lida;
 * @return tMatrix Matriz lida;
 */
tMatrix MatrixRead (tMatrix matrix);

/**
 * @brief Imprime uma matriz na sída padrão;
 * 
 * @param matrix Matriz a ser impressa;
 */
void MatrixPrint(tMatrix matrix);

/**
 * @brief Verifica se é possível subtrair duas matrizes;
 * 
 * @param matrix1 Primeira matriz a ser verificada;
 * @param matrix2 Segunda matriz a ser verificada;
 * @return int 1 se for possível somar as matrizes e 0, caso contrário;
 */
int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Verifica se é possível somar duas matrizes;
 * 
 * @param matrix1 Primeira matriz a ser verificada;
 * @param matrix2 Segunda matriz a ser verificada;
 * @return int 1 se for possível subtrair as matrizes e 0, caso contrário;
 */
int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Verifica se é possível multiplicar as duas matrizes;
 * 
 * @param matrix1 Primeira matriz a ser verificada;
 * @param matrix2 Segunda matriz a ser verificada;
 * @return int 1 se for possível multiplicar as duas matrizes e 0, caso contrário;
 */
int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Soma duas matrizes;
 * 
 * @param matrix1 Primeira matriz;
 * @param matrix2 Segunda matriz;
 * @return tMatrix Resultado da soma das duas matrizes;
 */
tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Subtrai duas matrizes;
 * 
 * @param matrix1 Primeira matriz;
 * @param matrix2 Segunda matriz;
 * @return tMatrix resultado da subtração das duas matrizes;
 */
tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Multiplica dusa matrizes;
 * 
 * @param matrix1 Primeira matriz;
 * @param matrix2 Segunda matriz;
 * @return tMatrix Resultado da multiplicação das duas matrizes;
 */
tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Transpõe uma matriz;
 * 
 * @param matrix Matriz a ser transposta;
 * @return tMatrix Matriz transposta;
 */
tMatrix TransposeMatrix(tMatrix matrix);

/**
 * @brief Multiplica uma matriz por um escalar (número);
 * 
 * @param matrix Matriz a ser multiplicada;
 * @param scalar Escalar (número) que multiplicará a matriz;
 * @return tMatrix Resultado da multiplicação;
 */
tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar);

#endif