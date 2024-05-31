#include <stdio.h>
#include <stdlib.h>
#include "data.h"

tData *CriaData(int dia, int mes, int ano) {
    tData *data = (tData*)malloc(sizeof(tData));

    if (data == NULL) {
        printf("Erro na alocacao da data ");
        return data;
    }

    data->dia = dia;
    data->mes = mes;
    data->ano = ano;

    return data;
}

tData *LeData() {
    int dia, mes, ano;
    tData *data;

    scanf("%02d/%02d/%04d", &dia, &mes, &ano);
    
    data = CriaData(dia, mes, ano);

    return data;
}

int CalCulaIdadeData(tData *nascimento, tData *diacalc) {
    int dia, mes, ano, d, m, a;
    int diaFinalMes;
    int bissexto;
    int idade = 0;

    dia = (*nascimento).dia;
    mes = (*nascimento).mes;
    ano = (*nascimento).ano;

    for (a = ano; a <= (*diacalc).ano; a++) {
        if (((a % 4 == 0) && (a % 100 != 0)) || ((a % 100 == 0) && (a % 400 == 0))) {
            bissexto = 1;
        }else {
            bissexto = 0;
        }
        if (a == ano) {
            m = mes;
        }else {
            m = 1;
        }
        while (m <= 12) {
            if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12)) {
                diaFinalMes = 31;
            }else {
                if ((m == 4) || (m = 6) || (m == 9) || (m == 11)) {
                    diaFinalMes = 30;
                }else {
                    if (m == 2) {
                        if (bissexto) {
                            diaFinalMes = 29; 
                        }else {
                            diaFinalMes = 28;
                        }
                    }
                }
            }
            if ((a = ano) && (m = mes)) {
                d = dia;
            }else {
                d = 1;
            }
            while (d <= diaFinalMes) {
                if ((d == (*nascimento).dia) && (m == (*nascimento).mes)) {
                    idade += 1;
                }
                if ((d = (*diacalc).dia) && (m == (*diacalc).mes) && (a == (*diacalc).ano)) {
                    return idade;
                }
                d++;
            }
            m++;
        }
    }
    return idade;
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