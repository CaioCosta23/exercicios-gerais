#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pad.h"

#define MAX_PACIENTES 100

void VerificaSituacaoLesao(tPad *pad, tLesao *lesao) {
    if (lesao == NULL) {
        LiberaPad(pad);
        exit(1);
    }
}

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
    tLesao *lesao[QTD_LESAO * MAX_PACIENTES];
    char listaCartoes[MAX_PACIENTES][TAM_CSUS], cartaoSus[TAM_CSUS];
    int quantCartoes = 0;
    int pc, ls;
    int pacienteEncontrado;

    while (1) {
        scanf("%c\n", &acao);

        if (acao == 'F') {
            break;
        }else {
            if (acao == 'P') {
                p->listapacientes[(*p).qtdpacientes] = CriaPaciente();
                if ((*p).listapacientes == NULL) {
                    printf("%d!", ((*p).qtdpacientes + 1));
                    LiberaPad(p);
                    exit(1);
                }
                LePaciente((*p).listapacientes[(*p).qtdpacientes]);
                if ((*p).listapacientes[(*p).qtdpacientes] == NULL) {
                    printf("%d!", ((*p).qtdpacientes + 1));
                    LiberaPad(p);
                    exit(1);
                }
                (*p).qtdpacientes += 1;
            }else {
                if (acao == 'L') {
                    scanf("%[^\n]\n", cartaoSus);
                        
                    strcpy(listaCartoes[quantCartoes], cartaoSus);
                    lesao[quantCartoes] = CriaLesao();
                    VerificaSituacaoLesao(p, lesao[quantCartoes]);
                    LeLesao(lesao[quantCartoes]);
                    VerificaSituacaoLesao(p, lesao[quantCartoes]);

                    quantCartoes += 1;
                }
            }
        }
    }
    for (ls = 0; ls < quantCartoes; ls++) {
        pacienteEncontrado = 0;
        for (pc = 0; pc < (*p).qtdpacientes; pc++) {
            if (!(strcmp(GetCartaoSusPaciente((*p).listapacientes[pc]), listaCartoes[ls]))) {
                AdicionaLesaoPaciente((*p).listapacientes[pc], lesao[ls]);
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