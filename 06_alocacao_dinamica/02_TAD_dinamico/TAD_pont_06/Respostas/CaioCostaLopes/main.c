#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

int main() {
    int rows, cols, op, scalar, opMatrix;
    // Cria ponteiros do tipo "tMatrix" e inicializa-os com NULL; 
    tMatrix *matrix1 = NULL, *matrix2 = NULL, 
    *sumMatrix = NULL, *subMatrix = NULL, *multMatrix = NULL, 
    *tempScalar = NULL, *newMatrix1 = NULL, *newMatrix2 = NULL;
    int encerrar = 0;

    // Lê o número de linhas e colunas, cria (e aloca dinâmicamente a matriz) e lê os seus dados;
    scanf("%d %d", &rows, &cols);
    matrix1 = MatrixCreate(rows, cols);
    MatrixRead(matrix1);

    // Lê o número de linhas e colunas, cria (e aloca dinâmicamente a matriz) e lê os seus dados;
    scanf("%d %d", &rows, &cols);
    matrix2 = MatrixCreate(rows, cols);
    MatrixRead(matrix2);

    while(1) {
        // Menu de opções;
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");

        // Lê a opção escolhida;
        printf("Opcao escolhida: ");
        scanf("%d", &op);
        printf("\n");

        switch(op) {
            case 1:
            // Verifica se é possível somar as matrizes;
                if (PossibleMatrixSum(matrix1, matrix2)) {
                    // Soma as matrizes e retorna um ponteiro (alocado dinâmicamente) para a matriz resultante;
                    sumMatrix = MatrixAdd(matrix1, matrix2);
                    // Imprime a matriz resultante;
                    MatrixPrint(sumMatrix);
                    // Libera a memória alocada para a matriz resultante;
                    MatrixFree(sumMatrix);
                }else {
                    // Caso não seja possível somar as matrizes, imprime uma mensagem de erro;
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;
            case 2:
                // Verifica se é possível subtrair as matrizes;
                if (PossibleMatrixSub(matrix1, matrix2)) {
                    // Subtrai as matrizes e retorna um ponteiro (alocado dinâmicamente) para a matriz resultante;
                    subMatrix = MatrixSub(matrix1, matrix2);
                    // Imprime a matriz resultante;
                    MatrixPrint(subMatrix);
                    // Libera a memória alocada para a matriz resultante;
                    MatrixFree(subMatrix);
                }else {
                    // Caso não seja possível subtrair as matrizes, imprime uma mensagem de erro;
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;
            case 3:
                // Verifica se é possível multiplicar as matrizes;
                if (PossibleMatrixMultiply(matrix1, matrix2)) {
                    // Multiplica as matrizes e retorna um ponteiro (alocado dinâmicamente) para a matriz resultante;
                    multMatrix = MatrixMultiply(matrix1, matrix2);
                    // Imprime a matriz resultante;
                    MatrixPrint(multMatrix);
                    // Libera a memória alocada para a matriz resultante;
                    MatrixFree(multMatrix);
                }else {
                    // Caso não seja possível multiplicar as matrizes, imprime uma mensagem de erro;
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;
            case 4:
            // Lê o escalar e a matriz que será multiplicada;
                scanf("%d %d", &scalar, &opMatrix);
                
                // Verifica se a matriz 1 será multiplicada;
                if (opMatrix == 1) {
                    // Multiplica a matriz 1 pelo escalar e retorna um ponteiro (alocado dinâmicamente) para a matriz resultante;
                    tempScalar = MatrixMultiplyByScalar(matrix1, scalar);
                    // Imprime a matriz resultante;
                    MatrixPrint(tempScalar);
                    // Libera a memória alocada para a matriz resultante;
                    MatrixFree(matrix1);
                    // Atribui o ponteiro da matriz resultante à matriz 1;
                    matrix1 = tempScalar;
                }else {
                    // Verifica se a matriz 2 será multiplicada;
                    if (opMatrix == 2) {
                        // Multiplica a matriz 2 pelo escalar e retorna um ponteiro (alocado dinâmicamente) para a matriz resultante;
                        tempScalar = MatrixMultiplyByScalar(matrix2, scalar);
                        // Imprime a matriz resultante;
                        MatrixPrint(tempScalar);
                        // Libera a memória alocada para a matriz resultante;
                        MatrixFree(matrix2);
                        // Atribui o ponteiro da matriz resultante à matriz 2;
                        matrix2 = tempScalar;
                    }
                }
                break;
            case 5:
                // Calcula a transposta da matriz 1 e retorna um ponteiro (alocado dinâmicamente) para a matriz resultante;
                newMatrix1 = TransposeMatrix(matrix1);
                // Imprime a matriz resultante;
                MatrixPrint(newMatrix1);
                // Libera a memória alocada para a matriz resultante;
                MatrixFree(newMatrix1);
                // Calcula a transposta da matriz 2 e retorna um ponteiro (alocado dinâmicamente) para a matriz resultante;
                newMatrix2 = TransposeMatrix(matrix2);
                // Imprime a matriz resultante;
                MatrixPrint(newMatrix2);
                // Libera a memória alocada para a matriz resultante;
                MatrixFree(newMatrix2);
                break;
            case 6:
                // Indica que o programa deve ser encerrado;
                encerrar = 1;
                break;
        }
        // Caso o programa deva ser encerrado, sai do loop;
        if (encerrar) {
            break;
        }
    }
    // Libera a memória alocada para as matrizes;
    MatrixFree(matrix1);
    MatrixFree(matrix2);

    return 0;
}