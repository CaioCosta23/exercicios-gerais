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

int NumeroDiasMes(tData data) {
    if ((data.mes == 1) || (data.mes == 3) || (data.mes == 5) || (data.mes == 8) || (data.mes == 8) ||
    (data.mes == 10) || (data.mes == 12)) {
        return 31;
    }else {
        if ((data.mes == 4) || (data.mes== 6) || (data.mes == 9) ||(data.mes == 11)) {
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

int ComparaData(tData data1, tData data2) {
    if (data1.ano > data2.ano) {
        return 1;
    }else {
        if (data1.ano == data2.ano) {
            if (data1.mes > data2.mes) {
                return 1;
            }else {
                if (data1.mes == data2.mes) {
                    if (data1.dia > data2.dia) {
                        return 1;
                    }else {
                        if (data1.dia == data2.dia) {
                            return 0;
                        }else {
                            return - 1;
                        }
                    }
                }else {
                    if (data1.mes < data2.mes) {
                        return - 1;
                    }
                }
            }
        }else {
            if (data1.ano < data2.ano) {
                return - 1;
            }
        }
    }
}

int CalculaDiasAteMes(tData data) {
    return NumeroDiasMes(data);
}

int CalculaDiferencaDuas(tData data1, tData data2) {
    int diferenca = 0;
    int a, m;
    tData aux;

    aux.dia = 0;

    if (ComparaData(data1, data2) == 0) {
        return 0;
    }else {
        if (ComparaData(data1, data2) == - 1) {
            if (data1.dia < data2.dia) {
                diferenca += (data2.dia - data1.dia);
            }else {
                /**
                 * @brief Calcula a diferenca de dias caso o dia da data que esta mais a frente seja menor que o dia da data que esta mais no atras;
                 * Um exemplo - 25/10/2023 a 23/11/2023. Sabendo que Outubro tem 31 dias (calculado na funcao "calculaDiasAteMes()"), temos entao:
                 * diferenca = diferenca + (31 - 25) + 23);
                 */
                diferenca += ((CalculaDiasAteMes(data1) - data1.dia) + data2.dia);
            }
            aux.mes = data1.mes;
            for (aux.ano = data1.ano; aux.ano <= data2.ano; aux.ano++) {
                while (1) {
                    aux.mes++;

                    if ((aux.mes > 12) || ((data1.ano == data2.ano) && (aux.mes >= data2.mes))) {
                        break;
                    }
                    diferenca += CalculaDiasAteMes(aux);
                }
                aux.mes = 0;
            }
        }else {
            if (data1.dia < data2.dia) {
                diferenca += (data1.dia - data2.dia);
            }else {
                /**
                 * @brief Calcula a diferenca de dias caso o dia da data que esta mais a frente seja menor que o dia da data que esta mais no atras;
                 * Um exemplo - 25/10/2023 a 23/11/2023. Sabendo que Outubro tem 31 dias (calculado na funcao "calculaDiasAteMes()"), temos entao:
                 * diferenca = diferenca + (31 - 25) + 23);
                 */
                diferenca += ((CalculaDiasAteMes(data2) - data2.dia) + data1.dia);
            }
            aux.mes = data2.mes;
            for (aux.ano = data2.ano; aux.ano <= data1.ano; aux.ano++) {
                while (1) {
                    aux.mes++;

                    if ((aux.mes > 12) || ((data1.ano == data2.ano) && (aux.mes >= data1.mes))) {
                        break;
                    }
                    diferenca += CalculaDiasAteMes(aux);
                }
                aux.mes = 0;
            }
        }
    }
    return diferenca;
}