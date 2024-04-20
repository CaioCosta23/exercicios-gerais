#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "departamento.h"

tDepartamento *CriaDepartamento() {
    tDepartamento *departamento = (tDepartamento*)malloc(sizeof(tDepartamento));
    
    if (departamento == NULL) {
        printf("Erro na alocacao do departamento\n");
        LiberaMemoriaDepartamento(departamento);
        exit(1);
    }

    departamento->nome = NULL;
    departamento->c1 = NULL;
    departamento->c2 = NULL;
    departamento->c3 = NULL;
    departamento->m1 = -1;
    departamento->m2 = -1;
    departamento->m3 = -1;
    departamento->diretor = NULL;
    departamento->media_geral = -1;

    return departamento;
}

void PreencheDadosDepartamento(tDepartamento *depto, char *c1, char *c2, char *c3, char *nome, int m1, int m2, int m3, char *diretor) {
    depto->c1 = (char*)malloc(STRING_MAX * sizeof(char));
    if ((*depto).c1 == NULL) {
        printf("Erro na alocacao do nome do curso 1!\n");
        LiberaMemoriaDepartamento(depto);
        exit(1);
    }
    strcpy((*depto).c1, c1);

    depto->c2 = (char*)malloc(STRING_MAX * sizeof(char));
    if ((*depto).c2 == NULL) {
        printf("Erro na alocacao do nome do curso 2!\n");
        LiberaMemoriaDepartamento(depto);
        exit(1);
    }
    strcpy((*depto).c2, c2);
    
    depto->c3 = (char*)malloc(STRING_MAX * sizeof(char));
    if ((*depto).c3 == NULL) {
        printf("Erro na alocacao do nome do curso 3!\n");
        LiberaMemoriaDepartamento(depto);
        exit(1);
    }
    strcpy((*depto).c3, c3);

    depto->nome = (char*)malloc(STRING_MAX * sizeof(char));
    if ((*depto).nome == NULL) {
        printf("Erro na alocacao do nome do departamento!\n");
        LiberaMemoriaDepartamento(depto);
        exit(1);
    }
    strcpy((*depto).nome, nome);

    depto->m1 = m1;
    depto->m2 = m2;
    depto->m3 = m3;

    depto->diretor = (char*)malloc(STRING_MAX * sizeof(char));
    if ((*depto).diretor == NULL) {
        printf("Erro na alocacao do nome do diretor!\n");
        LiberaMemoriaDepartamento(depto);
        exit(1);
    }
    strcpy((*depto).diretor, diretor);

    depto->media_geral = CalculaMediaGeralDepartamento(depto);
}

int ValidaMediaDepartamento(int media) {
    return ((media >= 0) && (media <= 10));
}

double CalculaDesvioPadraoDepartamento(tDepartamento *depto) {
    double desvioPadrao;
    int m;
    int qtdMedias = 3;
    double soma = 0.00;
    double x, xi;

    x = (*depto).media_geral;

    for (m = 1; m <= qtdMedias; m++) {
        switch(m) {
            case 1:
                xi = (double)(*depto).m1;
                break;
            case 2:
                xi = (double)(*depto).m2;
                break;
            case 3:
                xi = (double)(*depto).m3;
                break;
        }
        soma += pow((xi - x), 2);
    }
    desvioPadrao = sqrt(soma / (double)qtdMedias);

    return desvioPadrao;
}

double CalculaMediaGeralDepartamento(tDepartamento *depto) {
    return (((double)(*depto).m1 + (double)(*depto).m2 + (double)(*depto).m3) / (double)3);
}

void OrdenaPorMediaDepartamentos(tDepartamento *d[], int tamanho) {
    int x, y;
    tDepartamento *aux = NULL;

    for (x = 0; x < (tamanho - 1); x++) {
        for (y = x + 1; y < tamanho; y++) {
            /*
             * Para acessar vetor de ponteiros, é necessário usar o operador "->" ao invés de "." 
             * uma vez que estamos manipulando um vetor de ponteiros nessa estrutura condicional;
             * (e não um ponteiro para um vetor);
            */
            if (d[x]->media_geral < d[y]->media_geral) {
                aux = d[x];
                d[x] = d[y];
                d[y] = aux;
            }
        }
    }
}

void ImprimeAtributosDepartamento(tDepartamento *depto) {
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", (*depto).nome);
    printf("diretor => %s\n", (*depto).diretor);
    printf("curso1 => %s, media1 => %d\n", (*depto).c1, (*depto).m1);
    printf("curso2 => %s, media2 => %d\n", (*depto).c2, (*depto).m2);
    printf("curso3 => %s, media3 => %d\n", (*depto).c3, (*depto).m3);
    printf("media geral => %.2f\n", (*depto).media_geral);
    printf("desvio padrao => %.2f\n", (float)CalculaDesvioPadraoDepartamento(depto));
    printf("\n");
}

void LiberaMemoriaDepartamento(tDepartamento *depto) {
    if (depto != NULL) {
        if ((*depto).c1 != NULL) {
            free((*depto).c1);
        }
        if ((*depto).c2 != NULL) {
            free((*depto).c2);
        }
        if ((*depto).c3 != NULL) {
            free((*depto).c3);
        }
        if ((*depto).nome != NULL) {
            free((*depto).nome);
        }
        if (depto->diretor != NULL) {
            free((*depto).diretor);
        }
        free(depto);
    }
}