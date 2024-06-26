#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

void OrdenaAprovados(tAluno aprovados[], int p) {
    int x, y;
    tAluno aux;

    for(x = 0; x < (p - 1); x++) {
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

    tAluno alunos[qtdAlunos];
    tAluno aprovados[qtdAlunos];

    for (a = 0; a < qtdAlunos; a++) {
        alunos[a] = LeAluno();
        if (VerificaAprovacao(alunos[a])) {
            aprovados[p] = alunos[a];
            p++;
        }
    }

    OrdenaAprovados(aprovados, p);

    for (i = 0; i < p; i++) {
        ImprimeAluno(aprovados[i]);
    }
    printf("\n");

    return 0;
}