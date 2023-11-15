#include "data.h"

int verificaBissexto(int ano) {
    if ((ano % 400 == 0) && (ano % 100 != 0) && (ano % 4 == 0)) {
        return 1;
    }
    return 0;
}

int numeroDiasMes(int mes, int ano) {
    if ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) 
        || (mes == 10) || (mes == 12)) {
            return 31;
    }else {
        if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11) || (mes == 8)) {
            return 30;
        }else {
            if (verificaBissexto(ano)) {
                return 29;
            }else {
                return 28;
            }
        }
    }
}

int verificaDataValida(int dia, int mes, int ano) {
    if (ano >= 0) {
        if ((mes >=1) && (mes <= 12)) {
            // A funcao "numeroDiasMes()" coletara o mes e verificara quantos dias o referido mes tem; 
            if ((dia >= 1) && (numeroDiasMes(mes, ano) <= dia)) {
                return 1;
            }
        }
    }
    return 0;
    
}
void imprimeMesExtenso(int mes) {
    switch(mes) {
        case 1:
            printf("Janeiro");
            break;
        case 2:
            printf("Fevereiro:");
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
    if (verificaDataValida(dia, mes, ano)) {
        printf("%02d de ", dia);
        imprimeMesextenso(mes);
        printf(" de %04d", ano);
    }else {
        printf("primeira e/ou segunda data(s) invalida(s)");
        exit(1);
    }
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
                    if (mes1 < mes2) {
                        return - 1;
                    }
                }
            }
        }else {
            if (ano1 < ano2) {
                return - 1;
            }
        }
    }
}

int calculaDiasAteMes(int mes, int ano) {

    return numeroDiasMes(mes, ano);
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    int diferenca = 0;
    int a, m;

    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0) {
        return 0;
    }else {
        if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1) {
            m = mes1;
            for (a = ano1; a <= ano2; a++) {
                while(1) {
                    diferenca += calculaDiasAteMes(m, a);

                    m++;

                    if ((m == 13) || ((ano1 == ano2) && (m == mes2))) {
                        break;
                    }
                }
                m = 0;
            }
            if (dia1 > dia2) {
                diferenca += (dia1 - dia2);
            }else {
                /**
                 * @brief Calcula a diferenca de dias caso o dia da data que esta mais a frente seja menor que o dia da data que esta mais no atras;
                 * Um exemplo - 25/10/2023 a 23/11/2023. Sabendo que Outubro tem 31 dias (calculado na funcao "calculaDiasAteMes()"), temos entao:
                 * diferenca = diferenca + (31 - 25) + 23);
                 */
                diferenca += ((calculaDiasAteMes(mes1, ano1) - dia1) + dia2);
            }
        }else {
            m = mes2;
            for (a = ano2; a <= ano1; a++) {
                while(1) {
                    diferenca += calculaDiasAteMes(m, a);

                    m++;

                    if ((m == 13) || ((ano1 == ano2) && (m == mes1))) {
                        break;
                    }
                }
                m = 0;
            }
            if (dia2 > dia1) {
                diferenca += (dia2 - dia1);
            }else {
                /**
                 * @brief Calcula a diferenca de dias caso o dia da data que esta mais a frente seja menor que o dia da data que esta mais no atras;
                 * Um exemplo - 25/10/2023 a 23/11/2023. Sabendo que Outubro tem 31 dias (calculado na funcao "calculaDiasAteMes()"), temos entao:
                 * diferenca = diferenca + (31 - 25) + 23);
                 */
                diferenca += ((calculaDiasAteMes(mes2, ano2) - dia2) + dia1);
            }
        }
    }
}