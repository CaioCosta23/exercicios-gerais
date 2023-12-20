#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

int main() {
    int tamanho, c;
    char *vetor;

    scanf("%d\n", &tamanho);

    vetor = CriaVetor(tamanho);

    ImprimeString(vetor, tamanho);
    LeVetor(vetor, tamanho);
    ImprimeString(vetor, tamanho);
    LiberaVetor(vetor);
}