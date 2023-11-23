#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"

tJogada LeJogada() {
    tJogada jogada;

    scanf("%d %d", &jogada.x, &jogada.y);

    jogada.sucesso = 0;

    return jogada;
}

int ObtemJogadaX(tJogada jogada) {
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada) {
    return jogada.y;
}

int FoiJogadaBemSucedida (tJogada jogada) {
    jogada.sucesso = 1;

    return jogada.sucesso;
}