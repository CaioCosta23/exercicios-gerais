#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pad.h"

#define MAX_PACIENTES 100

tPad *CriaPad() {
    tPad *pad = (tPad*)malloc(sizeof(tPad));
    int p;

    if (pad == NULL) {
        printf("Erro na alocacao de memoria do pad!\n");
        exit(1);
    }

    pad->qtdpacientes = 0;

    for (p = 0; p < MAX_PACIENTES; p++) {
        pad->listapacientes[p] = NULL;
    }
    return pad;
}

void RodaPad(tPad *p) {
    char acao;
    tLesao *lesao = NULL;
    int pc, l;
    char cartaoSUS[TAM_CSUS][MAX_PACIENTES];
    int cs = 0;
    int encontrado;

    while(1) {
        scanf("%c\n", &acao);

        if (acao == 'F') {
            break;
        }

        if (acao == 'P') {
            p->listapacientes[(*p).qtdpacientes] = CriaPaciente();
            if ((*p).listapacientes[(*p).qtdpacientes] == NULL) {
                printf("%d!\n", ((*p).qtdpacientes) + 1);
                LiberaPad(p);
                exit(1);
            }
            
            LePaciente((*p).listapacientes[(*p).qtdpacientes]);
            if ((*p).listapacientes[(*p).qtdpacientes] == NULL) {
                printf("%d!\n", ((*p).qtdpacientes) + 1);
                LiberaPad(p);
                exit(1);
            }
            p->qtdpacientes += 1;
        }
        if (acao == 'L') {
            scanf("%s\n", cartaoSUS);
            lesao = CriaLesao();
            if (lesao == NULL) {
                printf("%d!\n", ((*p).qtdpacientes + 1));
                LiberaPad(p);
                exit(1);
            }

            LeLesao(lesao);
            if (lesao == NULL) {
                printf("%d!\n", ((*p).qtdpacientes + 1));
                LiberaPad(p);
                exit(1);
            }
            cs += 1;
        }
    }

}

void ImprimeRelatorioPad(tPad *p) {
    int l;
    int somaIdades = 0, totalLesoes = 0, totalCirurgias = 0, mediaIdades = 0;

    if ((*p).qtdpacientes > 0) {
        tData *dataLimite = NULL;
        dataLimite = CriaData(DIA_PAD, MES_PAD, ANO_PAD);

        for (l = 0; l < (*p).qtdpacientes; l++) {
            somaIdades += CalculaIdadeData(GetNascimentoPaciente((*p).listapacientes[l]), dataLimite);
            totalLesoes += GetQtdLesoesPaciente((*p).listapacientes[l]);
            totalCirurgias += GetQtdCirurgiasPaciente((*p).listapacientes[l]);
        }
        mediaIdades = (somaIdades / (*p).qtdpacientes);
        LiberaData(dataLimite);
    }
    printf("TOTAL PACIENTES: %d\n", (*p).qtdpacientes);
    printf("MEDIA IDADE (ANOS): %d\n", mediaIdades);
    printf("TOTAL LESOES: %d\n", totalLesoes);
    printf("TOTAL CIRURGIAS: %d\n", totalCirurgias);
    printf("LISTA DE PACIENTES:\n");
    for (l = 0; l < (*p).qtdpacientes; l++) {
        ImprimePaciente((*p).listapacientes[l]);
    }
}

void LiberaPad(tPad *p) {
    int l;

    if (p != NULL) {
        for (l = 0; l < (*p).qtdpacientes; l++) {
            LiberaPaciente((*p).listapacientes[l]);
        }
        free(p);
        p = NULL;
    }
}