#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"

int main() {
    int numeroIntervalos;
    Imagem *imagem;
    Histograma *histograma;

    scanf("%d\n", &numeroIntervalos);

    imagem = LerImagem();

    histograma = CalcularHistograma(imagem, numeroIntervalos);
    MostrarHistograma(histograma);
    DestruirHistograma(histograma);
    DestruirImagem(imagem);

    return 0;
}