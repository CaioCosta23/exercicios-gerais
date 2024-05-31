#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

tPaciente *CriaPaciente() {
    tPaciente *paciente = (tPaciente*)malloc(sizeof(tPaciente));

    if (paciente == NULL) {
        printf("Erro na alocacao do paciente ");
        return paciente;
    }

    paciente->nome = (char*)malloc(TAM_NOME * sizeof(char));
    if ((*paciente).nome == NULL) {
        printf("Erro na alocacao do nome do paciente ");
        LiberaPaciente(paciente);
        return paciente;
    }

    paciente->nascimento = NULL;
    paciente->cartaoSus = (char*)malloc(TAM_CSUS * sizeof(char));
    if ((*paciente).cartaoSus == NULL) {
        printf("Erro na alocacao do cartao do SUS do paciente ");
        LiberaPaciente(paciente);
        return paciente;
    }
    paciente->genero = '\0';
    paciente->listaLesao = (tLesao**)malloc(QTD_LESAO * sizeof(tLesao*));
    if ((*paciente).listaLesao == NULL) {
        printf("Erro na alocacao da lista de lesoes do paciente ");
        LiberaPaciente(paciente);
        return paciente;
    }
    
    paciente->qtdLesoes = 0;
    paciente->maxLesoes = 0;

    return paciente;
}

void LePaciente(tPaciente *p) {

    scanf("%[^\n]\n", p->nome);

    p->nascimento = LeData();

    if (p->nascimento != NULL) {
        scanf("%[^\n]\n", p->cartaoSus);
        scanf("%c", &p->genero);
    }
}

void AdicionaLesaoPaciente(tPaciente *p, tLesao *l) {
    if (!((*p).maxLesoes)) {
        p->listaLesao[(*p).qtdLesoes] = l;
        p->qtdLesoes += 1;

        if ((*p).qtdLesoes == QTD_LESAO) {
            p->maxLesoes = 1;
        }
    }
}

char *GetCartaoSusPaciente(tPaciente *p) {
    return (*p).cartaoSus;
}

int GetQtdLesoesPaciente(tPaciente *p) {
    return (*p).qtdLesoes;
}

int GetQtdCirurgiasPaciente(tPaciente *p) {
    int l;
    int qtdCirurgias = 0;

    for (l = 0; l < (*p).qtdLesoes; l++) {
        if (PrecisaCirurgiaLesao((*p).listaLesao[l])) {
            qtdCirurgias += 1;
        }
    }
    return qtdCirurgias;
}

tData *GetNascimentoPaciente(tPaciente *p) {
    return (*p).nascimento;
}

void ImprimePaciente(tPaciente *p) {
    int l;

    if ((*p).qtdLesoes > 0) {
        printf("- %s - ", (*p).nome);
        for (l = 0; l < (*p).qtdLesoes; l++) {
            printf("%s ", GetIdLesao((*p).listaLesao[l]));
        }
        printf("\n");
    }
}

void LiberaPaciente(tPaciente *p) {
    int l;

    if (p != NULL) {
        if ((*p).nome != NULL) {
            if ((*p).nascimento != NULL) {
                if ((*p).cartaoSus != NULL) {
                    if ((*p).listaLesao != NULL) {
                        for (l = 0; l < (*p).qtdLesoes; l++) {
                            LiberaLesao((*p).listaLesao[l]);
                        }
                        free((*p).listaLesao);
                        p->listaLesao = NULL;
                    }
                    free((*p).cartaoSus);
                    p->cartaoSus = NULL;
                }
                LiberaData((*p).nascimento);
            }
            free((*p).nome);
            p->nome = NULL;
        }
        free(p);
        p = NULL;
    }
}