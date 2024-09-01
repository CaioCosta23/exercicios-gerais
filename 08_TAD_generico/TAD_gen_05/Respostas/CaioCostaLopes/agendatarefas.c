#include <stdio.h>
#include <stdlib.h>
#include "agendatarefas.h"

typedef void (*executar)(void *);
typedef void (*destruir)(void *);

struct agendatarefas {
    void **tarefas;
    int *prioridade;
    executar *executar;
    destruir *destruir;
    int qtdTarefas;
    int maxTarefas;
};

tAgendaTarefas *CriaAgendaDeTarefas(int numElem) {
    tAgendaTarefas *agendaTarefas = (tAgendaTarefas*)malloc(sizeof(tAgendaTarefas));

    if (agendaTarefas == NULL) {
        printf("Erro na alocacao de memoria da agenda de tarefas!\n");
        exit(1);
    }

    agendaTarefas->tarefas = (void**)malooc(numElem * sizeof(void*));
    if ((*agendaTarefas).tarefas == NULL) {
        printf("Erro na alocacao de memoria do vetor de tarefas da agenda de tarefas!\n");
        DestroiAgendaDeTarefas(agendaTarefas);
        exit(1);
    }

    agendaTarefas->prioridade = (int*)malloc(numElem * sizeof(int));
    if ((*agendaTarefas).prioridade == NULL) {
        printf("Erro na alocacao de memoria do vetor de prioridades da agenda de tarefas!\n");
        DestroiAgendaDeTarefas(agendaTarefas);
        exit(1);
    }

    agendaTarefas->executar = (executar*)malloc(numElem * sizeof(executar));
    if ((*agendaTarefas).executar == NULL) {
        printf("Erro na alocacao de memoria da execução da agenda de tarefas!\n");
        DestroiAgendaDeTarefas(agendaTarefas);
        exit(1);
    }
    agendaTarefas->destruir = (destruir*)malloc(numElem * sizeof(destruir));
    if ((*agendaTarefas).destruir == NULL) {
        printf("Erro na alocacao de memoria da execução da agenda de tarefas!\n");
        DestroiAgendaDeTarefas(agendaTarefas);
        exit(1);
    }

    agendaTarefas->qtdTarefas = 0;
    agendaTarefas->maxTarefas = numElem;

    return agendaTarefas;
}

void CadastraTarefaNaAgenda(tAgendaTarefas *tar, int prioridade, void *tarefa, void (*executa)(void *), void (*destroi)(void *)) {
    tar->tarefas[(*tar).qtdTarefas] = tarefa;
    tar->prioridade[(*tar).qtdTarefas];
    tar->executar[(*tar).qtdTarefas] = executa;
    tar->destruir[(*tar).qtdTarefas] = destroi;
    tar->qtdTarefas += 1;
}

void ExecutarTarefasDaAgenda(tAgendaTarefas *tar) {
    int t1, t2, prioridadeAuxiliar, t;
    void *tarefaAuxiliar;
    executar *execucaoAuxiliar;
    destruir *destruicaoAuxiliar;

    for (t1 = 0; t1 < ((*tar).qtdTarefas - 1); t1++) {
        for (t2 = t1 + 1; t2 < (*tar).qtdTarefas; t2++) {
            if ((*tar).prioridade[t1] > (*tar).prioridade[t2]) {
                tarefaAuxiliar = (*tar).tarefas[t1];
                tar->tarefas[t1] = (*tar).tarefas[t2];
                tar->tarefas[t2] = tarefaAuxiliar;

                prioridadeAuxiliar = (*tar).prioridade[t1];
                tar->prioridade[t1] = (*tar).prioridade[t2];
                tar->prioridade[t2] = prioridadeAuxiliar;

                execucaoAuxiliar = (*tar).executar[t1];
                tar->executar[t1] = (*tar).executar[t2];
                tar->executar[t2] = execucaoAuxiliar;

                destruicaoAuxiliar = (*tar).destruir[t1];
                tar->destruir[t1] = (*tar).destruir[t2];
                tar->destruir[t2] = destruicaoAuxiliar;   
            }
        }
    }
    for (t = 0; t < (*tar).qtdTarefas; t++) {
        tar->executar[t]((*tar).tarefas[t]);
        tar->destruir[t]((*tar).tarefas[t]);
    }
}

void DestroiAgendaTarefas(tAgendaTarefas *tar) {
    if (tar != NULL) {
        if ((*tar).prioridade != NULL) {
            free((*tar).prioridade);
            tar->prioridade = NULL;
        }
        if ((*tar).tarefas != NULL) {
            free((*tar).tarefas);
            tar->tarefas = NULL;
        }
        if ((*tar).executar != NULL) {
            free((*tar).executar);
            tar->executar = NULL;
        }
        if ((*tar).destruir != NULL) {
            free((*tar).destruir);
            tar->destruir = NULL;
        }
        free(tar);
        tar = NULL;
    }
}