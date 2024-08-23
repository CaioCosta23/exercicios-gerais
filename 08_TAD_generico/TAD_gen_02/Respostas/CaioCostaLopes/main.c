#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gerenciadorpacotes.h"

int main() {
    int opcao, tipoElementos, numeroElementos, indiceListaPacotes;
    tGerenciador *gerenciador;
    tPacote *pacote;
    bool programaEncerrado = false;

    printf("tad_gen_02\n\n");

    gerenciador = CriaGerenciador();

    while (1) {
        printf("Escolha uma opcao:\n");
        printf("(1) Cadastrar um novo pacote\n");
        printf("(2) Imprimir um pacote especifico\n");
        printf("(3) Imprimir todos os pacotes e sair\n");

        scanf("%d\n", &opcao);
        
        switch(opcao) {
            case 1:
                scanf("%d %d", &tipoElementos, &numeroElementos);
                pacote = CriaPacote(tipoElementos, numeroElementos);
                LePacote(pacote);
                AdicionaPacoteNoGerenciador(gerenciador, pacote);
                break;
            case 2:
                scanf("%d", &indiceListaPacotes);
                ImprimirPacoteNoIndice(gerenciador, indiceListaPacotes);
                break;
            case 3:
                ImprimirTodosPacotes(gerenciador);
                programaEncerrado = true;
                break;
            default:
                printf("Opcao inexistente! Digite apenas 1, 2 ou 3!\n");
                break;
        }
        if (programaEncerrado == true) {
            break;
        }
    }

    DestroiGerenciador(gerenciador);

    return 0;
}