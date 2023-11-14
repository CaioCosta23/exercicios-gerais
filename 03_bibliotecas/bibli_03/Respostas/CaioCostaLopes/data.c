#include "data.h"

int verificaBissexto(int ano) {
    if ((ano % 400 == 0) && (ano % 100 != 0) && (ano %4 == 0)) {
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
    
}