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
    int fib, p, div, resto;
    int f1 = 0, f2 = 1, nPrimoFib = 0;
    int ehPrimo;
    
    while(nPrimoFib < n) {
        fib = f1 + f2;
        f1 = f2;
        f2 = fib;

        if (fib <= 1) {
            ehPrimo = 0;
        }else {
            if (fib <= 3) {
                ehPrimo = 1;
            }else {
                if (fib % 2 == 0 || fib % 3 == 0){
                    ehPrimo = 0;
                }else {
                    ehPrimo = 1;
                    for (int i = 5; i * i <= fib; i += 6) {
                        if (fib % i == 0 || fib % (i + 2) == 0) {
                            ehPrimo = 0;
                            break;
                        }
                    }
                }
            }
        }
        
        if (ehPrimo) {
            nPrimoFib += 1;
        }
    }
    resto = (fib % 101);

    jogo->valorSurpresa = round((((float)resto / (float)100) * ((float)(*jogo).maxIntervalo - (float)(*jogo).minIntervalo) + (float)(*jogo).minIntervalo));
}

void CalculaNumeroTentativas(tJogo *jogo) {
    jogo->qtdTentativas = (int)((log2((*jogo).maxIntervalo - ((*jogo).minIntervalo + 1))) + 1);

    //printf("\nNumero de tentativas: %d\n", (*jogo).qtdTentativas);
}

int ProcessaTentativas(tJogo *jogo) {
    int t, tentativa;

    printf("\nVoce tem direito a %d tentativas", (*jogo).qtdTentativas);

    for (t = 1; t <= (*jogo).qtdTentativas; t++) {
        printf("\nTentativa %d: ", t);
        scanf("%d", &tentativa);

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
    printf("Voce perdeu! O numero escolhido foi %d", (*jogo).valorSurpresa);

    return 0;
}

void DestroiJogo(tJogo *jogo) {
    free(jogo);
    jogo = NULL;
}