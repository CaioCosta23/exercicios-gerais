#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main() {
    tData *data1, *data2;

    data1 = CriaData();
    data2 = CriaData();

    LeData(data1);
    LeDaa(data2);

    ImprimeDataExtenso(data1);
    ImprimeExtenso(data2);

    if (ComparaData(data1, data2) == 1) {
        printf("A primeira data eh mais antiga\n");
    }else {
        if (ComparaData(data1, data2) == -1) {
            printf("A segunda data eh mais antiga\n");
        }else {
            printf("As datas sao iguais\n");
        }
    }

    printf("A diferenca em dias entre as datas eh: %d dias\n", CalculaDiferencaDias(data1, data2));

    return 0;
}