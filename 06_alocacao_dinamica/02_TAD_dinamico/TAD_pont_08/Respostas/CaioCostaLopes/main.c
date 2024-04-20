#include <stdio.h>
#include <stdlib.h>
#include "departamento.h"

int main() {
    int qtdDepartamentos, d, l;
    char nome[STRING_MAX], diretor[STRING_MAX], curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX];
    int media1, media2, media3;

    scanf("%d\n", &qtdDepartamentos);

    tDepartamento *departamento[qtdDepartamentos];

    for (d = 0; d < qtdDepartamentos; d++) {
        
        scanf("%s", nome);
        scanf("%s", diretor);
        scanf("%s", curso1);
        scanf("%s", curso2);
        scanf("%s", curso3);
        scanf("%d %d %d", &media1, &media2, &media3);

        if ((!(ValidaMediaDepartamento(media1)) || (!(ValidaMediaDepartamento(media2)) || (!(ValidaMediaDepartamento(media3)))))) {
            printf("Erro: A media m1, m2, e/ou m3 nao eh/sao valida(s)");
            for (l = 0; l < d; l++) {
                LiberaMemoriaDepartamento(departamento[l]);
            }
            exit(1);
        }
        departamento[d] = CriaDepartamento();
        PreencheDadosDepartamento(departamento[d], curso1, curso2, curso3, nome, media1, media2, media3, diretor);
    }

    OrdenaPorMediaDepartamentos(departamento, qtdDepartamentos);

    for (d = 0; d < qtdDepartamentos; d++) {
        ImprimeAtributosDepartamento(departamento[d]);
    }
    for (d = 0; d < qtdDepartamentos; d++) {
        LiberaMemoriaDepartamento(departamento[d]);
    }

    return 0;
}