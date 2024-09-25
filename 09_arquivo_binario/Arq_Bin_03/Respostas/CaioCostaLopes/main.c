#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

#define TAM_CAMINHO 1001

int main() {
    const char caminho [TAM_CAMINHO];
    Imagem *imagem;

    scanf ("%s", caminho);
    
    imagem = LerImagem(caminho);

    printf("Numero de bytes lidos: %d\n", ObterNumeroBytesLidos(imagem));
    ImprimirImagem(imagem);

    DestruirImagem(imagem);

    return 0;
}