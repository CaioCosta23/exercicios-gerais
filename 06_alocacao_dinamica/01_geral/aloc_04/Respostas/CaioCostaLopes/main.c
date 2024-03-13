#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_char2.h"

int main() {
    
    char *vetor;
    int tamanho;

    tamanho = TAM_PADRAO;

    vetor = CriaVetorTamPadrao();
    vetor = LeVetor(vetor, &tamanho);
    ImprimeString(vetor);
    LiberaVetor(vetor);
    
    return 0;
}