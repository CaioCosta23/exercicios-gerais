#include <stdio.h>
#include <stdlib.h>
#include "base_alunos.h"


#define TAMANHO_CAMINHO 1001

int main() {
    tBaseAlunos *baseDeAlunos;
    char caminho[1001];

    scanf("%s", caminho);
    
    baseDeAlunos = CriarBaseAlunos();

    LerBaseAlunos(baseDeAlunos, caminho);

    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(baseDeAlunos));

    DestruirBaseAlunos(baseDeAlunos);

    return 0;
}