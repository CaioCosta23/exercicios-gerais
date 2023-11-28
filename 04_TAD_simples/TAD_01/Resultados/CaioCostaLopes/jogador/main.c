#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main()
{
    tJogo jogo;

    do
    {
        jogo = CriaJogo();
        ComecaJogo(jogo);

    } while (ContinuaJogo() == 1);

    return 0;
}