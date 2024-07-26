#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

#define QTD_MESES_ANO 12
#define MES_30_DIAS 30
#define MES_31_DIAS 31
#define FEVEREIRO_NORMAL 28
#define FEVEREIRO_ANO_BISSEXTO 29

#define QTD_HORAS_DIA 24
#define QTD_MINUTOS_HORA 60

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

void ProcessaDiaMesAno(tData *data, char *str) {
    sscanf(str, " %d/%d/%d", &data->dia, &data->mes, &data->ano);
}

void ProcessaDiaDaSemana(tData *data, char *str) {
    sscanf(str, "%d", &data->codDiaSemana);
}

void ProcessaHorario(tData *data, char *str) {
    sscanf(str, " %d:%d", &data->horaHorario, &data->minutoHorario);
}

int VerificaDataValida(tData *data) {
    if ((*data).ano > 0) {
        if (((*data).mes > 0) && ((*data).mes <= QTD_MESES_ANO)) {
            if (((*data).dia > 0) && ((*data).dia <= NumeroDiasMes(data))) {
                return 1;
            }
        }
    }
    return 0;
}

int VerificaBissexto(tData *data) {
    return ((((*data).ano % 4 == 0) && ((*data).ano % 100 != 0)) || ((*data).ano % 400 == 0));
}

int NumeroDiasMes(tData *data) {
    if (VerificaDataValida(data)) {
        if (((*data).mes == 1) || ((*data).mes == 3) || ((*data).mes == 5) || ((*data).mes == 7) || 
            ((*data).mes == 8) || ((*data).mes == 10) || ((*data).mes == 12)) {
                return MES_31_DIAS;
        }else {
            if (((*data).mes == 4) || ((*data).mes == 6) || ((*data).mes == 9) || ((*data).mes == 11)) {
                return MES_30_DIAS;
            }else {
                if ((*data).mes == 2) {
                    if (VerificaBissexto(data)) {
                        return FEVEREIRO_ANO_BISSEXTO;
                    }else {
                        return FEVEREIRO_NORMAL;
                    }
                }
            }
        }
    }
    data->mes = 1;
    return MES_31_DIAS;
}

int ComparaDiaMesAno(tData *data1, tData *data2) {
    if ((*data1).ano > (*data2).ano) {
        return 1;
    }else {
        if ((*data1).ano == (*data2).ano) {
            if ((*data1).mes > (*data2).mes) {
                return 1;
            }else {
                if ((*data1).mes == (*data2).mes) {
                    if ((*data1).dia > (*data2).dia) {
                        return 1;
                    }else {
                        if ((*data1).dia == (*data2).dia) {
                            return 0;
                        }
                        return -1;
                    }
                }
                return -1;
            }
        }
        return -1;
    }
}

int CalculaDiasAteMes(tData *data) {
    // Função Obsoleta;
    return (NumeroDiasMes(data) - (*data). dia);
}

int CalculaDiferencaDias(tData *data1, tData *data2) {
    int diferenca = 0;
    tData *dataAuxiliar = NULL;

    dataAuxiliar = CriaData();

    CopiaDiaMesAno(data1, dataAuxiliar);

    while (1) {
        if (((*dataAuxiliar).ano == (*data2).ano) && ((*dataAuxiliar).mes == (*data2).mes) && ((*dataAuxiliar).dia == (*data2).dia)) {
            break;
        }
        DataDiaSeguinte(dataAuxiliar);
        diferenca += 1;
    }
    DestroiData(dataAuxiliar);

    return diferenca;
}

float CalculaHorasEntreDatas(tData *data1, tData *data2) {
    float diferenca = 0;

    if (CalculaDiferencaDias(data1, data2) > 1) {
        diferenca += (float)((CalculaDiferencaDias(data1, data2) * QTD_HORAS_DIA) - 1);
    }

    if ((*data2).horaHorario < (*data1).horaHorario) {
        diferenca += (float)(QTD_HORAS_DIA + (*data2).horaHorario) - (*data1).horaHorario;
    }else {
        diferenca += (float)(*data2).horaHorario - (*data1).horaHorario;
    }

    if ((*data2).minutoHorario < (*data1).minutoHorario) {
        diferenca -= 1;
        diferenca += ((float)((QTD_MINUTOS_HORA + (*data2).minutoHorario) - (*data1).minutoHorario) * 1) / (float)QTD_MINUTOS_HORA;
    }else {
        diferenca += ((float)((*data2).minutoHorario - (*data1).minutoHorario) * 1) / (float) QTD_MINUTOS_HORA;
    }

    return diferenca;
}

int DataEhSabadoOuDomingo(tData *data) {
    if (((*data).codDiaSemana == 0) || (*data).codDiaSemana == 6) {
        return 1;
    }
    return 0;
}

void DataDiaSeguinte(tData *data) {
    if ((*data).dia == NumeroDiasMes(data)) {
        data->dia = 1;
        if ((*data).mes == QTD_MESES_ANO) {
            data->mes = 1;
            data->ano += 1;
        }else {
            data->mes += 1;
        }
    }else {
        data->dia += 1;
    }
}

void CopiaDiaMesAno(tData *src, tData *tgt) {
    tgt->codDiaSemana = (*src).codDiaSemana;
    tgt->dia = (*src).dia;
    tgt->mes = (*src).mes;
    tgt->ano = (*src).ano;
    tgt->horaHorario = (*src).horaHorario;
    tgt->minutoHorario = (*src).minutoHorario;
}

void DestroiData(tData *data) {
    if (data != NULL) {
        free(data);
        data = NULL;
    }
}