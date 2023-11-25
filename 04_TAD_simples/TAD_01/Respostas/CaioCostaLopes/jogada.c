#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "jogada.h"
#include "tabuleiro.h"
#include "jogo.h"

tJogada LeJogada() {
    tJogada jogada;

    scanf("%d %d", &jogada.y, &jogada.x);

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
    return EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada));
}