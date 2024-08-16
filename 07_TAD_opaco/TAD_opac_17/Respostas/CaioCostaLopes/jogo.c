#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

struct Jogo {
    int minIntervalo;
    int maxIntervalo;
    int qtdTentativas;
    int valorSurpresa;
};

tJogo *CriaJogo() {
    tJogo *jogo = (tJogo*)malloc(sizeof(tJogo));

    if (jogo == NULL) {
        printf("Erro na alocacao de memoria do jogo");
        return jogo;
    }

    jogo->minIntervalo = 0;
    jogo->maxIntervalo = 0;
    jogo->qtdTentativas = 0;
    jogo->valorSurpresa = -1;

    return jogo;
}


void DefineMinimo(tJogo *jogo, int min) {
    jogo->minIntervalo = min;
}

void DefineMaximo(tJogo *jogo, int max) {
    jogo->maxIntervalo = max;
}

void CalculaValorASerAdivinhado(tJogo *jogo, int n) {
    int fib, t, resto;
    int f1 = 0, f2 = 1;

    for (t = 2; t <= n; t++) {
        fib = f1 + f2;
        f1 = f2;
        f2 = fib;
    }

    resto = (int)(fib % 101);

    jogo->valorSurpresa = ((resto / 100) * ((*jogo).maxIntervalo - (*jogo).minIntervalo + 1) + (*jogo).minIntervalo);
}

void CalculaNumeroTentativas(tJogo *jogo) {
    jogo->qtdTentativas = (int)((log2((*jogo).maxIntervalo - ((*jogo).minIntervalo + 1))) + 1);
}

int ProcessaTentativas(tJogo *jogo) {
    int t, tentativa;

    for (t = 1; t <= (*jogo).qtdTentativas; t++) {
        printf("\nTentativa %d: ", t);
        scanf("%d\n", &tentativa);

        if (tentativa == (*jogo).valorSurpresa) {
            printf("\nParabens, voce ganhou!");
            return 1;
        }else {
            if (tentativa < (*jogo).valorSurpresa) {
                printf("\nBaixa");
            }else {
                printf("\nAlta");
            }
        }
    }
    return 0;
}

void DestroiJogo(tJogo *jogo) {
    free(jogo);
    jogo = NULL;
}