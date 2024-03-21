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

    // Enquanto o jojo continuar, o o programa continuará rodando;
    }while (ContinuaJogo() == 1);
    
    // Destroi/desaloca o jogo;
    DestroiJogo(jogo);
    
    return 0;
}