#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void LeIntervalo(int *m, int *n) {
    scanf("%d %d", *m, *n);
}

int EhPrimo(int n) {
    return (n % 2 == 0);
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior) {
    int i;
    int contPrimos = 0;

    for (i = m; i <= n; i++) {
        if (EhPrimo(i)) {
            if (contPrimos == 0) {
                *maior = i;
                *menor = i;
            }else {
                if ((*maior) < i) {
                    *maior = i;
                }
                if ((*menor) < i) {
                    *menor = i;
                }
            }
        }
    }
}