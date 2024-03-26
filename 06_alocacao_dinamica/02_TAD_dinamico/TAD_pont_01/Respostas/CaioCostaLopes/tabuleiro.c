#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"

#define VAZIO '-'

tTabuleiro *CriaTabuleiro() {
    int m, l, c;
    // Aloca a estrutura do tabuleiro;
    tTabuleiro *tabuleiro = (tTabuleiro *) malloc(sizeof(tTabuleiro));

    // Se a alocação falhar (ou seja, o ponteiro apontar para uma área nula, então hove erro na alocação e o programa é encerrado imediatamente);
    if (tabuleiro == NULL) {
        printf("Erro na alocacao da estrutura do tabuleiro!");
        exit(1);
    }
    // Aloca as linhas da matriz que formará o tabuleiro;
    tabuleiro->posicoes = (char **)malloc(TAM_TABULEIRO * sizeof(char*));

    // Aloca cada coluna da matriz que formará o tabuleiro;
    for (m = 0; m < TAM_TABULEIRO; m++) {
        tabuleiro->posicoes[m] = (char*)malloc(TAM_TABULEIRO * sizeof(char));
    }

    // A informação referente a uma peça vazia (na estrutura) recebe seu respectivo caracter de representação (no tabuleiro);
    tabuleiro->pecaVazio = VAZIO;

    // Marca todas as posições do tabuleiro como "vazio";
    for (l = 0; l < TAM_TABULEIRO; l++) {
        for (c = 0; c < TAM_TABULEIRO; c++) {
            tabuleiro->posicoes[l][c] = (*tabuleiro).pecaVazio;

        }
    }
    // Jogador 1 será representado pelo caractere "X" no tabuleiro;
    tabuleiro->peca1 = 'X';
    // Jogador 2 será representado pelo caractere "0" no tabuleiro;
    tabuleiro->peca2 = '0';

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro) {
    int l, c;

    // Verifica se  uma posição está com o caracter que representa o espaço vazio;
    for (l = 0; l < TAM_TABULEIRO; l++) {
        for (c = 0; c < TAM_TABULEIRO; c++) {
            // Se sim, ele retorna verdadeiro (valores diferentes de 0 - neste caso, 1);
            if ((*tabuleiro).posicoes[l][c] == (*tabuleiro).pecaVazio) {
                return 1;
            }
        }
    }
    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y) {
    // Verifica se a posição está dentro do tabuleiro (se X e Y são menores que os valores das posições do tabuleiro);
   return (((x >= 0) && (x < TAM_TABULEIRO)) && ((y >= 0) && (y < TAM_TABULEIRO)));
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y, int peca) {
    char marcacao;

    // Verifica se a peça recebida é igual a peça do jogador 1 (peça 1) ou do jogador 2 (peça 2)
    if (peca == PECA_1) {
        marcacao = (*tabuleiro).peca1;
    }else {
        marcacao = (*tabuleiro).peca2;
    }
    
    // Verifica se a posição na qual se deseja marcar está vazia, ou se ela já está marcada (com alguma peça);
    return ((*tabuleiro).posicoes[y][x] == marcacao);

}

int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y) {
    return ((*tabuleiro).posicoes[y][x] == (*tabuleiro).pecaVazio);
}

void MarcaPosicaoTabuleiro (tTabuleiro *tabuleiro, int peca, int x, int y) {
    char marcacao;

    /* Se a peça recebida for igual a do jogador 1, então o tabuleiro será marcado na respectiva coordenada 
     * (posição (y,x) - Valores estão invertidos devido a configuração do exercício) com peça do jogador 1, 
     * caso contrário, o mesmo processo será feito com o jogador 2;
    */
    if (peca == PECA_1) {
        marcacao = (*tabuleiro).peca1;
    }else {
        marcacao = (*tabuleiro).peca2;
    }
    (*tabuleiro).posicoes[y][x] = marcacao;
}


void ImprimeTabuleiro(tTabuleiro *tabuleiro) {
    int l, c;

    for (l = 0; l < TAM_TABULEIRO; l++) {
        for (c = 0; c < TAM_TABULEIRO; c++) {
            printf("%c", (*tabuleiro).posicoes[l][c]);
        }
        printf("\n");
    }
}

void DestroiTabuleiro(tTabuleiro *tabuleiro) {
    int m;

    for (m = 0; m < TAM_TABULEIRO; m++) {
        free((*tabuleiro).posicoes[m]);
    }
    free((*tabuleiro).posicoes);
    free(tabuleiro);
}