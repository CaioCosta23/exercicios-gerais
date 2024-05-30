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
    int pc;
    char cartaoSUS[TAM_CSUS];
    int finalizar = 0;

    while(1) {
        scanf("%c\n", &acao);

        switch (acao) {
            case 'P':
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
                break;
            case 'L':
                scanf("%s", cartaoSUS);
                for (pc = 0; pc < (*p).qtdpacientes; pc++) {
                    if (!(strcmp(GetCartaoSusPaciente((*p).listapacientes[pc]), cartaoSUS))) {
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
                        AdicionaLesaoPaciente((*p).listapacientes[pc], lesao);
                    }
                }
                break;
            case 'F':
                finalizar = 1;
                break;
        }
        if (finalizar) {
            break;
        }
    }

}

void ImprimeRelatorioPad(tPad *p) {
    int l;
    tData *dataLimite = NULL;
    int somaIdades = 0, totalLesoes = 0, totalCirurgias = 0;

    dataLimite = CriaData(DIA_PAD, MES_PAD, ANO_PAD);

    printf("TOTAL PACIENTES: %d\n", (*p).qtdpacientes);
    for (l = 0; l < (*p).qtdpacientes; l++) {
        somaIdades += CalculaIdadeData(GetNascimentoPaciente((*p).listapacientes[l]), dataLimite);
        totalLesoes += GetQtdLesoesPaciente((*p).listapacientes[l]);
        totalCirurgias += GetQtdCirurgiasPaciente((*p).listapacientes[l]);
    }
    printf("MEDIA IDADE (ANOS): %d\n", (somaIdades / (*p).qtdpacientes));
    printf("TOTAL LESOES: %d\n", totalLesoes);
    printf("TOTAL CIRURGIAS: %d\n", totalCirurgias);
    printf("LISTA DE PACIENTES:\n");
    for (l = 0; l < (*p).qtdpacientes; l++) {
        ImprimePaciente((*p).listapacientes[l]);
    }

    LiberaData(dataLimite);
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