#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    Ponto ponto_1, ponto_2;
    float x1, y1, x2, y2;

    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    ponto_1 = pto_cria(x1, y1);
    ponto_2 = pto_cria(x2, y2);

    printf("%g", pto_distancia(ponto_1, ponto_2));
    
    return 0;
}