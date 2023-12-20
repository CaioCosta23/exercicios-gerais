#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

int main() {
    int tamanho;
    char *vetor;

    scanf("%d\n", &tamanho);

    vetor = CriaVetor(tamanho);
    
    LeVetor(vetor, tamanho);
    ImprimeString(vetor, tamanho);
    LiberaVetor(vetor);
}