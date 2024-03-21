#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"

int main() {
    tJogo *jogo;

    do {
        // Cria todo o ambiente necessário para a realização do jogo;
        jogo = CriaJogo();
        ComecaJogo(jogo);

    // Enquanto o jojo continuar, o programa continuará rodando;
    // Destroi/desaloca o jogo;
    DestroiJogo(jogo);

    }while (ContinuaJogo() == 1);
    
    return 0;
}