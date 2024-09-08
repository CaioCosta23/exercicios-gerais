#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main() {
    int numeroAlunos;
    Aluno **alunos;

    printf("Digite o numero de alunos: ");
    scanf("%d", &numeroAlunos);

    alunos = CriaVetorAlunos(numeroAlunos);
    
    LeAlunos(alunos, numeroAlunos);
    SalvaAlunosBinario(alunos, "alunos.bin", numeroAlunos);

    LiberaAlunos(alunos, numeroAlunos);

    alunos = CriaVetorAlunos(numeroAlunos);
    
    CarregaAlunosBinario(alunos, "alunos.bin");
    ImprimeAlunos(alunos, numeroAlunos);

    LiberaAlunos(alunos, numeroAlunos);

    return 0;
}