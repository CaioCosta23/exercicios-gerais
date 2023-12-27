#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

int main() {
    tLocadora locadora;
    char operacao[10];
    char opcoes[4][10] = {"Cadastrar", "Alugar", "Devolver", "Estoque"};
    int op;
    int sair = 0;

    locadora = criaLocadora();

    while(scanf("%s\n", operacao) == 1) {
        for (op = 0; op < 4; op++) {
            if (!(strcmp(operacao, opcoes[op]) == 0)) {
                sair = 1;
                break;
            }
        }
        if (sair) {
            break;
        }
        
        if ((strcmp(operacao, opcoes[0]) == 0)) {
            locadora = lerCadastroLocadora(locadora);
        }else {
            if ((strcmp(operacao, opcoes[1]) == 0)) {
                locadora = lerLocadoraAluguelLocadora(locadora);
            }else {
                if ((strcmp(operacao, opcoes[2]) == 0)) {
                    locadora = lerDevolucaoLocadora(locadora);
                }else {
                    if ((strcmp(operacao, opcoes[3]) == 0)) {
                        consultaEstoqueLocadora(locadora);
                    }
                }
            }
        }
    }
    consultaLucroLocadora(locadora);

    return 0;
}