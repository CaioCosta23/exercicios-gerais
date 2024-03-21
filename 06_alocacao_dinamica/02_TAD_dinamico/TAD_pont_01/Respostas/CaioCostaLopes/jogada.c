#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"

tJogada *CriaJogada() {
    // Aloca dinâmicamente a jogada;
    tJogada *jogada = (tJogada *) malloc(sizeof(tJogada));

    // Verifica se a jogada foi alocada corretamente (caso contrário, o programa se encerra);
     if (jogada == NULL) {
        printf("Erro na alocacao da jogada!");
        exit(1);
    }
    return jogada;
}

void LeJogada(tJogada *jogada) {

    printf("Digite uma posicao (x e y):\n");

    // Se foram lidas duas informações (dois numeros inteiros - representando x e y respectivamente do tabuleiro) a jogada é bem sucedida;
    if (scanf("%d %d", &(*jogada).x, &(*jogada).y) == 2) {
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
    free(jogada);
}