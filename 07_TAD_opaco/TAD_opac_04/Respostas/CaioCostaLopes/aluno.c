#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

#define MAX_CARACTERES 51

struct Aluno {
    char *nome;
    int matricula;
    int n1, n2, n3;
};

tAluno *CriaAluno() {
    tAluno *aluno = (tAluno*)malloc(sizeof(tAluno));

    if (aluno == NULL) {
        printf("Erro na alocacao de memoria do aluno!\n");
        return aluno;
    }

    aluno->nome = NULL;
    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;

    return aluno;
}

void LeAluno(tAluno *aluno) {
    aluno->nome = (char*)malloc(MAX_CARACTERES * sizeof(char));

    if ((*aluno).nome == NULL) {
        printf("Erro na alocacao de memoria no nome do aluno!\n");
        ApagaAluno(aluno);
    }else{
        scanf("%s", aluno->nome);
        scanf("%03d", &aluno->matricula);
        scanf("%d %d %d", &aluno->n1, &aluno->n2, &aluno->n3);
    }
}

intComparaMatricula(tAluno *aluno1, tAluno *aluno2) {
    if ((*aluno1).matricula > (*aluno2).matricula) {
        return 1;
    }else {
        if ((*aluno1).matricula < (*aluno2).matricula) {
            return -1;
        }
    }
    return 0;
}

int CalculaMediaAluno(tAluno *aluno) {
    return (((*aluno).n1 + (*aluno).n2 + (*aluno).n3) / 3);
}

int VerificaAprovacao(tAluno *aluno) {
    return (CalculaMediaAluno(aluno) >= 7);
}

void ImprimeAluno(tAluno *aluno) {
    printf("%s\n", (*aluno).nome);
}

void ApagaAluno(tAluno *aluno) {
    if (aluno != NULL) {
        if ((*aluno).nome != NULL) {
            free((*aluno).nome);
            aluno->nome = NULL;
        }
        free(aluno);
        aluno = NULL;
    }
}