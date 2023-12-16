#include <stdio.h>
#include <stdlib.h>
#include "evento.h"

void cadastrarEvento(Evento eventos[], int *numEventos) {
    if(scanf("%s\n %d %d %d", eventos[*numEventos].nome, &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano) == 4) {
        printf("Evento cadastrado com sucesso\n");
        *numEventos += 1;
    }else {
        printf("ERRO! Algum dos atributos nao recebeu os parametros esperados.");
        exit(1);
    }
}

void exibirEventos(Evento eventos[], int *numEventos) {
    int e;

    printf("Eventos cadastrados:\n");

    for (e = 0; e < *numEventos; e++) {
        printf("%d - %s - %d/%d/%d\n", e, eventos[e].nome, eventos[e].dia, eventos[e].mes, eventos[e].ano);
    }
}

void trocarDataEvento(Evento eventos[], int *numEventos) {
    int i, indice;

    scanf("%d", &indice);

    for (i = 0; i < *numEventos; i++) {
        if (i == indice) {
            scanf("%d %d %d", &eventos[i].dia, &eventos[i].mes, &eventos[i].ano);
            break;
        }
    }
}

void trocarIndicesEventos(Evento eventos[], int *indiceA, int *indiceB, int *numEventos) {
    int *x;
    int aux;

    for (x = eventos; x < eventos + *numEventos; x++) {
        if (*x == *indiceA) {
            aux = *indiceA;
            *indiceA = *indiceB;
            *indiceB = aux;
            break;
        }
    }
}