#include <stdio.h>
#include <stdlib.h>
#include "base_alunos.h"
#include "aluno.h"

#define QTD_INICIAL_ALUNOS 5

struct BaseAlunos {
    tAluno **alunos;
    int qtdAlunos;
    int maxAlunos;
};

tBaseAlunos *CriarBaseAlunos() {
    tBaseAlunos *baseDeAlunos = (tBaseAlunos*)malloc(sizeof(tBaseAlunos));

    if (baseDeAlunos == NULL) {
        printf("Erro na alocacao de memoria da base de dados dos alunos!\n");
        exit(1);
    }

    baseDeAlunos->alunos = (tAluno**)malloc(QTD_INICIAL_ALUNOS * sizeof(tAluno*));
    if ((*baseDeAlunos).alunos == NULL) {
        printf("Erro na alocacao de memoria do vetor da base de dados do aluno!\n");
        DestruirBaseAlunos(baseDeAlunos);
        exit(1);
    }

    baseDeAlunos->qtdAlunos = 0;
    baseDeAlunos->maxAlunos = QTD_INICIAL_ALUNOS;

    return baseDeAlunos;
}

void LerBaseAlunos(tBaseAlunos *baseAlunos, char *nomeArquivo) {
    FILE *arquivo;

    arquivo = fopen(nomeArquivo, "rb");

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo binário que contém os dados do programa!\n");
        DestruirBaseAlunos(baseAlunos);
        exit(1);
    }

    fread(&baseAlunos->qtdAlunos, sizeof(int), 1, arquivo);
    
    if ((*baseAlunos).qtdAlunos > (*baseAlunos).maxAlunos) {
        baseAlunos->alunos = (tAluno**)realloc((*baseAlunos).alunos, (*baseAlunos).qtdAlunos * sizeof(tAluno*));
        if ((*baseAlunos).alunos == NULL) {
            printf("Erro na realocacao de memoria do vetor de alunos da base de dados de alunos!\n");
            DestruirBaseAlunos(baseAlunos);
            fclose(arquivo);
            exit(1);
        }
    }
    
    int a;

    for (a = 0; a < (*baseAlunos).qtdAlunos; a++) {
        baseAlunos->alunos[a] = LeAluno(arquivo);
    }
    fclose(arquivo);
}

float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos *baseAlunos) {
    int a;
    float coeficienteMedio = 0;

    for (a = 0; a < (*baseAlunos).qtdAlunos; a++) {
        coeficienteMedio += GetCoeficienteRendimentoAluno((*baseAlunos).alunos[a]);
    }
    return ((float)coeficienteMedio / (float)(*baseAlunos).qtdAlunos);
}

void DestruirBaseAlunos(tBaseAlunos *baseAlunos) {
    int a;

    if (baseAlunos != NULL) {
        if ((*baseAlunos).alunos != NULL) {
            for (a = 0; a < (*baseAlunos).qtdAlunos; a++) {
                DestruirAluno((*baseAlunos).alunos[a]);
            }
            free((*baseAlunos).alunos);
            baseAlunos->alunos = NULL;
        }
        free(baseAlunos);
        baseAlunos = NULL;
    } 
}