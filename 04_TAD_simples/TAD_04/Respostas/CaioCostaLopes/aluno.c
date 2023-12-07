#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define MAX_CARACTERES 50

tAluno CriaAluno(char nome[], int matricula, int n1, int n2, int n3) {
    tAluno aluno;

    strcpy(aluno.nome, nome);
    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;

    return aluno;
}

tAluno LeAluno() {
    char nome[MAX_CARACTERES];
    int matricula, n1, n2, n3;
    tAluno aluno;

    scanf("%49s", nome);
    scanf("%03d", &matricula);
    scanf("%d %d %d", &n1, &n2, &n3);

    aluno = CriaAluno(nome, matricula, n1, n2, n3);

    return aluno;
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2) {
    if (aluno1.matricula > aluno2.matricula) {
        return 1;
    }else {
        if (aluno1.matricula < aluno2.matricula) {
            return -1;
        }
    }

    return 0;
}

int CalculaMediaAluno(tAluno aluno) {
    return ((aluno.n1 + aluno.n2 + aluno.n3) / 3);
}

int VerificaAprovacao(tAluno aluno) {
    int media = 0;

    media = CalculaMediaAluno(aluno);

    return (media >= 7);
}

void ImprimeAluno(tAluno aluno) {
    printf("%s\n", aluno.nome);
}