#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main() {
    tData data1, data2;
    int dia1, mes1, ano1, dia2, mes2, ano2, diferencaDias;
    
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    data1 = CriaData(dia1, mes1, ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);
    data2 = CriaData(dia2, mes2, ano2);

    if ((VerificaDataValida(data1)) && (VerificaDataValida(data2))) {
        printf("Primeira data: ");
        ImprimeDataExtenso(data1);
        printf("Segunda Data: ");
        ImprimeDataExtenso(data2);
    }else {
        printf("A primeira data e/ou segunda data(s) invalida(s)");
        exit(1);
    }

    if (ComparaData(data1, data2) == -1) {
        printf("A primeira data eh mais antiga\n");
    }else {
        if (ComparaData(data1, data2) == 1) {
            printf("A segunda data eh mais antiga\n");
        }else {
            printf("As datas sao iguais\n");
        }
    }

    diferencaDias = CalculaDiferencaDias(data1, data2);

    printf("A diferenca em dias entre as datas eh: %02d dias", diferencaDias);

    return 0;
}