#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

int Soma(int num1, int num2) {
    return num1 + num2;
}

int Multiplicacao(int num1, int num2) {
    return num1 * num2;
}

int main() {
    Vetor vetor;

    LeVetor(&vetor);
    
    printf("Soma: %d\n", AplicarOperacaoVetor(&vetor, Soma));
    printf("Produto: %d\n", AplicarOperacaoVetor(&vetor, Multiplicacao));

    return 0;
}