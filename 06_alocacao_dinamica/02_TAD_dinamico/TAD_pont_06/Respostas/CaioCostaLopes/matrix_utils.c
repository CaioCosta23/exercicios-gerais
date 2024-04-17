#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

tMatrix *MatrixCreate(int rows, int cols) {
    int m;
    tMatrix *matrix = (tMatrix*)malloc(sizeof(tMatrix));

    if (matrix == NULL) {
        printf("Erro na alocacao de memoria estrutura matriz!\n");
        exit(1);
    }

    matrix->rows = rows;
    matrix->cols = cols;

    matrix->data = (int**)malloc((*matrix).rows * sizeof(int*));
    if ((*matrix).data == NULL) {
        printf("Erro na alocacao das linhas da matriz da estrutura!\n");
        MatrixFree(matrix);
        exit(1);
    }

    for (m = 0; m < (*matrix).rows; m++) {
        matrix->data[m] = (int*)malloc((*matrix).cols * sizeof(int));
        if ((*matrix).data[m] == NULL) {
            printf("Erro na alocacao das celulas da matriz da estrutura!\n");
            MatrixFree(matrix);
            exit(1);
        }
    }
    return matrix;
}

void MatrixRead(tMatrix *matrix) {
    int r, c;

    for (r = 0; r < (*matrix).rows; r++) {
        for (c = 0; c < (*matrix).cols; c++) {
            scanf("%d", &matrix->data[r][c]);
        }
    }

}

int PossibleMatrixSum(tMatrix *matrix1, tMatrix *matrix2) {
    return (((*matrix1).rows == (*matrix2).rows) && ((*matrix1).cols == (*matrix2).cols));
}

int PossibleMatrixSub(tMatrix *matrix1, tMatrix *matrix2) {
    return (((*matrix1).rows == (*matrix2).rows) && ((*matrix1).cols == (*matrix2).cols));
}

int PossibleMatrixMultiply(tMatrix *matrix1, tMatrix *matrix2) {
    return ((*matrix1).rows == (*matrix2).cols);
}

tMatrix *MatrixAdd(tMatrix *matrix1, tMatrix *matrix2) {
    tMatrix *result = NULL;
    int r, c;

    result = MatrixCreate((*matrix1).rows, (*matrix2).cols);

    for (r = 0; r < (*result).rows; r++) {
        for (c = 0; c < (*result).cols; c++) {
            result->data[r][c] = (*matrix1).data[r][c] + (*matrix2).data[r][c];
        }
    }
    return result;
}

tMatrix *MatrixSub(tMatrix *matrix1, tMatrix *matrix2) {
    tMatrix *result = NULL;
    int r, c;

    result = MatrixCreate((*matrix1).rows, (*matrix2).cols);

    for (r = 0; r < (*result).rows; r++) {
        for (c = 0; c < (*result).cols; c++) {
            result->data[r][c] = (*matrix1).data[r][c] - (*matrix2).data[r][c];
        }
    }
    return result;
}

tMatrix *MatrixMultiply(tMatrix *matrix1, tMatrix *matrix2) {
    tMatrix *result = NULL;
    int c1, c2, mult;
    int r1 = 0;

    result = MatrixCreate((*matrix1).rows, (*matrix2).cols);

    while (r1 < (*result).rows) {
        c2 = 0;

        while (c2 < (*result).cols) {
            mult = 0;
            c1 = 0;

            while (c1 < (*matrix1).cols) {
                mult += (*matrix1).data[r1][c1] * (*matrix2).data[c1][c2];
                c1++;
            }
            result->data[r1][c2] = mult;
            c2++;
        }
        r1++;
    }
    return result;
}

tMatrix *TransposeMatrix(tMatrix *matrix) {
    int r, c;
    tMatrix *result = NULL;

    result = MatrixCreate((*matrix).cols, (*matrix).rows);

    for (r = 0; r < (*result).rows; r++) {
        for (c = 0; c < (*result).cols; c++) {
            result->data[r][c] = (*matrix).data[c][r];
        }
    }
    return result;
}

tMatrix *MatrixMultiplyByScalar(tMatrix *matrix, int scalar) {
    int r, c;
    tMatrix *result = NULL;

    result = MatrixCreate((*matrix).rows, (*matrix).cols);

    for (r = 0; r < (*result).rows; r++) {
        for (c = 0; c < (*result).cols; c++) {
            result->data[r][c] = (*matrix).data[r][c] * scalar;
        }
    }
    return result;
}

void MatrixPrint(tMatrix *matrix) {
    int r, c;

    for (r = 0; r < (*matrix).rows; r++) {
        printf("|");
        for (c = 0; c < (*matrix).cols; c++) {
            printf("%d", (*matrix).data[r][c]);

            if (c < ((*matrix).cols - 1)) {
                printf(" ");
            }
            if (c == ((*matrix).cols - 1)) {
                printf("|");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void MatrixFree(tMatrix *matrix) {
    int m;

    if (matrix != NULL) {
        if ((*matrix).data != NULL) {
            for (m = 0; m < (*matrix).rows; m++) {
                if ((*matrix).data[m] != NULL) {
                    free((*matrix).data[m]);
                }else {
                    break;
                }
            }
            free((*matrix).data);
        }
        free(matrix);
    }
}