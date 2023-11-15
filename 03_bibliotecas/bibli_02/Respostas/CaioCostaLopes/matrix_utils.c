#include "matrix_utils.h"
#include <stdio.h>

void matrix_read(int rows, int cols, int matrix[rows][cols]) {
    int r, c;

    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            scanf("%d", &matrix[r][c]);
        }
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols]) {
    int r, c;

    for (r = 0; r < rows; r++) {
        printf("|");
        for (c = 0; c < cols; c++) {
            printf("%d", matrix[r][c]);

            if (c < (cols - 1)) {
                printf(" ");
            }
            if(c == cols - 1) {
                printf("|\n");
            }
        }
    }
    printf("\n");
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2) {
    /**
     * @brief Retorno logico da funcao;
     * 
     * Se a expressao for falsa, retorna 0 (valor inteiro que representa o valor logico falso), caso contrario,
     * retorna qualquer outro valor diferente de 0 (que representa o valor logico verdadeiro);
     */
    return((rows1 == rows2) && (cols1 == cols2));
}

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2) {
    return((rows1 == rows2) && (cols1 == cols2));
}

int possible_matrix_multiply(int cols1, int rows2) {
    return(cols1 == rows2);
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]) {
    int r, c;

    for (r = 0; r < rows1; r++) {
        for (c = 0; c < cols1; c++) {
            result[r][c] = matrix1[r][c] + matrix2[r][c];
        }
    }
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]) {
    int r, c;

    for (r = 0; r < rows1; r++) {
        for (c = 0; c < cols1; c++) {
            result[r][c] = matrix1[r][c] - matrix2[r][c];
        }
    }
}

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]) {
    int r1, c1, c2, mult;

    r1 = 0;

    // Define o numero de linhas que a matriz resultante tera;
    while(r1 < rows1) {
        c2 = 0;

        // Define o numero de colunas que a matriz resultante tera;
        while(c2 < cols2) {
            mult = 0;
            c1 = 0;

            // O numero de colunas da primeira matriz e sempre o numero de linhas da segunda, podemos usar qualquer uma como base;
            while(c1 < cols1) {
                /**
                 * @brief Recebe a soma das multiplicacoes que formarao um numero na matriz resultante;
                 * 
                 * Cada elemento "X" de uma linha da primeira mariz e multiplicado por um elemento coluna "Y" da segunda matrix,
                 * e o resultado dessas multiplicacoes e acumulado, para que surja o elemento N (resultado da multiplicacao) na
                 * matriz resultante;
                 */
                mult += matrix1[r1][c1] * matrix2[c1][c2];
                c1++;
            }
            /**
             * @brief Recebe o valor resultado da multiplicacao dos elementos das duas matrizes analisadas e o coloca na posicao
             * correta da matriz resultante;
             */
            result[r1][c2] = mult;

            c2++;
        }
        r1++;
    }
}

void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]) {
    int r, c;

    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            result[c][r] = matrix[r][c];
        }
    }
    
}

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar) {
    int r, c;

    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            matrix[r][c] = scalar * matrix[r][c];
        }
    }
}