#include <stdio.h>
#include <stdlib.h>
#include "utils_char2.h"

#define VAZIO '_'

char *CriaVetorTamPadrao() {
    char *vetor = malloc(TAM_PADRAO * sizeof(char));
    int v;

    if (vetor == NULL) {
        printf("Erro na alocacao!");
        exit(1);
    }

    for (v = 0; v < TAM_PADRAO - 1; v++) {
        vetor[v] = '_';
    }
    vetor[TAM_PADRAO] = '\0';

    return vetor;

}

char *AumentaTamanhoVetor(char *vetor, int tamanhoantigo) {
    int novoTamanho = tamanhoantigo + TAM_PADRAO;
    vetor = realloc(vetor, novoTamanho);
    int v;

    if (vetor == NULL) {
        printf("Erro na alocacao!");
        exit(1);
    }

    for (v = 0; v < novoTamanho - 1; v++) {
        vetor[v] = '_';
    }
    vetor[novoTamanho] = '\0';

    return vetor;

}

char *LeVetor(char *vetor, int *tamanho) {
    int c = 0;
    char letra = '\0';

    while (c < *tamanho) {
        scanf("%c", &letra);

        if (letra == '\n') {
            break;
        }

        vetor[c] = letra;
        c++;
    }
    return vetor;
}

void ImprimeString(char *vetor) {
    printf("%s\n", vetor);
}

void LiberaVetor(char *vetor) {
    free(vetor);
}