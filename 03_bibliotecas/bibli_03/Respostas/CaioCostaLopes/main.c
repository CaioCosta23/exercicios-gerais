#include "data.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    int dia1, mes1, ano1, dia2, mes2, ano2, diferenca_Dias;

    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    printf("Primeira data:");
    imprimeDataExtenso(dia1, mes1, ano1);
    printf("\nSegunda data:");
    imprimeDataExtenso(dia2, mes2, ano2);

    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1) {
        printf("\nA primeira data eh mais antiga\n");
    }else{
        if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == - 1) {
            printf("\nA segunda data eh mais antiga\n");
        }else{
            printf("As datas sao iguais");
        }
    }

    diferenca_Dias = calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2);

    return 0;
}