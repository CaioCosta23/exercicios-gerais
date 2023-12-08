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
        for (c = 0; c < matrix.cols; c++) {
            // Imprime cada barra que tem na borda da matriz (antes do primeiro elemento de cada linha);
            if (c == 0) {
                printf("|");
            }
            // Imprime os elementos da matriz;
            printf("%d", matrix.data[r][c]);
            // Imprime os espaços entre cada elemento da matriz;
            if (c < (matrix.cols - 2)) {
                printf(" ");
            }
            // Imprime cada barra que tem na borda da matriz (depoiss do último elemento de cada linha);
            if (c == (matrix.cols - 1)) {
                printf("|");
            }
        }
        printf("\n");
    }
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
    tMatrix resultado;

    for (r = 0; r < matrix2.rows; r++) {
        for (c = 0; c < matrix2.cols; c++) {
            resultado.data[r][c] = matrix1.data[r][c] + matrix2.data[r][c];            
        }
    }
    return resultado;
}

tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2) {
    int r, c;
    tMatrix resultado;

    for (r = 0; r < matrix1.rows; r++) {
        for (c = 0; c < matrix1.cols; c++) {
            resultado.data[r][c] = matrix1.data[r][c] - matrix2.data[r][c];            
        }
    }
    return resultado;
}

tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2) {
    tMatrix resultado;
    /*
    * AINDA SEM CÓDIGO!!!!
    */
    return resultado;
}

tMatrix TransposteMatrix(tMatrix matrix) {
    tMatrix resultado;
    int r, c;

    resultado.rows = matrix.cols;
    resultado.cols = matrix.rows;

    for (r = 0; r < matrix.rows; r++) {
        for (c = 0; c < matrix.cols; c++) {
            resultado.data[r][c] = matrix.data[c][r];
        }
    }
    return resultado;
}

tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar) {
    tMatrix resultado;
    int r, c;

    for (r = 0; r < matrix.rows; r++) {
        for (c = 0; c < matrix.cols; c++) {
            resultado.data[r][c] = matrix.data[r][c] * scalar;
        }
    }
    return resultado;    
}