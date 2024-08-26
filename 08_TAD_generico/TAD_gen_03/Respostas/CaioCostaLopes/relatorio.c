#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"
#include "aluno.h"

#define MASCULINO 'M'
#define FEMININO 'F'
#define OUTROS 'O'

#define APROVACAO 6

void ImprimeRelatorio(Vector *alunos) {
    int v;
    float somaNotas = 0, aprovados = 0, alunosMasculinos = 0, alunosFemininos = 0, outros = 0;

    for (v = 0; v < VectorSize(alunos); v++) {
        somaNotas += GetNotaAluno(VectorGet(alunos, v));

        if (GetNotaAluno(VectorGet(alunos, v)) >= APROVACAO) { 
            aprovados += 1;
        }

        if (GetGeneroAluno(VectorGet(alunos, v)) == MASCULINO) {
                alunosMasculinos += 1;
        }else {
            if (GetGeneroAluno(VectorGet(alunos, v)) == FEMININO) {
                alunosFemininos += 1;
            }else {
                if (GetGeneroAluno(VectorGet(alunos, v)) == OUTROS) {
                    outros += 1;
                }
            }
        }
    }
    printf("Media das notas: %.2f\n", (somaNotas / VectorSize(alunos)));
    printf("Porcentagem de alunos aprovados: %.2f%\n", (((float)aprovados / (float)VectorSize(alunos)) * 100));
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%\n", (((float)alunosMasculinos / (float)VectorSize(alunos)) * (float)100));
    printf("Feminino: %.2f%\n", (((float)alunosFemininos / (float)VectorSize(alunos)) * (float)100));
    printf("Outro: %.2f%\n", (((float)outros / (float)VectorSize(alunos)) * (float)100));
    
}