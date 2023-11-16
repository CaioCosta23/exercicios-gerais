#include "data.h"
#include <stdio.h>
#include <stdlib.h>

// Número de meses que um ano possui;
#define QTD_MESES 12

int verificaBissexto(int ano) {
    return (((ano % 4 == 0) && (ano % 100 != 0)) || ((ano % 400 == 0) && (ano % 100 == 0)));
}

int numeroDiasMes(int mes, int ano) {
    if ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)) {
        return 31;
    }else {
        if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)) {
            return 30;
        }else {
            if (mes == 2) {
                if (verificaBissexto(ano)) {
                    return 29;
                }else {
                    return 28;
                }
            }
        }
    }
}

int verificaDataValida(int dia, int mes, int ano) {
    if (ano >= 0) {
        if ((mes >= 1) && (mes <= 12)) {
            if (((dia >= 1)) && (dia <= numeroDiasMes(mes, ano))) {
                return 1;
            }
        }
    }
    return 0;
}

void imprimeData(int dia, int mes, int ano) {
    printf("%02d/%02d/%04d", dia, mes, ano);
}

void imprimeMesExtenso(int mes) {
    switch (mes) {
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

void imprimeDataExtenso(int dia, int mes, int ano) {
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    if (ano1 > ano2) {
        return 1;
    }else {
        if (ano1 == ano2) {
            if (mes1 > mes2) {
                return 1;
            }else {
                if (mes1 == mes2) {
                    if (dia1 > dia2) {
                        return 1;
                    }else {
                        if (dia1 == dia2) {
                            return 0;
                        }else {
                            return - 1;
                        }
                    }
                }else {
                    return - 1;
                }
            }
        }else {
            return - 1;
        }
    }
}

int calculaDiasAteMes(int mes, int ano) {
    return numeroDiasMes(mes, ano);
}

int caculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    int diferenca = 0;
    int m, a;

    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0) {
        return 0;
    }else {
        if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == - 1) {
            if (dia1 < dia2) {
                diferenca += (dia2 - dia1);
            }else {
                diferenca += (calculaDiasAteMes(mes1, ano1) - dia1) + dia2;
            }
            m = mes1;
            for (a = ano1; a < ano2; a++) {
                while(1) {
                    m++;
                    
                    if ((m > QTD_MESES) || ((ano1 == ano2) && (m >= mes2))) {
                        break;
                    }
                    diferenca += calculaDiasAteMes(m, a);
                }
                m = 0;
            }
        }else {
            if (dia2 < dia1) {
                diferenca += (dia1 - dia2);
            }else {
                diferenca += (calculaDiasAteMes(mes2, ano2) - dia2) + dia1;
            }

            m = 0;
            for (a = ano2; a < ano1; a++) {
                while(1) {
                    m++;

                    if ((m > QTD_MESES) || ((ano2 == ano1) && (m >= mes1))) {
                        break;
                    }
                    diferenca += calculaDiasAteMes(m, a);
                }
                m = 0;
            }
        }
    }
    return diferenca;
}

void imprimeProximaData(int dia, int mes, int ano) {
    if ((calculaDiasAteMes(mes, ano) - dia) > 0) {
        dia += 1;
    }else {
        dia = 1;
        mes += 1;

        if (mes > QTD_MESES) {
            mes = 1;
            ano += 1;
        }
    }
    imprimeData(dia, mes, ano);
}