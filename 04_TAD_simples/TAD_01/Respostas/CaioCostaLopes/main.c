#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main() {
    tJogo jogo;

    do {
        ComecaJogo(jogo);
    }while (ContinuaJogo());

    return 0;
}