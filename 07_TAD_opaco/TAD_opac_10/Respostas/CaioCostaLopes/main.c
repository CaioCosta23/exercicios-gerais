#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

void VerificaSituacaoLivroNoPrograma(tBiblioteca *biblioteca, tLivros *livro) {
    if (livro == NULL) {
        ApagaBiblioteca(biblioteca);
        exit(1);
    }
}

int main() {
    tBiblioteca *biblioteca;
    tLivros *livro;
    int qtdOperacoes, opcao, r;
    char titulo[50];

    biblioteca = InicializarBiblioteca();

    scanf("%d", &qtdOperacoes);

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n\n");

    for (r = 0; r < qtdOperacoes; r++) {
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                livro = CriaLivro();
                VerificaSituacaoLivroNoPrograma(biblioteca, livro);
                LerLivro(livro);
                VerificaSituacaoLivroNoPrograma(biblioteca, livro);
                AdicionarLivroNaBiblioteca(biblioteca, livro);
                break;
            case 2:
                scanf("%s", titulo);
                RemoverLivroDaBiblioteca(biblioteca, titulo);
                break;
            case 3:
                ListarLivrosDaBiblioteca(biblioteca);
                break;
            default:
                printf("Operacao invalida!\n");
                ApagaBiblioteca(biblioteca);
                exit(1);
        }
    }
    ApagaBiblioteca(biblioteca);

    return 0;
}