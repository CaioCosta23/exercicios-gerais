#include <stdio.h>
#include <stdlib.h>
#include "cidade.h"
#include "defesa.h"
#include "missil.h"

struct cidade {
    float eixoX;
    float eixoY;
    tDefesa *defesas;
    tMissil misseis;
    int qtdDefesas;
    int qtdMisseis;
};

tCidade CriaCidade() {
    tCidade cidade = (tCidade)malloc(sizeof(struct cidade));

    if (cidade == NULL) {
        printf("Erro na alocacao de memoria da cidade!\n");
        exit(1);
    }

    cidade->defesas = (tDefesa*)malloc(QTD_DEF * sizeof(tDefesa));
    if ((*cidade).defesas == NULL) {
        printf("Erro na alocacao de memoria da lista de defesas da cidade!\n");
        LiberaCidade(cidade);
        exit(1);
    }

    cidade->misseis = (tMissil*)malloc(QTD_MIS * sizeof(tMissil));
    if ((*cidade).misseis == NULL) {
        printf("Erro na alocacao de memoria da lista de misseis de defesa da cidade!\n");
        LiberaCidade(cidade);
        exit(1);
    }int maxDefesas;

    cidade->eixoX = 0;
    cidade->eixoY = 0;
    cidade->qtdDefesas = 0;
    cidade->misseis = 0;

    return cidade;
}

tCidade LeEntrada(tCidade cidade) {
    char tipoDado;
    tDefesa defesa;

    scanf("C %f %f\n", &cidade->eixoX, &cidade->eixoY);

    while (1) {
        scanf("%c", &tipoDado);

        if (tipoDado != MISSIL) {
            break;
        }
        defesa = LeDefesa();
    }


}