#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

struct paciente {
    char *nome;
    tData *nascimento;
    char *cartaoSus;
    char genero;
    tLesao **listaLesoes;
    int qtdLesoes;
    int maxLesoes;
};

tPaciente *CriaPaciente() {
    tPaciente *paciente = (tPaciente*)malloc(sizeof(tPaciente));

    if (paciente == NULL) {
        printf("Erro na alocacao de memoria do paciente ");
        return paciente;
    }

    paciente->nome = (char*)malloc(TAM_NOME *sizeof(char));
    if ((*paciente).nome == NULL) {
        printf("Erro na alocacao de memoria no nome do paciente ");
        LiberaPaciente(paciente);
        return paciente;
    }

    paciente->nascimento = NULL;
    paciente->cartaoSus = (char*)malloc(TAM_CSUS * sizeof(char));
    if ((*paciente).cartaoSus == NULL) {
        printf("Erro na alocacao de memoria do cartao do SUS do paciente ");
        LiberaPaciente(paciente);
        return paciente;
    }

    paciente->genero = '\0';
    paciente->qtdLesoes = 0;
    paciente->maxLesoes = 0;
    paciente->listaLesoes = (tLesao**)malloc(QTD_LESAO * sizeof(tLesao*));
    if ((*paciente).listaLesoes ==  NULL) {
        printf("Erro na alocacao de memoria da lista/vetor de lesoes do paciente ");
        LiberaPaciente(paciente);
    }
    
    return paciente;
}

void LePaciente(tPaciente *p) {
    scanf("%[^\n]\n", p->nome);
    
    p->nascimento = LeData();

    if ((*p).nascimento != NULL) {
        scanf("%[^\n]\n", p->cartaoSus);
        scanf("%c", &p->genero);
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
        if (PrecisaCirurgiaLesao((*p).listaLesoes[l])) {
            qtdCirurgias += 1;
        }
    }
    return qtdCirurgias;
}

tData *GetNascimentoPaciente(tPaciente *p) {
    return (*p).nascimento;
}

void AdicionaLesaoPaciente(tPaciente *p, tLesao *l) {
    if (!((*p).maxLesoes)) {
        p->listaLesoes[(*p).qtdLesoes] = l;
        p->qtdLesoes += 1;

        if ((*p).qtdLesoes == QTD_LESAO) {
            p->maxLesoes = 1;
        }
    }
}

void ImprimePaciente(tPaciente *p) {
    int l;

    if ((*p).qtdLesoes > 0) {
        printf("- %s - ", (*p).nome);
        for (l = 0; l < (*p).qtdLesoes; l++) {
            printf("%s ", GetIdLesao((*p).listaLesoes[l]));
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
                    if ((*p).listaLesoes != NULL) {
                        for (l = 0; l < (*p).qtdLesoes; l++) {
                            LiberaLesao((*p).listaLesoes[l]);
                        }
                        free((*p).listaLesoes);
                        p->listaLesoes = NULL;
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