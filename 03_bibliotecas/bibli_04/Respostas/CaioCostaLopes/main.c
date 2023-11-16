#include "data.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    int dia1, mes1, ano1;
    //int dia2, mes2, ano2;

    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    // scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    if(verificaDataValida(dia1, mes1, ano1)) {
        printf("Data informada: ");
        imprimeDataExtenso(dia1, mes1, ano1);
        //printf("Primeira data: ", dia1, mes1, ano1);
    }else {
        printf("A data informada eh invalida");
        // printf("A primeira e/ou segunda data(s) invalida(s)");
        exit (1);
    }

    if (verificaBissexto(ano1)) {
        printf("O ano informado eh bissexto\n");
    }else {
        printf("O ano informado nao eh bissexto\n");
    }

    printf("O mes informado possui %d dias\n", numeroDiasMes(mes1, ano1));
    
    printf("A data seguinte eh: ");
    imprimeProximaData(dia1, mes1, ano1);

    /**
     * @brief COMANDOS ADICIONAIS;
     * 
     * Os Comandos a seguir são para o uso das funcionalidades adicionais (comparar as datas, ver a diferença entreas duas, etc.).
     * Para utilizá-las, basta decomentar os comandos. (Fazer o mesmo para os comandos comentados acima);
     */

    /*
    if(verificaDataValida(dia2, mes2, ano2)) {
        //printf("Primeira data: ", dia2, mes2, ano2);
    }else {
        exit(1);
    }

    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == - 1) {
        printf("A primeira data eh mais antiga\n");
    }else {
        if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1) {
            printf("A segunda data eh mais antiga\n");
        }else {
            printf("As datas sao iguais");
        }
    }

    printf("A diferenca em dias entre as datas eh: %02d", calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2));
    */

    return 0;
}