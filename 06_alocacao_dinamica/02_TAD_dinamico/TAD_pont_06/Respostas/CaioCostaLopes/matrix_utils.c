#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

tMatrix *MatrixCreate(int rows, int cols) {
    int m;
    // Aloca a estrutura da matriz;
    tMatrix *matrix = (tMatrix*)malloc(sizeof(tMatrix));

    // Verifica se a alocação foi bem sucedida;
    if (matrix == NULL) {
        printf("Erro na alocacao de memoria estrutura matriz!\n");
        exit(1);
    }

    // Atribui os valores de linhas e colunas;
    matrix->rows = rows;
    matrix->cols = cols;

    // Aloca as linhas da matriz;
    matrix->data = (int**)malloc((*matrix).rows * sizeof(int*));
    // Verifica se a alocação foi bem sucedida;
    if ((*matrix).data == NULL) {
        printf("Erro na alocacao das linhas da matriz da estrutura!\n");
        MatrixFree(matrix);
        exit(1);
    }

    // Aloca as colunas da matriz;
    for (m = 0; m < (*matrix).rows; m++) {
        matrix->data[m] = (int*)malloc((*matrix).cols * sizeof(int));
        // Verifica se a alocação foi bem sucedida;
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

    // Lê os valores da matriz;
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

    // Cria a matriz resultado;
    result = MatrixCreate((*matrix1).rows, (*matrix2).cols);

    // Soma as matrizes;
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

    // Cria a matriz resultado;
    result = MatrixCreate((*matrix1).rows, (*matrix2).cols);

    // Subtrai as matrizes;
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

    // Cria a matriz resultado;
    result = MatrixCreate((*matrix1).rows, (*matrix2).cols);

    // Multiplica as matrizes;

    // Define o numero de linhas que a matriz resultante tera;
    while (r1 < (*result).rows) {
        c2 = 0;

        while (c2 < (*result).cols) {
            mult = 0;
            c1 = 0;
            
            // Define o numero de colunas que a matriz resultante tera;
            while (c1 < (*matrix1).cols) {
                /*
                 * Recebe a soma das multiplicacoes que formarao um numero na matriz resultante;
                 * 
                 * Cada elemento "X" de uma linha da primeira mariz e multiplicado por um elemento coluna "Y" da segunda matrix,
                 * e o resultado dessas multiplicacoes e acumulado, para que surja o elemento N (resultado da multiplicacao) na
                 * matriz resultante;
                 */
                mult += (*matrix1).data[r1][c1] * (*matrix2).data[c1][c2];
                c1++;
            }
            /*
             * Recebe o valor resultado da multiplicacao dos elementos das duas matrizes analisadas e o coloca na posicao
             * correta da matriz resultante;
             */
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

    // Cria a matriz resultado;
    result = MatrixCreate((*matrix).cols, (*matrix).rows);

    // Transpõe a matriz;
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

    // Cria a matriz resultado;
    result = MatrixCreate((*matrix).rows, (*matrix).cols);

    // Multiplica a matriz pelo escalar;
    for (r = 0; r < (*result).rows; r++) {
        for (c = 0; c < (*result).cols; c++) {
            result->data[r][c] = (*matrix).data[r][c] * scalar;
        }
    }
    return result;
}

void MatrixPrint(tMatrix *matrix) {
    int r, c;

    // Imprime a matriz;
    for (r = 0; r < (*matrix).rows; r++) {
        printf("|");
        for (c = 0; c < (*matrix).cols; c++) {
            printf("%d", (*matrix).data[r][c]);

            // Verifica se é necessário imprimir um espaço ou uma barra;
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

    // Libera a memória alocada para a matriz;
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