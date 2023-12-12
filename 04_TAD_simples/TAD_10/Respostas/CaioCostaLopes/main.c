#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "livro.h"

int main() {
    tBiblioteca biblioteca;
    int qtdOperacoes, opcao;
    char titulo[50];
    
    biblioteca = inicializarBiblioteca();

    scanf("%d", &qtdOperacoes);

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n\n");

    for (int r = 0; r < qtdOperacoes; r++) {
        
        scanf("%d", &opcao);

        if (opcao == 1) {
            biblioteca = adicionarLivroNaBiblioteca(biblioteca, lerLivro());
        }else {
            if (opcao == 2) {
                scanf("%s", titulo);
                biblioteca = removerLivroDaBiblioteca(biblioteca, titulo);
            }else {
                if (opcao == 3) {
                    listarLivrosDaBiblioteca(biblioteca);
                }else {
                    printf("Operacao invalida!\n");
                    exit(1);
                }
            }
        }
    }

    return 0;
}