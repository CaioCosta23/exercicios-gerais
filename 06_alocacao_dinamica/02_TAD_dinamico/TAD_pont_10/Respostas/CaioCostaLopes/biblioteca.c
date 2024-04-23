#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

tBiblioteca *InicializarBiblioteca() {
    tBiblioteca *biblioteca = (tBiblioteca*)malloc(sizeof(tBiblioteca));

    if (biblioteca == NULL) {
        printf("Erro na alocacao da biblioteca!\n");
        exit(1);
    }

    biblioteca->tamanho = 0;

    return biblioteca;
}

void AdicionarLivroNaBiblioteca(tBiblioteca *biblioteca, tLivros *livro) {
    if ((*biblioteca).tamanho < MAX_LIVROS) {
        biblioteca->livros[(*biblioteca).tamanho] = livro;
        biblioteca->tamanho += 1;
        printf("Livro adicionado com sucesso!\n");
    }else {
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
    }
}

void RemoverLivroDaBiblioteca(tBiblioteca *biblioteca, char titulo[]) {
    int l, o, posicao;
    int achado = 0;
    tLivros *aux;

    if ((*biblioteca).tamanho > 0) {
        for (l = 0; l < (*biblioteca).tamanho; l++) {
            if (!(VerificaTituloDoLivroNaBiblioteca((*biblioteca).livros[l], titulo))) {
                achado = 1;
                posicao = l;
                break;
            }
        }
        if (achado) {
            for (o = posicao; o < (*biblioteca).tamanho; o++) {
                aux = (*biblioteca).livros[o + 1];
                biblioteca->livros[o + 1] = (*biblioteca).livros[o];
                biblioteca->livros[o] = aux; 
            }
            ApagaLivro((*biblioteca).livros[o]);
            biblioteca->tamanho -= 1;

            printf("Livro removido com sucesso\n!");
        }else {
            printf("Livro nao encontrado na biblioteca.\n");
        }
    }
}

int VerificaTituloDoLivroNaBiblioteca(tLivros *livro, char titulo[]) {
    return strcmp((*livro).titulo, titulo);
}

void ListarLivrosDaBiblioteca(tBiblioteca *biblioteca) {
    int l;

    if ((*biblioteca).tamanho > 0) {
        printf("\nLista de livros na biblioteca:\n");
        for (l = 0; l < (*biblioteca).tamanho; l++) {
            ImprimeLivro((*biblioteca).livros[l]);
        }
    }else {
        printf("A biblioteca esta vazia!\n");
    }
}

void ApagaBiblioteca(tBiblioteca *biblioteca) {
    int l;

    if (biblioteca != NULL) {
        for (l = 0; l < (*biblioteca).tamanho; l++) {
            if ((*biblioteca).livros[l] != NULL) {
                ApagaLivro((*biblioteca).livros[l]);
            }
        }
        free(biblioteca);
        biblioteca = NULL;
    }
}