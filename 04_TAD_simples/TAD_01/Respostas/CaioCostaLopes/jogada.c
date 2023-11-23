#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"

tJogada LeJogada() {
    tJogada jogada;

    scanf("%d %d", &jogada.x, &jogada.y);

    return jogada;
}

int ObtemJogadaX(tJogada jogada) {
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada) {
    return jogada.y;
}

int FoiJogadaBemSucedida (tJogada jogada) {
    return jogada.sucesso;
}