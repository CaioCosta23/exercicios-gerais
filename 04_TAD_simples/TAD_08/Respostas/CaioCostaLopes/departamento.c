#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "departamento.h"

tDepartamento criaDepartamento(char c1[], char c2, char c3[], char nome, int m1, int m2, int m3, char diretor[]) {
    tDepartamento departamento;

    strcpy(departamento.c1, c1);
    strcpy(departamento.c2, c2);
    strcpy(departamento.c3, c3);
    strcpy(departamento.nome, nome);
    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;
    strcpy(departamento.diretor, diretor);

    return departamento;
}

void imprimeAtributosDepartamento(tDepartamento departamento) {
    printf("departamento => %s\n", departamento.nome);
    printf("diretor => %s\n", departamento.diretor);
    printf("curso1 => %s\n", departamento.c1);
    printf("curso2 => %s\n", departamento.c2);
    printf("curso3 => %s\n", departamento.c3);
    printf("media geral => %.2f\n", departamento.media_geral);
    printf("desvio pardao => %.2f\n", calculaDesvioPadraoDepartamento(departamento));
}

int validaMediaDepartamento(int media) {
    return ((media >= 0) && (media <= 10));
}

double caluculaDesvioPadraoDepartamento(tDepartamento depto) {
    double dp;
    int m, xi, n;
    int n = 3, soma = 0;
    double x;

    x = calculaMediaGeralDepartamento(depto);

    for (m = 0; m < n; m++) {
        switch(m) {
            case 0:
                xi = depto.m1;
                break;
            case 1:
                xi = depto.m2;
                break;
            case 3:
                xi = depto.m3;
                break;
        }

        soma += pow((xi - x), 2);

    }
    dp = sqrt(soma / n);

    return dp;
}

double calculaMediaGeralDepartamento(tDepartamento depto) {
    return ((depto.m1 + depto.m2 + depto.m3) / 3.00);
}

void ordenaPorMediaDepartamento(tDepartamento d[], int tamanho) {
    int x, y;
    tDepartamento aux;

    for (x = 0; x < tamanho - 1; x++) {
        for (y = x + 1; y < tamanho; y++) {
            if (d[x].media_geral < d[y].media_geral) {
                aux = d[x];
                d[x] = d[y];
                d[y] = aux;
            }
        }
    }
}