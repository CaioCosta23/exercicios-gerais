#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

#define TAM_STRING_OPERACAO 10
#define NUM_OPCOES 4


int main() {
    tLocadora *locadora;
    char parada = '\0';
    char operacao[TAM_STRING_OPERACAO];
    char opcoes[NUM_OPCOES][TAM_STRING_OPERACAO] = {"Cadastrar", "Alugar", "Devolver", "Estoque"};

    // Cria (aloca dinâmicamente) a locadora;
    locadora = CriarLocadora();

    // Lê a ação que o usuário deseja realizar;
    while(scanf("%s", operacao) == 1) {
        // verifica qual das 4 ações o usuário escolheu e através das funções abaixo as realiza;
        if (strcmp(operacao, opcoes[0]) == 0) {
            LerCadastroLocadora(locadora);
            printf("\n");

            // Verifica se o usuário deseja parar de cadastrar filmes (através do caractere de parada - '#');
            if ((scanf("%c", &parada) == 1) && (parada == '#')) {
                continue;
            }
        }
        if (strcmp(operacao, opcoes[1]) == 0) {
            LerAluguelLocadora(locadora);
            printf("\n");
            
            if ((scanf("%c", &parada) == 1) && (parada == '#')) {
                continue;
            }
        }
        if (strcmp(operacao, opcoes[2]) == 0) {
            LerDevolucaoLocadora(locadora);
            printf("\n");

            if((scanf("%c", &parada) == 1) && (parada == '#')) {
                continue;
            }
        }
        if (strcmp(operacao, opcoes[3]) == 0) {
            OrdenarFilmesLocadora(locadora);
            ConsultarEstoqueLocadora(locadora);

            if ((scanf("%c", &parada) == 1) && (parada == '#')) {
                continue;
            }
        }
    }
    // Exibe o lucro total que a locadora obteve com as ações;
    ConsultarLucroLocadora(locadora);
    
    // Destrói (desaloca) a locadora;
    DestruirLocadora(locadora);

    return 0;
}