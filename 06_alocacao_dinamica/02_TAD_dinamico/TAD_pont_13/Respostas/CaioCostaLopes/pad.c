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
                lesao = CriaLesao();
                if (lesao == NULL) {
                    printf("%d!\n", ((*p).qtdpacientes + 1));
                    LiberaPad(p);
                    exit(1);
                }
                
                scanf("%s", cartaoSUS);
                LeLesao(lesao);
                if (lesao == NULL) {
                    printf("%d!\n", ((*p).qtdpacientes + 1));
                    LiberaPad(p);
                    exit(1);
                }
                for (pc = 0; pc < (*p).qtdpacientes; pc++) {
                    if (!(strcmp(GetCartaoSusPaciente(p), cartaoSUS))) {
                        AdicionaLesaoPaciente((*p).listapacientes[pc], lesao);
                    }
                }
            case 'F':
                finalizar = 1;
        }
        if (finalizar) {
            break;
        }
    }

}

void ImprimeRelatorioPad(tPad *p) {
    int l;

    printf("TOTAL PACIENTES %d\n", (*p).listapacientes);
    for (l = 0; l < (*p).listapacientes; l++) {
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