#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct Data {
    int dia;
    int mes;
    int ano;
};

tData *CriaData() {
    tData *data = (tData*)malloc(sizeof(tData));

    if (data == NULL) {
        printf("Erro na alocacao da data!\n");
    }

    data->dia = -1;
    data->mes = -1;
    data->ano = -1;

    return data;
}

void LeData(tData *data) {
    scanf("%02d/%02d/%04d", &data->dia, &data->mes, &data->ano);
}

int VerificaDataValida(tData *data) {
    if ((*data).ano > 0) {
        if ((*data).ano > 0) {
            if (((*data).mes > 0) && ((*data).mes <= 12)) {
                if (((*data).dia > 0) && ((*data).dia <= NumeroDiasMes(data))) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int VerificaBissexto(tData *data) {
    return ((((*data).ano % 4 == 0) && ((*data).ano % 100 != 0)) || (((*data).ano % 100 == 0) && ((*data).ano % 400 == 0)));
}

int NumeroDiasMes(tData *data) {
    if (((*data).mes == 1) || ((*data).mes == 3) || ((*data).mes == 5) || ((*data).mes == 7) || ((*data).mes == 8) || ((*data).mes == 10) || ((*data).mes == 12)) {
        return 31;
    }else {
        if (((*data).mes == 4) || ((*data).mes == 6) || ((*data).mes == 9) || ((*data).mes == 11)) {
            return 30;
        }else {
            if (VerificaBissexto(data)) {
                return 29;
            }else {
                return 28;
            }
        }
    }
}

int ComparaData(tData *data1, tData *data2) {
    if ((*data1).ano > (*data2).ano) {
        return 1;
    }else {
        if (((*data1).ano == (*data2).ano) && ((*data1).mes > (*data2).mes)) {
            return 1;
        }else {
            if (((*data1).mes == (*data2).mes) && ((*data1).dia > (*data2).dia)) {
                return 1;
            }else {
                if ((*data1).dia == (*data2).dia) {
                    return 0;
                }
            }
        }
    }
    return -1;
}

// Função Inrrelevante - No modo de código feito neste arquivo;
int CalculaDiasAteMes(tData *data) {
    return NumeroDiasMes(data);
}

int CalculaDiferencaDias(tData *data1, tData *data2) {
    int diferenca = 0;
    tData *dataAuxiliar = NULL;

    dataAuxiliar = CriaData();
    
    dataAuxiliar->dia = 0;

    if (ComparaData(data1, data2) == -1) {
        if ((*data1).dia < (*data2).dia) {
            diferenca += (*data2).dia - (*data1).dia;
        }else {
            diferenca += (CalculaDiasAteMes(data1) - (*data1).dia) + (*data2).dia;
        }
        dataAuxiliar->mes = (*data1).mes;
        for ((*dataAuxiliar).ano = (*data1).ano; (*dataAuxiliar).ano <= (*data2).ano; (*dataAuxiliar).ano++) {
            while (1) {
                dataAuxiliar->mes++;

                if (((*dataAuxiliar).mes > 12) || (((*data1).ano == (*data2).ano) && (*dataAuxiliar).mes >= (*data2).mes)) {
                    break;
                }
                diferenca += CalculaDiasAteMes(dataAuxiliar);
            }
            dataAuxiliar->mes = 0;
        }
    }else {
        if (ComparaData(data1, data2) == 1) {
            if ((*data2).dia < (*data1).dia) {
                diferenca += (*data1).dia - (*data2).dia;
            }else {
                diferenca += (CalculaDiasAteMes(data2) - (*data2).dia) + (*data1).dia;
            }
            dataAuxiliar->mes = (*data2).mes;
            for ((*dataAuxiliar).ano = (*data2).ano; (*dataAuxiliar).ano < (*data1).ano; (*dataAuxiliar).ano++) {
                while (1) {
                    dataAuxiliar->mes++;
                    if (((*dataAuxiliar).ano == (*data2).ano) || (((*data1).ano == (*data2).ano) && ((*dataAuxiliar).mes >= (*data1).mes))) {
                        break;
                    }
                    diferenca += CalculaDiasAteMes(dataAuxiliar);
                }
                dataAuxiliar->mes = 0;
            }
        }
    }
    LiberaData(dataAuxiliar);

    return diferenca;
}

void ImprimeMesExtenso(tData *data) {
    switch((*data).mes) {
        case 1:
            printf("Janeiro");
            break;
        case 2:
            printf("Fevereiro");
            break;
        case 3:
            printf("Marco");
            break;
        case 4:
            printf("Abril");
            break;
        case 5:
            printf("Maio");
            break;
        case 6:
            printf("Junho");
            break;
        case 7:
            printf("Julho");
            break;
        case 8:
            printf("Agosto");
            break;
        case 9:
            printf("Setembro");
            break;
        case 10:
            printf("Outubro");
            break;
        case 11:
            printf("Novembro");
            break;
        case 12:
            printf("Dezembro");
            break;
    }
}

void ImprimeDataExtenso(tData *data) {
    printf("%02d de ", (*data).dia);
    ImprimeMesExtenso(data);
    printf(" de %04d\n", (*data).ano);
}

void LiberaData(tData *data) {
    if (data != NULL) {
        free(data);
        data = NULL;
    }
}