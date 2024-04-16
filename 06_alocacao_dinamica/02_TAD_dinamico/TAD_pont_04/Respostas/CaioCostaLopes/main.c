#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

void OrdenaAprovados(tAluno *aprovados[], int p) {
    int x, y;
    int *aux;

    for (x = 0; x < (p - 1); x++) {
        for (y = x + 1; y < p; y++) {
            if (ComparaMatricula(aprovados[x], aprovados[y]) == 1) {
                aux = aprovados[y];
                aprovados[y] = aprovados[x];
                aprovados[x] = aux;
            }
        }
    }
}


int main() {
    int qtdAlunos;
    int a, i;
    int p = 0;

    scanf("%d\n", &qtdAlunos);

    tAluno **alunos = (tAluno**)malloc(qtdAlunos * sizeof(tAluno*));
    if (alunos == NULL) {
        printf("Erro na alocacao do vetor de alunos!\n");
        exit(1);
    }

    tAluno **aprovados = (tAluno**)malloc(qtdAlunos * sizeof(tAluno*));
    if (aprovados == NULL) {
        printf("Erro na alocacao do vertor de alunos dos aprovados");
    }

    for (a = 0; a < qtdAlunos; a++) {
        alunos[a] = CriaAluno();
        LeAluno(alunos[a]);

        if (VerificaAprovacao(alunos[a])) {
            aprovados[p] = alunos[a];
            p++;
        }
    }

    aprovados = (tAluno **)realloc(aprovados, p * (sizeof(tAluno*)));

    OrdenaAprovados(aprovados, p);

    for (i = 0; i < p; i++) {
        ImprimeAluno(aprovados[i]);
    }
    printf("\n");

    for (a = 0; a < qtdAlunos; a++) {
        ApagaAluno(alunos[a]);
    }
    free(alunos);
    free(aprovados);

    return 0;
}