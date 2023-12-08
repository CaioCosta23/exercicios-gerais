#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

int main () {
    int rows, cols, op;
    tMatrix matrix1, matrix2;

    scanf("%d %d", &rows, &cols);
    matrix1 = MatrixCreate(rows, cols);

    scanf("%d %d", &rows, &cols);
    matrix2 = MatrixCreate(rows, cols);

    while(1) {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar programa\n");

        printf("Opcao escolhida: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                if (PossibleMatrixSum) {
                    matrix1 = MatrixAdd(matrix1, matrix2);
                    MatrixPrint(matrix1);
                }else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
            case 2:
                if (PossibleMatrixSub) {
                    matrix1 = MatrixSub(matrix1, matrix2);
                    MatrixPrint(matrix1);
                }else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
        }
    }

    return 0;
}