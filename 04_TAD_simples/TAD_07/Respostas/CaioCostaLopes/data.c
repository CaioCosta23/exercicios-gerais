#include <stdio.h>
#include <stdlib.h>
#include "data.h"

tData CriaData(int dia, int mes, int ano) {
    tData data;

    data.dia = dia;
    data.mes = mes;
    data.ano = ano;

    return data;
}

int VerificaDataValida(tData data) {
    if (data.ano >= 0) {
        if ((data.mes >= 1) && (data.mes <= 12)) {
            if ((data.dia >= 1) && (data.dia <= NumeroDiasMes(data))) {
                return 1;
            }
        }
    }
    return 0;
}

void ImprimeMesExtenso(tData data) {
    switch(data.mes) {
        case 1:
            printf("Janeiro");
        case 2:
            printf("Fevereiro");
        case 3:
            printf("Marco");
        case 4:
            printf("Abril");
        case 5:
            printf("Maio");
        case 6:
            printf("Junho");
        case 7:
            printf("Julho");
        case 8:
            printf("Agosto");
        case 9:
            printf("Setembro");
        case 10:
            printf("Outubro");
        case 11:
            printf("Novembro");
        case 12:
            printf("Dezembro");
    }
}

void ImprimeDataExtenso(tData data) {
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %04d\n", data.ano);
}

int VerificaBissexto(tData data) {
    return (((data.ano % 4 == 0) && (data.ano % 100 != 0)) || ((data.ano % 100  == 0) && (data.ano % 400 == 0)));
}