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

    for (v = 0; v < TAM_PADRAO; v++) {
        vetor[v] = '_';
    }
    vetor = realloc(vetor, TAM_PADRAO + 1);
    vetor[TAM_PADRAO] = '\0';

    return vetor;
}

char *AumentaTamanhoVetor(char *vetor, int tamanhoantigo) {
    int novoTamanho = tamanhoantigo + TAM_PADRAO;
    vetor = realloc(vetor, novoTamanho * sizeof(char));
    int v;

    if (vetor == NULL) {
        printf("Erro na alocacao!");
        exit(1);
    }

    for (v = tamanhoantigo; v < novoTamanho; v++) {
        vetor[v] = '_';
    }
    vetor = realloc(vetor, novoTamanho + 1);
    vetor[novoTamanho] = '\0';

    return vetor;
}

char *LeVetor(char *vetor, int *tamanho) {
    int c = 0;
    char letra = '\0';

    while (1) {
        scanf("%c", &letra);

        if (letra == '\n') {
            break;
        }

        if (c >= *tamanho) {
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho += TAM_PADRAO;
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