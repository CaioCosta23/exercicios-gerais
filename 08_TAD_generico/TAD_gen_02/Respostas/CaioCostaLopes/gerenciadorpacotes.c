#include <stdio.h>
#include <stdlib.h>
#include "gerenciadorpacotes.h"

#define QTD_INICIAL_PACOTES 50

struct gerenciadorpacotes {
    tPacote **pacotes;
    int qtdPacotes;
    int maxPacotes;
};

tGerenciador *CriaGerenciador() {
    tGerenciador *gerenciador = (tGerenciador*)malloc(sizeof(tGerenciador));

    if (gerenciador == NULL) {
        printf("Erro de alocacao de memoria do gerenciador!\n");
        exit(1);
    }

    gerenciador->pacotes = (tPacote**)malloc(QTD_INICIAL_PACOTES * sizeof(tPacote*));
    if ((*gerenciador).pacotes == NULL) {
        printf("Erro de alocacao de memoria na lista/vetor de pacotes!\n");
        DestroiGerenciador(gerenciador);
        exit(1);
    }

    gerenciador->qtdPacotes = 0;
    gerenciador->maxPacotes = QTD_INICIAL_PACOTES;

    return gerenciador;
}

void AdicionaPacoteNoGerenciador(tGerenciador *geren, tPacote *pac) {
    if ((*geren).qtdPacotes == (*geren).maxPacotes) {
        geren->maxPacotes += QTD_INICIAL_PACOTES;
        geren->pacotes = (tPacote**)realloc((*geren).pacotes, (*geren).maxPacotes * sizeof(tPacote*));
        if ((*geren).pacotes == NULL) {
            printf("Erro na realocacao de memoria do vetor de pacotes do gerenciador!\n");
            DestroiGerenciador(geren);
            DestroiPacote(pac);
            exit(1);
        }
    }
    geren->pacotes[(*geren).qtdPacotes] = pac;
    geren->qtdPacotes += 1;
}

void ImprimirPacoteNoIndice(tGerenciador *geren, int idx) {
    ImprimePacote((*geren).pacotes[idx]);
}

void ImprimirTodosPacotes(tGerenciador *geren) {
    int p;

    for (p = 0; p < (*geren).qtdPacotes; p++) {
        ImprimirPacoteNoIndice(geren, p);
    }
}

void DestroiGerenciador(tGerenciador *geren) {
    int p;

    if (geren != NULL) {
        if ((*geren).pacotes != NULL) {
            for (p = 0; p < (*geren).qtdPacotes; p++) {
                DestroiPacote((*geren).pacotes[p]);
            }
            free((*geren).pacotes);
            geren->pacotes = NULL;
        }
        free(geren);
        geren = NULL;
    }
}