#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

int main () {
    int option, rows1, cols1, rows2, cols2, scalar, matrix_choiced;
    int encerrar = 0;

    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];

    matrix_read(rows1, cols1, matrix1);

    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];

    int result_sum_sub[rows1][cols1];
    int result_multiply[rows1][cols2];
    int result_transposte1[cols1][rows1];
    int result_transposte2[cols2][rows2];

    matrix_read(rows2, cols2, matrix2);

    while (1) {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: ");

        scanf("%d", &option);
        printf("\n");

        switch(option) {
            case 1:
                if (possible_matrix_sum(rows1, cols1, rows2, cols2)) {
                    matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result_sum_sub);
                    matrix_print(rows1, cols1, result_sum_sub);
                }else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n\n");
                }
                break;
            case 2:
                if (possible_matrix_sub(rows1, cols1, rows2, cols2)) {
                    matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result_sum_sub);
                    matrix_print(rows2, cols2, result_sum_sub);
                }else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n\n");
                }
                break;
            case 3:
                if (possible_matrix_multiply(cols1, rows2)) {
                    matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result_multiply);
                    matrix_print(rows1, cols2, result_multiply);
                }else {
                    printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
                }
                break;
            case 4:
                scanf("%d %d", &scalar, &matrix_choiced);
                if (matrix_choiced == 1) {
                    scalar_multiply(rows1, cols1, matrix1, scalar);
                    matrix_print(rows1, cols1, matrix1);
                }else {
                    if (matrix_choiced == 2) {
                        scalar_multiply(rows2, cols2, matrix2, scalar);
                        matrix_print(rows2, cols2, matrix2);
                    }
                }
                break;
            case 5:                
                transpose_matrix(rows1, cols1, matrix1, result_transposte1);
                transpose_matrix(rows2, cols2, matrix2, result_transposte2);

                matrix_print(cols1, rows1, result_transposte1); 
                matrix_print(cols2, rows2, result_transposte2);
                break;
            case 6:
                encerrar = 1;
        }

        if (encerrar) {
            break;
        }
    }

    return 0;
}