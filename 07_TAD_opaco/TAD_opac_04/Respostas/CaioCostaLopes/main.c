#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

void OrdenaAprovados(tAluno *aprovados[], int qtdAprovados) {
    int x, y;
    tAluno *alunoAuxiliar;

    for (x = 0; x < (qtdAprovados - 1); x++) {
        for (y = x + 1; x < qtdAprovados; y++) {
            if (ComparaMatricula(aprovados[x], aprovados[y]) == 1) {
                alunoAuxiliar = aprovados[y];
                aprovados[y] = aprovados[x];
                aprovados[x] = alunoAuxiliar;
            }
        }
    }
}

void DesalocaMemoria(tAluno *alunos[], int qtdAlunos) {
    int a;

    for (a = 0; a < qtdAlunos; a++) {
        ApagaAluno(alunos[a]);
    }
}

int main () {
    int qtdAlunos;
    int a, i;
    int p = 0;

    scanf("%d\n", &qtdAlunos);

    tAluno *alunos[qtdAlunos];
    tAluno **aprovados =  NULL;

    for (a = 0; a < qtdAlunos; a++) {
        alunos[a] = CriaAluno();
        LeAluno(alunos[a]);

        if (VerificaAprovacao(alunos[a])) {
            if (p == 0) {
                aprovados = (tAluno**)malloc((p + 1) * sizeof(tAluno*));
                if (aprovados == NULL) {
                    printf("Erro na alocacao de memoria no vetor de aprovados!\n");
                    DesalocaMemoria(alunos, a);
                    exit(1);
                }
                p++;
            }else {
                aprovados = (tAluno**)realloc(aprovados, (p +1) * sizeof(tAluno*));
                if (aprovados == NULL) {
                    printf("Erro na realocacao de memoria no vetor de aprovados!\n");
                    DesalocaMemoria(aprovados, p);
                    DesalocaMemoria(alunos, a);
                    exit(1);
                }
            }
            aprovados[p] = alunos[a];
            p++;
        }
    }

    OrdenaAprovados(aprovados, p);

    for (i = 0; i < p; i++) {
        ImprimeAluno(aprovados[i]);
    }
    printf("\n");

    DesalocaMemoria(alunos, qtdAlunos);
    free(aprovados);

    return 0;
}