#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int **CriaMatriz(int linhas, int colunas) {
    int l;

    int **matriz = malloc(linhas * sizeof(int*));

    for (l = 0; l < linhas; l++) {
        matriz[l] = malloc(colunas * sizeof(int));
        
        if (matriz[l] == NULL) {
            printf("Erro de alocacao!");
            exit(1);
        }
    }
    return matriz;
}

void LiberaMatriz(int **matriz, int linhas) {
    int l;

    for(l = 0; l < linhas; l++) {
        free(matriz[l]);
    }
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

    for (c = 0; c < colunas; c++) {
        for (l = 0; l < linhas; l++) {
            printf("%d ", matriz[l][c]);
        }
        printf("\n");
    }
}