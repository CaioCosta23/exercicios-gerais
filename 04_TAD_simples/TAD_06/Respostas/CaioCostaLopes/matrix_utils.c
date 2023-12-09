#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

tMatrix MatrixCreate(int rows, int cols) {
    tMatrix matrix;
    
    matrix.rows = rows;
    matrix.cols = cols;
    matrix = MatrixRead(matrix);

    return matrix;
}

tMatrix MatrixRead(tMatrix matrix) {
    int r, c;

    for (r = 0; r < matrix.rows; r++) {
        for (c = 0; c < matrix.cols; c++) {
            scanf("%d", &matrix.data[r][c]);
        }
    }
    return matrix;
}

void MatrixPrint(tMatrix matrix) {
    int r, c;

    for (r = 0; r < matrix.rows; r++) {
        // Imprime cada barra que tem na borda da matriz (antes do primeiro elemento de cada linha);
        printf("|");
        for (c = 0; c < matrix.cols; c++) {
            // Imprime os elementos da matriz;
            printf("%d", matrix.data[r][c]);
            // Imprime os espaços entre cada elemento da matriz;
            if (c < (matrix.cols - 1)) {
                printf(" ");
            }
            // Imprime cada barra que tem na borda da matriz (depoiss do último elemento de cada linha);
            if (c == (matrix.cols - 1)) {
                printf("|");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2) {
    return ((matrix1.rows == matrix2.rows) && (matrix1.cols == matrix2.cols));
}

int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2) {
    return ((matrix1.rows == matrix2.rows) && (matrix1.cols == matrix2.cols));
}

int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2) {
    return (matrix1.rows == matrix2.cols);
}

tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2) {
    int r, c;
    tMatrix result;

    result.rows = matrix1.rows;
    result.cols = matrix1.cols;

    for (r = 0; r < matrix2.rows; r++) {
        for (c = 0; c < matrix2.cols; c++) {
            result.data[r][c] = matrix1.data[r][c] + matrix2.data[r][c];            
        }
    }
    return result;
}

tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2) {
    int r, c;
    tMatrix result;

    result.rows = matrix2.rows;
    result.cols = matrix2.cols;

    for (r = 0; r < matrix1.rows; r++) {
        for (c = 0; c < matrix1.cols; c++) {
            result.data[r][c] = matrix1.data[r][c] - matrix2.data[r][c];            
        }
    }
    return result;
}

tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2) {
    int r1, c1, c2, mult;
    tMatrix result;

    result.rows = matrix1.rows;
    result.cols = matrix2.cols;

    r1 = 0;

    // Define o numero de linhas que a matriz resultante tera;
    while(r1 < matrix1.rows) {
        c2 = 0;

        // Define o numero de colunas que a matriz resultante tera;
        while(c2 < matrix2.cols) {
            mult = 0;
            c1 = 0;

            // O numero de colunas da primeira matriz e sempre o numero de linhas da segunda, podemos usar qualquer uma como base;
            while(c1 < matrix1.cols) {
                /**
                 * @brief Recebe a soma das multiplicacoes que formarao um numero na matriz resultante;
                 * 
                 * Cada elemento "X" de uma linha da primeira mariz e multiplicado por um elemento coluna "Y" da segunda matrix,
                 * e o resultado dessas multiplicacoes e acumulado, para que surja o elemento N (resultado da multiplicacao) na
                 * matriz resultante;
                 */
                mult += matrix1.data[r1][c1] * matrix2.data[c1][c2];
                c1++;
            }
            /**
             * @brief Recebe o valor resultado da multiplicacao dos elementos das duas matrizes analisadas e o coloca na posicao
             * correta da matriz resultante;
             */
            result.data[r1][c2] = mult;

            c2++;
        }
        r1++;
    }

    return result;
}

tMatrix TransposeMatrix(tMatrix matrix) {
    tMatrix result;
    int r, c;

    result.rows = matrix.cols;
    result.cols = matrix.rows;

    for (r = 0; r < matrix.rows; r++) {
        for (c = 0; c < matrix.cols; c++) {
            result.data[c][r] = matrix.data[r][c];
        }
    }
    return result;
}

tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar) {
    tMatrix result;
    int r, c;

    result.cols = matrix.cols;
    result.rows = matrix.rows;    

    for (r = 0; r < matrix.rows; r++) {
        for (c = 0; c < matrix.cols; c++) {
            result.data[r][c] = matrix.data[r][c] * scalar;
        }
    }
    return result;    
}