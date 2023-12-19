#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

float Soma(float num1, float num2) {
    return num1 + num2;
}

float Subtracao(float num1, float num2) {
    return num1 - num2;
}

float Multiplicacao(float num1, float num2) {
    return num1 * num2;
}

float Divisao(float num1, float num2) {
    return num1 / num2;
}

int main() {
    char acao;
    float num1 = 0, num2 = 0;

    do {
        scanf("%c\n", &acao);
        scanf("%f %f", &num1, &num2);

        if (acao == 'a'){
            printf("%.2f + %.2f = %.2f\n", num1, num2, Calcular(num1, num2, Soma));
        }
        if (acao == 's'){
            printf("%.2f - %.2f = %.2f\n", num1, num2, Calcular(num1, num2, Subtracao));
        }
        if (acao == 'm'){
            printf("%.2f x %.2f = %.2f\n", num1, num2, Calcular(num1, num2, Multiplicacao));
        }
        if (acao == 'd'){
            printf("%.2f / %.2f = %.2f\n", num1, num2, Calcular(num1, num2, Divisao));
        }
    } while(acao != 'f');

    return 0;
}