#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct data {
    int dia;
    int mes;
    int ano;
};

tData *CriaData(int dia, int mes, int ano) {
    tData *data = (tData*)malloc(sizeof(tData));

    if (data == NULL) {
        printf("Erro na alocacção da data ");
        return data;
    }

    data->dia = dia;
    data->mes = mes;
    data->ano = ano;

    return data;
}

tData *LeData() {
    int dia, mes, ano;
    tData *data = NULL;

    scanf("%02d/%02d/%04d\n", &dia, &mes, &ano);

    data = CriaData(dia, mes, ano);

    return data;
}

int CalculaIdadeData(tData *nascimento, tData *diacalc) {
    return ((*diacalc).ano - (*nascimento).ano);
}

void ImprimeData(tData *d) {
    printf("%02d/%02d/%04d\n", (*d).dia, (*d).mes, (*d).ano);
}

void LiberaData(tData *d) {
    if (d != NULL) {
        free(d);
        d = NULL;
    }
}