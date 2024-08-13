#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main() {
    tJogo *jogo;
    int n, min, max;
    char resposta;
    int fimDeJogo = 0;

    while (1) {
        printf("Jogo de adivnhação\n");
        jogo = CriaJogo();
        
        while (1) {
            printf("Forneca um numero no intervalo entre 1 e 10000: ");
            scanf("%d\n", &n);
            
            if ((n < 1) || (n > 10000)) {
                continue;
            }
            
            printf("Forneca um intervalo de numeros naturais: ");
            scanf("%d %d\n", &min, &max);

            if ((min < max) && (max < 1000000000)) {
                DefineMaximo(jogo, max);
                DefineMinimo(jogo, min);

                break;
            }else {
                if (min >= max) {
                    printf("O primeiro numero do intervalo deve ser inferior ao segundo\n");
                }
                if (max >= 1000000000) {
                    printf("O segundo numero do intervalo deve ser menor que 1.000.000.000\n");
                }
            }
        }
        CalculaValorASerAdivinhado(jogo, n);
        CalculaNumeroTentativas(jogo);

        while(1) {
            if ((ProcessaTentativas(jogo) == 1)) {
                break;
            }
        }

        while(1) {
            printf("Deseja continuar a jogar (s/n):\n");
            scanf("%c\n", &resposta);

            if ((resposta == 's') || (resposta == 'n')) {
                if (resposta == 's') {
                    break;
                }else {
                    fimDeJogo = 1;
                    break;
                }
            }
        }
        if (fimDeJogo) {
            DestroiJogo(jogo);
            break;
        }
    }

    return 0;
}