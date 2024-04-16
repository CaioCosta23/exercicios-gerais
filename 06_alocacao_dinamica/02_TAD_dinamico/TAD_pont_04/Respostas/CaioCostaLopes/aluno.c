#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

#define MAX_CARACTERES 51

tAluno *CriaAluno() {
    tAluno *aluno = (tAluno*)malloc(sizeof(tAluno));

    if (aluno == NULL) {
        printf("Erro na alocacao do aluno\n");
        return aluno;
    }

    // Inicializa campos do aluno;

    aluno->nome = NULL;
    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;

    return aluno;
}

void LeAluno(tAluno *aluno) {
    // aloca dinâmicamente o nome do aluno;
    aluno->nome = (char*)malloc(MAX_CARACTERES * sizeof(char));

    if ((*aluno).nome == NULL) {
        printf("Erro na alocacao do nome do aluno!\n");
        aluno = NULL;
    }else {
        scanf("%s", aluno->nome);
        scanf("%03d", &aluno->matricula);
        scanf("%d %d %d", &aluno->n1, &aluno->n2, &aluno->n3);
    }
}

int ComparaMatricula(tAluno *aluno1, tAluno * aluno2) {
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
    int media = 0;

    media = CalculaMediaAluno(aluno);

    return (media >= 7);
}

void ImprimeAluno(tAluno *aluno) {
    printf("%s\n", (*aluno).nome);
}

void ApagaAluno(tAluno *aluno) {
    // Libera a memória alocada para o nome do aluno e o aluno;
    free(aluno->nome);
    free(aluno);
}
