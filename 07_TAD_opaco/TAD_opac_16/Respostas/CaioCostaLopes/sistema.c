#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema.h"

#define MAX_TIQUETES 10
#define ENCERRAR '\n'
#define TAM_NOME_DIA_SEMANA 2
#define TAM_DATA 10
#define TAM_HORARIO 6

struct Sistema {
    tData **dataEntrada;
    tData **dataSaida;
    int qtdRegistros;
    int maxRegistros;
    float faturamentoTotal;
};

tSistema *CriaSistema() {
    tSistema *sistema = (tSistema*)malloc(sizeof(tSistema));

    if (sistema == NULL) {
        printf("Erro na alocacao de memoria do sistema!\n");
        exit(1);
    }

    sistema->dataEntrada = (tData**)malloc(MAX_TIQUETES * sizeof(tData*));
    if ((*sistema).dataEntrada == NULL) {
        printf("Erro na alocacao de memoria do vetor/lista dos registros de entrada!\n");
        DestroiSistema(sistema);
        exit(1);
    }

    sistema->dataSaida = (tData**)malloc(MAX_TIQUETES * sizeof(tData*));
    if ((*sistema).dataSaida == NULL) {
        printf("Erro na alocacao de memoria do vetor/lista dos registros de saida!\n");
        DestroiSistema(sistema);
        exit(1);
    }

    sistema->qtdRegistros = 0;
    sistema->maxRegistros = MAX_TIQUETES;
    sistema->faturamentoTotal = 0;

    return sistema;
}

void LeSistema(tSistema *sys) {
    tData *registro;
    char codDiaSemana;
    char diaSemana[TAM_NOME_DIA_SEMANA], data[TAM_DATA], horario[TAM_HORARIO];

    while(1) {
        scanf("%c", &codDiaSemana);
        if (codDiaSemana == ENCERRAR) {
            break;
        }else {
            switch(codDiaSemana) {
                case '0':
                    strcpy(diaSemana, "0");
                    break;
                case '1':
                    strcpy(diaSemana, "1");
                    break;
                case '2':
                    strcpy(diaSemana, "2");
                    break;
                case '3':
                    strcpy(diaSemana, "3");
                    break;
                case '4':
                    strcpy(diaSemana, "4");
                    break;
                case '5':
                    strcpy(diaSemana, "5");
                    break;
                case '6':
                    strcpy(diaSemana, "6");
                    break;
                default:
                    printf("Dia invalido!\n");
                    DestroiSistema(sys);
                    exit(1);
            }
        }

        scanf("%*[^ ] ");

        if ((*sys).qtdRegistros == (*sys).maxRegistros) {
            sys->maxRegistros += MAX_TIQUETES;

            sys->dataEntrada = (tData**)realloc((*sys).dataEntrada, (*sys).maxRegistros * sizeof(tData*));
            if ((*sys).dataEntrada == NULL) {
                printf("Erro na realocacao de memoria do vetor/lista de registros de tiquetes!\n");
                DestroiSistema(sys);
                exit(1);
            }
            sys->dataSaida = (tData**)realloc((*sys).dataSaida, (*sys).maxRegistros * sizeof(tData*));
            if ((*sys).dataSaida == NULL) {
                printf("Erro na realocacao de memoria do vetor/lista de registros de saida!\n");
                DestroiSistema(sys);
                exit(1);
            }
        }

        registro = CriaData();
        ProcessaDiaDaSemana(registro, diaSemana);
        scanf("%[^;]; ", data);
        ProcessaDiaMesAno(registro, data);
        scanf("%[^;]; ", horario);
        ProcessaHorario(registro, horario);
        scanf("%[^;]; ", data);

        sys->dataEntrada[(*sys).qtdRegistros] = registro;

        registro = CriaData();
        ProcessaDiaMesAno(registro, data);
        scanf("%[^\n]\n ", horario);
        ProcessaHorario(registro, horario);

        sys->dataSaida[(*sys).qtdRegistros] = registro;

        sys->qtdRegistros += 1;
    }
}

float CalculaPrecoTiquete(tSistema *sys, tData *dataEntrada, tData *dataSaida) {
    float valorPago = 0;



    return valorPago;
}

void ImprimeFaturamentoSistema(tSistema *sys) {
    int t;

    for (t = 0; t < (*sys).qtdRegistros; t++) {
        printf("O tiquete processado tem valor: %.2f reais\n", CalculaPrecoTiquete(sys, (*sys).dataEntrada[t], (*sys).dataSaida[t]));
        sys->faturamentoTotal += CalculaPrecoTiquete(sys, (*sys).dataEntrada[t], (*sys).dataSaida[t]);
    }
    printf("O sistema faturou: %.2f reais\n", (*sys).faturamentoTotal);
}

void DestroiSistema(tSistema *sys) {
    int t;

    if (sys != NULL) {
        if ((*sys).dataEntrada != NULL) {
            for (t = 0; t < (*sys).qtdRegistros; t++) {
                DestroiData((*sys).dataEntrada[t]);
            }
            free((*sys).dataEntrada);
            sys->dataEntrada = NULL;
        }
        if ((*sys).dataSaida != NULL) {
            for (t = 0; t < (*sys).qtdRegistros; t++) {
                DestroiData((*sys).dataSaida[t]);
            }
            free((*sys).dataSaida);
            sys->dataSaida = NULL;
        }
        free(sys);
        sys = NULL;
    }
}