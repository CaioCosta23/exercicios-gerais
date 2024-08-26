#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

#define MAX_CARACTERES_NOME 51

struct Aluno {
    char nome[MAX_CARACTERES_NOME];
    char genero;
    float nota;
};

tAluno *CriaAluno() {
    tAluno *aluno = (tAluno*)malloc(sizeof(tAluno));
    int n;

    if (aluno == NULL) {
        printf("Erro na alocacao de memoria do aluno ");
        return aluno;
    }

    for (n = 0; n < MAX_CARACTERES_NOME; n++) {
        aluno->nome[n] = '\0';
    }
    aluno->genero = '\0';
    aluno->nota = 0;

    return aluno;
}

void LeAluno(tAluno *aluno) {
    scanf("%[^;];%c;%f\n", aluno->nome, &aluno->genero, &aluno->nota);
}

char GetGeneroAluno(tAluno *aluno) {
    return (*aluno).genero;
}

float GetNotaAluno(tAluno *aluno) {
    return (*aluno).nota;
}

void DestroiAluno(data_type aluno) {
    if (aluno != NULL) {
        free(aluno);
        aluno = NULL;
    }
}