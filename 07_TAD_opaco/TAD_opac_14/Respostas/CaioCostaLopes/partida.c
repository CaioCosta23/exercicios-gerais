#include <stdio.h>
#include <stdlib.h>
#include "partida.h"
#include "franquia.h"

struct partida {
    char *time1;
    char *time2;
    int pontos1;
    int pontos2
};

tPartida LePartida() {
    tPartida partida = (tPartida)malloc(sizeof(struct partida));

    if (partida == NULL) {
        printf("Erro na alocaccao de memoria da partida ");
        return partida;
    }

    partida->time1 = (char*)malloc(MAX_NOME * sizeof(char));
    if ((*partida).time1 == NULL) {
        printf("Erro na alocacao de memoria no nome do time 1 da partida ");
        LiberaPartida(partida);
        return partida;
    }
    
    partida->time2 = (char*)malloc(MAX_NOME * sizeof(char));
    if ((*partida).time2 == NULL) {
        printf("Erro na alocacao de memoria no nome do time 2 da partida ");
        LiberaPartida(partida);
        return partida;
    }

    partida->pontos1 = 0;
    partida->pontos2 = 0;

    scanf("%s @ %s %d %d\n", partida->time1, partida->time2, &partida->pontos1, &partida->pontos2);

    return partida;
}

char *GetTime1Partida(tPartida p) {
    return (*p).time1;
}

char *GetTime2Partida(tPartida p) {
    return (*p).time2;
}

int GetVencedorPartida (tPartida p) {
    if ((*p).pontos1 > (*p).pontos2) {
        return TIME_CASA;
    }else {
        if ((*p).pontos1 < (*p).pontos2) {
            return TIME_FORA;
        }
    }
}

void ImprimePartida(tPartida p) {
    // Função obsoleta devido a formatação do programa;
}

void LiberaPartida(tPartida p) {
    if (p != NULL) {
        if ((*p).time1 != NULL) {
            free((*p).time1);
            p->time1 = NULL;
        }
        if ((*p).time2 != NULL) {
            free((*p).time2);
            p->time2 = NULL;
        }
        free(p);
        p = NULL;
    }
}