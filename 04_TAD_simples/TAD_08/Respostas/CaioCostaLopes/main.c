#include <stdio.h>
#include <stdlib.h>
#include "departamento.h"

tDepartamento AtribuiMediaGeralDepartamento(tDepartamento departamento) {
    departamento.media_geral = (float)calculaMediaGeralDepartamento(departamento);
    
    return departamento;
}

int main() {
    int qtdDepartamentos;
    char nome [STRING_MAX], diretor [STRING_MAX], c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];
    int m1, m2, m3, d;
    double desvioPadrao = 0.00;

    scanf("%d\n", &qtdDepartamentos);

    tDepartamento departamento[qtdDepartamentos];

    for (d = 0; d < qtdDepartamentos; d++) {
        scanf("%s", nome);
        scanf("%s", diretor);
        scanf("%s", c1);
        scanf("%s", c2);
        scanf("%s", c3);
        scanf("%d %d %d", m1, m2, m3);
        
        if ((!(validaMediaDepartamento(m1))) || (!(validaMediaDepartamento(m2))) || (!(validaMediaDepartamento(m3)))) {
            printf("Erro: A media m1, m2, e/ou m3 nao eh/sao valida(s)");
            exit(1);
        }
        departamento[d] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
        departamento[d] = AtribuiMediaGeralDepartamento(departamento[d]);
    }

    for (d = 0; d < qtdDepartamentos; d++) {
        desvioPadrao = calculaDesvioPadraoDepartamento(departamento[d]);
        printf("ATRIBUTOS:\n");
        imprimeAtributosDepartamento(departamento[d]);
        printf("desvio padrao => %.2f", desvioPadrao);
    }
    return 0;
}