#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int **CriaMatriz(int linhas, int colunas) {
    int (*matriz)[linhas] = malloc(linhas * colunas * sizeof(int));

    if (*matriz == NULL) {
        printf("Erro de alocacao!");
        exit(1);
    }
}

void LiberaMatriz(int **matriz, int linhas) {
    free(matriz);
}

void LeMatriz(int **matriz, int linhas, int colunas) {
    int l, c;

    for (l = 0; l < linhas; l++) {
        for (c = 0; c < colunas; c++) {
            scanf("%d", &matriz[l][c]);
        }
    }
}

void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas) {
    int l, c;

    for (l = 0; l < linhas; l++) {
        for (c = 0; c < colunas; c++) {
            printf("%d ", matriz[c][l]);
        }
        printf("\n");
    }
}