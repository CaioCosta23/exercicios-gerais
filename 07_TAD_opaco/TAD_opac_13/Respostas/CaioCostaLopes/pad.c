#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pad.h"

#define MAX_PACIENTES 100

struct pad {
    tPaciente *listaPacientes[100];
    int qtdPacientes;
};

void VerificaSituacaoLesao(tPad *pad, tLesao *lesao) {
    if (lesao == NULL) {
        LiberaPad(pad);
        exit(1);
    }
}

tPad *CriaPad() {
    tPad *pad = (tPad*)malloc(sizeof(tPad));

    if (pad == NULL) {
        printf("Erro na alocacao de memoria do P.A.D.!\n");
        exit(1);
    }

    pad->qtdPacientes = 0;

    return pad;
}

void RodaPad(tPad *p) {
    char acao;
    tLesao *lesao;
    char listaCartoes[MAX_PACIENTES][TAM_CSUS], cartaoSus[TAM_CSUS];
}