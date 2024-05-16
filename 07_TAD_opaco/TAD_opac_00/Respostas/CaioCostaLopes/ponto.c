#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto {
    float x, y;
};

tPonto Pto_Cria(float x, float y) {
    tPonto ponto = (tPonto)malloc(sizeof(tPonto));

    if (ponto == NULL) {
        printf("Erro na alocacao de memoria do ponto!\n");
        return ponto;
    }

    Pto_Atribui_x(ponto, x);
    Pto_Atribui_y(ponto, y);

    return ponto;
}

float Pto_Acessa_x(tPonto p) {
    return (*p).x;
}

float Pto_Acessa_y(tPonto p) {
    return (*p).y;
}

void Pto_Atribui_x(tPonto p, float x) {
    p->x = x;
}

void Pto_Atribui_y(tPonto p, float y) {
    p->y = y;
}

float Pto_Distancia(tPonto p1, tPonto p2) {
    return (sqrt((pow((Pto_Acessa_y(p2) - Pto_Acessa_y(p1)), 2)) + (pow((Pto_Acessa_x(p2) - Pto_Acessa_x(p1)), 2))));
}

void Pto_Apaga(tPonto p) {
    if (p != NULL) {
        free(p);
        p = NULL;
    }
}