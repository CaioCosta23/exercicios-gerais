#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

int main() {
    float x, y, raio, xPontoNovo, yPontoNovo;
    tCirculo circulo;
    tPonto novoPonto;

    scanf("%f %f %f %f %f", &x, &y, &raio, &xPontoNovo, &yPontoNovo);

    circulo = Circulo_Cria(x, y, raio);
    novoPonto = Pto_Cria(xPontoNovo, yPontoNovo);

    printf("%d", Circulo_Interior(circulo, novoPonto));

    Pto_Apaga(novoPonto);
    Circulo_Apaga(circulo);

    return 0;
}