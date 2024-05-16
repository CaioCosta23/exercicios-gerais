#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

struct circulo {
    float raio;
    tPonto centro;
};

tCirculo Cria_Circulo(float x, float y, float r) {
    tCirculo circulo = (tCirculo*)malloc(sizeof(tCirculo));

    if (circulo == NULL) {
        printf("Erro na alocacao do circulo!\n");
        exit(1);
    }

    Circulo_Atribui_Centro(circulo, Pto_Cria(x, y));
    Circulo_Atribui_Raio(circulo, r);

    return circulo;
}

tPonto Circulo_Acessa_Centro(tCirculo c) {
    return (*c).centro;
}

float Circulo_Acessa_Raio(tCirculo c) {
    return (*c).raio;
}

void Circulo_Atribui_Centro(tCirculo c, tPonto p) {
    Pto_Atribui_x((*c).centro, Pto_Acessa_x(p));
    Pto_Atribui_y((*c).centro, Pto_Acessa_y(p));
}

void Circulo_Atribui_Raio(tCirculo c, float r) {
    c->raio = r;
}

int Circulo_Interior(tCirculo c, tPonto p) {
    if (Pto_Distancia((*c).centro, p) > (*c).raio) {
        return 1;
    }
    return 0;
}

void Circulo_Apaga(tCirculo c) {
    if (c != NULL) {
        if ((*c).centro != NULL) {
            Pto_Apaga((*c).centro);
        }
        free(c);
        c = NULL;
    }
}