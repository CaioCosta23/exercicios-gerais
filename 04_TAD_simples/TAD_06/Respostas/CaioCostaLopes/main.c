#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

int main () {
    int rows, cols, op, scalar, opMatrix;
    tMatrix matrix1, matrix2;
    int encerrar = 0;

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
                break;
            case 2:
                if (PossibleMatrixSub) {
                    matrix1 = MatrixSub(matrix1, matrix2);
                    MatrixPrint(matrix1);
                }else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;
            case 3:
                if (PossibleMatrixMultiply(matrix1, matrix2)) {
                    matrix1 = MatrixMultiply(matrix1, matrix2);
                    MatrixPrint(matrix1);
                }else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;
            case 4:
                scanf("%d %d", &scalar, &opMatrix);
                if (opMatrix == 1) {
                    MatrixMultiplyByScalar(matrix1, scalar);
                    MatrixPrint(matrix1);
                }else {
                    if (opMatrix == 2) {
                        MatrixMultiplyByScalar(matrix2, scalar);
                        MatrixPrint(matrix2);
                    }
                }
                break;
            case 5:
                TransposteMatrix(matrix1);
                MatrixPrint(matrix1);
                TransposteMatrix(matrix2);
                MatrixPrint(matrix2);
                break;
            case 6:
                encerrar = 1;
                break;
        }
        if (encerrar) {
            break;
        }
    }

    return 0;
}