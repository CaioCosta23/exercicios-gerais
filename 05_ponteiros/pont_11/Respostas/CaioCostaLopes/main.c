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
    CalculatoraCallback calculadora;
    char acao;
    float num1 = 0, num2 = 0;

    do {
        scanf("%c\n", &acao);
        scanf("%f %f", &num1, &num2);

        if (acao == 'a'){
            calculadora = Soma;
            printf("%.2f + %.2f = %.2f", num1, num2, Calcular(num1, num2, calculadora));
        }
        if (acao == 's'){
            calculadora = Subtracao;
            printf("%.2f - %.2f = %.2f", num1, num2, Calcular(num1, num2, calculadora));
        }
        if (acao == 'm'){
            calculadora = Multiplicacao;
            printf("%.2f + %.2f = %.2f", num1, num2, Calcular(num1, num2, calculadora));
        }
        if (acao == 'd'){
            calculadora = Divisao;
            printf("%.2f + %.2f = %.2f", num1, num2, Calcular(num1, num2, calculadora));
        }
    } while(acao != 'f');

    return 0;
}