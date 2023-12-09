#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

int main () {
    int rows, cols, op, scalar, opMatrix;
    tMatrix matrix1, matrix2, sumMatrix, subMatrix, multMatrix, newMatrix1, newMatrix2;
    int encerrar = 0;

    scanf("%d %d", &rows, &cols);
    matrix1 = MatrixCreate(rows, cols);
    matrix1 = MatrixRead(matrix1);

    scanf("%d %d", &rows, &cols);
    matrix2 = MatrixCreate(rows, cols);
    matrix2 = MatrixRead(matrix2);

    while(1) {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");

        printf("Opcao escolhida: ");
        scanf("%d", &op);
        printf("\n");

        switch (op) {
            case 1:
                if (PossibleMatrixSum(matrix1, matrix2)) {
                    sumMatrix = MatrixAdd(matrix1, matrix2);
                    MatrixPrint(sumMatrix);
                }else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;
            case 2:
                if (PossibleMatrixSub(matrix1, matrix2)) {
                    subMatrix = MatrixSub(matrix1, matrix2);
                    MatrixPrint(subMatrix);
                }else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;
            case 3:
                if (PossibleMatrixMultiply(matrix1, matrix2)) {
                    multMatrix = MatrixMultiply(matrix1, matrix2);
                    MatrixPrint(multMatrix);
                }else {
                    printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
                }
                break;
            case 4:
                scanf("%d %d", &scalar, &opMatrix);
                if (opMatrix == 1) {
                    matrix1 = MatrixMultiplyByScalar(matrix1, scalar);
                    MatrixPrint(matrix1);
                }else {
                    if (opMatrix == 2) {
                        matrix2 = MatrixMultiplyByScalar(matrix2, scalar);
                        MatrixPrint(matrix2);
                    }
                }
                break;
            case 5:
                newMatrix1 = TransposeMatrix(matrix1);
                MatrixPrint(newMatrix1);
                newMatrix2 = TransposeMatrix(matrix2);
                MatrixPrint(newMatrix2);
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