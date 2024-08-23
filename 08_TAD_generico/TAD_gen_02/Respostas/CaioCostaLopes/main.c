#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gerenciadorpacotes.h"

int main() {
    int opcao, tipoElementos, numeroElementos, indiceListaPacotes;
    tGerenciador *gerenciador;
    tPacote *pacote;
    bool programaEncerrado = false;

    printf("tad_gen_02\n");

    gerenciador = CriaGerenciador();

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("\t(1) Cadastrar um novo pacote\n");
        printf("\t(2) Imprimir um pacote específico\n");
        printf("\t(3) Imprimir todos os pacotes e sair\n");

        scanf("%d\n", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: ");
                scanf("%d %d\n", &tipoElementos, &numeroElementos);
                if (tipoElementos == 0) {
                    pacote = CriaPacote(CHAR, numeroElementos);
                }else {
                    if (tipoElementos == 1) {
                        pacote = CriaPacote(INT, numeroElementos);
                    }else {
                        printf("\nDigite um tipo valido!");
                        break;
                    }   
                }
                LePacote(pacote);
                AdicionaPacoteNoGerenciador(gerenciador, pacote);
                break;
            case 2:
                scanf("%d\n", &indiceListaPacotes);
                ImprimirPacoteNoIndice(gerenciador, indiceListaPacotes);
                break;
            case 3:
                ImprimirTodosPacotes(gerenciador);
                programaEncerrado = true;
                break;
            default:
                printf("Escolha uma opcao valida para o menu!\n");
                break;
        }
        if (programaEncerrado == true) {
            break;
        }
    }

    DestroiGerenciador(gerenciador);

    return 0;
}