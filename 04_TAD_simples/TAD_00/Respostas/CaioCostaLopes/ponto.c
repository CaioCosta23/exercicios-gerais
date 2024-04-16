#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include <math.h>

Ponto pto_cria (float x, float y) {
    Ponto ponto;
    
    ponto = pto_atribui_x(ponto, x);
    ponto = pto_atribui_y(ponto, y);

    return ponto;
}

float pto_acessa_x(Ponto p) {
    return p.x;
}

float pto_acessa_y(Ponto p) {
    return p.y;
}

Ponto pto_atribui_x(Ponto p, float x) {
    p.x = x;
    
    return p;
}

Ponto pto_atribui_y(Ponto p, float y) {
    p.y = y;

    return p;
}

float pto_distancia (Ponto p1, Ponto p2) {
    /* Fórmula para o cálculo da distância entre dois pontos:
     * d = (((x2 - x1) ^ 2) + ((y2 - y1) ^ 2)) ^ (1/2)
     * 
     * Cálculo 1: x2 - x1 (e o seu resultado ao quadrado);
     * Cálculo 2: y2 - y1 (e o seu resultado ao quadrado);
     * Cálculo 3: Cálculo 1 + Cálculo 2;
     * Cálculo 4: raiz quadrada (do Cálculo 3);
    */
    return (sqrt((pow((pto_acessa_x(p1) - pto_acessa_x(p2)), 2)) + 
            (pow((pto_acessa_y(p1) - p2.y), 2))));
}