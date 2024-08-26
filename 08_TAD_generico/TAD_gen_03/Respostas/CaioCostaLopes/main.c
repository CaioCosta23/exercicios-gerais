#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "relatorio.h"

int main() {
    int qtdAlunos, a;
    tAluno *aluno;
    Vector *vetorAlunos;

    scanf("%d", &qtdAlunos);

    vetorAlunos = VectorConstruct();

    for (a = 0; a < qtdAlunos; a++) {
        aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(vetorAlunos, aluno);
    }
    ImprimeRelatorio(vetorAlunos);
    
    VectorDestroy(vetorAlunos, DestroiAluno);

    return 0;
}