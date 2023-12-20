#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {
    int tamanho;
    int *vetor;
    float media;

    scanf("%d", &tamanho);

    vetor = CriaVetor(tamanho);
    LeVetor(vetor, tamanho);
    
    media = CalculaMedia(vetor, tamanho);
    printf("%.2f", media);

    LiberaVetor(vetor);

    return 0;
}