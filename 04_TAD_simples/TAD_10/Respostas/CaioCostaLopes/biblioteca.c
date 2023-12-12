#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "livro.h"

tBiblioteca inicializarBiblioteca() {
    tBiblioteca biblioteca;

    biblioteca.tamanho = 0;

    return biblioteca;
}

tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro) {
    
    if (biblioteca.tamanho < MAX_LIVROS) {
        biblioteca.livros[biblioteca.tamanho] = livro;
        biblioteca.tamanho += 1;
        printf("Livro adicionado com sucesso!\n");
    }else {
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
    }
    return biblioteca;
}

tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char titulo[]) {
    int l, o, posicao;
    int achado = 0;
    tLivros aux; 
    tLivros livroVazio = {"\0", "\0", 0};;

    if (biblioteca.tamanho > 0) {
        for (l = 0; l < biblioteca.tamanho; l++) {
            if (!(verificaTituloDoLivroNaBiblioteca(biblioteca.livros[l], titulo))) {
                achado = 1;
                posicao = l;
                break;
            }
        }

        if (achado) {
            for (o = posicao; o < biblioteca.tamanho - 1; o++) {
                aux = biblioteca.livros[o + 1];
                biblioteca.livros[o + 1] = biblioteca.livros[o];
                biblioteca.livros[o] = aux;
            }
            biblioteca.livros[o] = livroVazio;
            biblioteca.tamanho -= 1;
            printf("Livro removido com sucesso!\n");
        }else {
            printf("Livro nao encontrado na biblioteca.\n");
        }
    }
    return biblioteca;
}

int verificaTituloDoLivroNaBiblioteca(tLivros livro, char titulo[]) {
    return strcmp(livro.titulo, titulo);
}

void listarLivrosDaBiblioteca(tBiblioteca biblioteca) {
    int l;

    if (biblioteca.tamanho > 0) {
        printf("\nLista de Livros na Biblioteca:\n");
        for (l = 0; l < biblioteca.tamanho; l++) {
            imprimeLivro(biblioteca.livros[l]);
        }
    }else {
        printf("A biblioteca esta vazia!\n");
    }
}