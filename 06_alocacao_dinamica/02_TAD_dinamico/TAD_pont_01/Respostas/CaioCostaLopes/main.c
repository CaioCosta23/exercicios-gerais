#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"

int main() {
    tJogo *jogo;
    //tJogo *jogo = (tJogo *) malloc(sizeof(tJogo));

    do {
        jogo = CriaJogo();
        ComecaJogo(jogo);

    }while (ContinuaJogo() == 1);
    
    DestroiJogo(jogo);
    
    return 0;
}