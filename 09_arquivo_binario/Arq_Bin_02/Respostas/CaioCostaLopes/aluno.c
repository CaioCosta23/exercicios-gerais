#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct Aluno {
    char *nome;
    char *dataNascimento;
    char *curso;
    int periodo;
    float CR;
};

#define TAMA_MAX_NOME 100
#define TAMA_MAX_DATA 11
#define TAMA_MAX_CURSO 50


tAluno *CriarAluno(char *nome, char *dataNascimento, char *curso, int periodo, float coeficienteRendimento) {
    tAluno *aluno = (tAluno*)malloc(sizeof(tAluno));

    if (aluno == NULL) {
        printf("Erro na alocacao de memoria do aluno! ");
        return aluno;
    }

    aluno->nome = (char*)calloc(TAMA_MAX_NOME, sizeof(char));
    if ((*aluno).nome == NULL) {
        printf("Erro na alocacao de memoria do nome do aluno!\n");
        DestruirAluno(aluno);
        return aluno;
    }

    aluno->dataNascimento = (char*)calloc(TAMA_MAX_DATA, sizeof(char));
    if ((*aluno).dataNascimento == NULL) {
        printf("Erro na alocacao de memoria da data de nascimento do aluno!\n");
        DestruirAluno(aluno);
        return aluno;
    }

    aluno->curso = (char*)calloc(TAMA_MAX_CURSO, sizeof(char));
    if ((*aluno).curso == NULL) {
        printf("Erro na alocacao de memoria do nome do curso do aluno!\n");
        DestruirAluno(aluno);
        return aluno;
    }

    strcpy(aluno->nome, nome);
    strcpy(aluno->dataNascimento, dataNascimento);
    strcpy(aluno->curso, curso);
    aluno->periodo = periodo;
    aluno->CR = coeficienteRendimento;

    return aluno;

}

tAluno *LeAluno(FILE *arquivo_binario) {
    tAluno *aluno;
    char nome[TAMA_MAX_CURSO], dataNascimento[TAMA_MAX_DATA], curso[TAMA_MAX_CURSO];
    int periodo;
    float CR;

    fread(nome, sizeof(char), TAMA_MAX_NOME, arquivo_binario);
    fread(dataNascimento, sizeof(char), TAMA_MAX_DATA, arquivo_binario);
    fread(curso, sizeof(char), TAMA_MAX_CURSO, arquivo_binario);
    fread(&periodo, sizeof(int), 1, arquivo_binario);
    fread(&CR, sizeof(float), 1, arquivo_binario);

    aluno = CriarAluno(nome, dataNascimento, curso, periodo, CR);
    
    return aluno;
}

float GetCoeficienteRendimentoAluno(tAluno *aluno) {
    return (*aluno).CR;
}

void DestruirAluno(tAluno *aluno) {
    if (aluno != NULL) {
        if ((*aluno).nome != NULL) {
            free((*aluno).nome);
            aluno->nome = NULL;
        }
        if ((*aluno).dataNascimento != NULL) {
            free((*aluno).dataNascimento);
            aluno->dataNascimento = NULL;
        }
        if ((*aluno).curso != NULL) {
            free((*aluno).curso);
            aluno->curso = NULL;
        }
        free(aluno);
        aluno = NULL;
    }
}
