#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"

struct Jogada {
    int x;
    int y;
    int sucesso;
};

tJogada *CriaJogada() {
    tJogada *jogada = (tJogada*)malloc(sizeof(tJogada));

    if (jogada == NULL) {
        printf("Erro na alocacao da jogada!\n");
        return jogada;
    }
    
    jogada->x = -1;
    jogada->y = -1;
    jogada->sucesso = -1;

    return jogada;
}

void LeJogada(tJogada *jogada) {
    printf("Digite uma posicao (x e y):\n");

    if (scanf("%d %d", &jogada->x, &jogada->y) == 2) {
        jogada->sucesso = 1;
    }else {
        jogada->sucesso = 0;
    }
}

int ObtemJogadaX(tJogada *jogada) {
    return (*jogada).x;
}

int ObtemJogadaY(tJogada *jogada) {
    return (*jogada).y;
}

int FoiJogadaBemSucedida(tJogada *jogada) {
    return (*jogada).sucesso;
}

void DestroiJogada(tJogada *jogada) {
    if (jogada != NULL) {
        free(jogada);
        jogada = NULL;
    }
}