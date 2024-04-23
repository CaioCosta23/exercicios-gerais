#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main() {
    tBiblioteca *biblioteca;
    int qtdOperacoes, opcao, r;
    char titulo[50];

    biblioteca = InicializarBiblioteca();

    scanf("%d", &qtdOperacoes);

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros\n");
    printf("3 - Listar todos os livros cadastrados\n\n");

    for (r = 0; r < qtdOperacoes; r++) {
        scanf("%d", &opcao);

        if (opcao == 1) {
            AdicionarLivroNaBiblioteca(biblioteca);
        }else {
            if (opcao == 2) {
                scanf("%s", titulo);
                RemoverLivroDaBiblioteca(biblioteca, titulo);
            }else {
                if (opcao == 3) {
                    ListarLivrosDaBiblioteca(biblioteca);
                }else {
                    printf("Operacao invalida!\n");
                    exit(1);
                }
            }
        }
    }

    return 0;
}