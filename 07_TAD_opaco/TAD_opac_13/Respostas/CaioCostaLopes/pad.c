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

void VerificaSituacaoPaciente(tPad *pad) {
    if ((*pad).listaPacientes[(*pad).qtdPacientes] == NULL) {
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
    tLesao *lesao[QTD_LESAO * MAX_PACIENTES];
    char listaCartoes[MAX_PACIENTES][TAM_CSUS];
    int qtdCartoes = 0;
    int pc, ls;
    int pacienteEncontrado;

    while(1) {
        scanf("%c\n", &acao);

        if (acao == 'F') {
            break;
        }else {
            if (acao == 'P') {
                p->listaPacientes[(*p).qtdPacientes] = CriaPaciente();
                VerificaSituacaoPaciente(p);
                LePaciente(p);
                VerificaSituacaoPaciente(p);
            }else {
                if (acao == 'L') {
                    scanf("%[^\n]\n", listaCartoes[qtdCartoes]);
                    lesao[qtdCartoes] = CriaLesao();
                    VerificaSituacao(p, lesao[qtdCartoes]);
                    LeLesao(lesao[qtdCartoes]);
                    VerificaSituacaoLesao(p, lesao[qtdCartoes]);

                    qtdCartoes += 1;
                }
            }
        }
    }
    for (ls = 0; ls < qtdCartoes; ls++) {
        pacienteEncontrado = 0;
        for (pc = 0; pc < (*p).qtdPacientes; pc++) {
            if (!(strcmp(GetCartaoSusPaciente((*p).listaPacientes[pc]), listaCartoes[ls]))) {
                AdicionaLesaoPaciente((*p).listaPacientes[pc], lesao[ls]);
                pacienteEncontrado = 1;
            }
        }
        if (!(pacienteEncontrado)) {
            LiberaLesao(lesao[ls]);
        }
    }
}

void ImprimeRelatorioPad(tPad *p) {
    int l;
    int somaIdades, totalLesoes = 0, totalCirurgias = 0, mediaIdades = 0;

    if ((*p).qtdPacientes > 0) {
        tData *dataLimite = NULL;
        dataLimite = CriaData(DIA_PAD, MES_PAD, ANO_PAD);

        for (l = 0; l < (*p).qtdPacientes; l++) {
            somaIdades += CalculaIdadeData(GetNascimentoPaciente((*p).listaPacientes[l]), dataLimite);
            totalLesoes += GetQtdLesoesPaciente((*p).listaPacientes[l]);
            totalCirurgias += GetQtdCirurgias((*p).listaPacientes[l]);
        }
        mediaIdades = (somaIdades / (*p).qtdPacientes);
        LiberaData(dataLimite);
    }
    printf("TOTAL PACIENTES: %d\n", (*p).qtdPacientes);
    printf("MEDIA IDADE (ANOS): %d\n", mediaIdades);
    printf("TOTAL LESOES: %d\n", totalLesoes);
    printf("TOTAL CIRURGIAS: %d\n", totalCirurgias);
    printf("LISTA PACIENTES:\n");
    for (l = 0; l < (*p).qtdPacientes; l++) {
        ImprimePaciente((*p).listaPacientes[l]);
    }
}

void LiberaPad(tPad *p) {
    int l;
    if (p != NULL) {
        for (l = 0; l < (*p).qtdPacientes; l++) {
            LiberaPaciente((*p).listaPacientes[l]);
        }
        free(p);
        p = NULL;
    }
}