#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "livro.h"

int main() {
    tBiblioteca biblioteca;
    int opcao;
    char titulo[50];
    
    biblioteca = inicializarBiblioteca();
    
    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");
    
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            biblioteca = adicionarLivroNaBiblioteca(biblioteca, lerLivro());
            break;
        case 2:
            scanf("%s", titulo);
            biblioteca = removerLivroDaBiblioteca(biblioteca, titulo);
            break;
        case 3:
            imprimeBibioteca(biblioteca);
            break;
    }

    return 0;
}