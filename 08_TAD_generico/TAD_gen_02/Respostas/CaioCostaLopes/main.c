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
        printf("(1) Cadastrar um novo pacote\n");
        printf("(2) Imprimir um pacote específico\n");
        printf("(3) Imprimir todos os pacotes e sair\n");

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
                    }   
                }
                LePacote(pacote);
                AdicionaPacoteNoGerenciador(gerenciador, pacote);
                //programaEncerrado = true;
                break;
            case 2:
                scanf("%d\n", &indiceListaPacotes);
                ImprimirPacoteNoIndice(gerenciador, indiceListaPacotes);
                //programaEncerrado = true;
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