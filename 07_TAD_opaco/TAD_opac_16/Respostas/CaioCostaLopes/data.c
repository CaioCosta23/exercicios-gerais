#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

struct Data {
    int codDiaSemana;
    int dia;
    int mes;
    int ano;
    int horaHorario;
    int minutoHorario;
};

tData *CriaData() {
    tData *data = (tData*)malloc(sizeof(tData));

    if (data == NULL) {
        printf("Erro na alocacao de memoria da data ");
        return data;
    }

    data->codDiaSemana = -1;
    data->dia = -1;
    data->mes = -1;
    data->ano = -1;
    data->horaHorario = -1;
    data->minutoHorario = -1;

    return data;
}

