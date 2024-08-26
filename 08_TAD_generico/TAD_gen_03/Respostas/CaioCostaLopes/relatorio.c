#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"

#define MASCULINO 'M'
#define FEMININO 'F'
#define OUTROS 'O'

#define APROVACAO 6

void ImprimeRelatorio(Vector *alunos) {
    int v;
    float somaNotas = 0, aprovadosMasculinos = 0, aprovadosFemininos = 0, aprovadosOutros = 0;

    for (v = 0; v < VectorSize(alunos); v++) {
        somaNotas += GetNotaAluno(VectorGet(alunos, v));

        if (GetNotaAluno(VectorGet(alunos, v)) >= APROVACAO) { 
        }

        if (GetGeneroAluno(VectorGet(alunos, v)) == MASCULINO) {
                aprovadosMasculinos += 1;
            }else {
                if (GetGeneroAluno(VectorGet(alunos, v)) == FEMININO) {
                    aprovadosFemininos += 1;
                }else {
                    if (GetGeneroAluno(VectorGet(alunos, v)) == OUTROS) {
                        aprovadosOutros += 1;
                    }
                }
            }
    }
    printf("Media das notas: %.2f\n", (somaNotas / VectorSize(alunos)));
    printf("Porcentagem de alunos aprovados: %.2f\n", (((aprovadosMasculinos + aprovadosFemininos + aprovadosOutros) / (float)VectorSize(alunos)) * 100));
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f\n", ((aprovadosMasculinos / (float)VectorSize(alunos)) * 100));
    printf("Feminino: %.2f\n", ((aprovadosFemininos / (float)VectorSize(alunos)) * 100));
    printf("Outros: %.2f\n", ((aprovadosOutros / (float)VectorSize(alunos)) * 100));
    
}