#include <stdio.h>
#include <stdlib.h>
#include "evento.h"

void imprimeMenu() {
    printf("\n====Menu====\n");
    printf("1 - Cadastrar evento\n");
    printf("2 - Exibir todos os eventos\n");
    printf("3 - Trocar data de um evento\n");
    printf("4 - Trocar posicao entre dois eventos\n");
    printf("5 - Sair\n");
}

int main() {
    Evento eventos[MAX_EVENTOS];
    int numEventos = 0;
    int opcao;

    imprimeMenu();

    while (opcao != 5) {
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarEvento(eventos, &numEventos);
                break;
            case 2:
                exibirEventos(eventos, &numEventos);
                break;
            case 3:
                trocarDataEvento(eventos, &numEventos);
                break;
            case 4:
                int indiceA, indiceB;

                scanf("%d %d", &indiceA, &indiceB);

                trocarIndicesEventos(eventos, &indiceA, &indiceB, &numEventos);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            defaut:
                printf("Opcao invalida!\n");
        }
    }
    return 0;
}