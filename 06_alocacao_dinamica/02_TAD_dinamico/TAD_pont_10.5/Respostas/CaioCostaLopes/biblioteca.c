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
    biblioteca->tam_max_atual = NUM_INICIAL_LIVROS;

    biblioteca->livros = (tLivros**)malloc((*biblioteca).tam_max_atual * sizeof(tLivros*));
    if ((*biblioteca).livros == NULL) {
        printf("Erro na alocacao do vetor de livros da biblioteca!\n");
        ApagaBiblioteca(biblioteca);
        exit(1);
    }

    return biblioteca;
}

void AdicionarLivroNaBiblioteca(tBiblioteca *biblioteca, tLivros *livro) {
    if ((*biblioteca).tamanho == (*biblioteca).tam_max_atual) {
        biblioteca->tam_max_atual += 1;
        biblioteca->livros = (tLivros**)realloc(biblioteca->livros, (*biblioteca).tam_max_atual * sizeof(tLivros*));
        
        if ((*biblioteca).livros == NULL) {
            printf("Erro na realocacao do vetor de livros (na adição) da biblioteca!\n");
            ApagaBiblioteca(biblioteca);
            exit(1);
        }
    }
    biblioteca->livros[(*biblioteca).tamanho] = livro;
    biblioteca->tamanho += 1;
    printf("Livro adicionado com sucesso!\n");
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
            biblioteca->tam_max_atual -= 1;

            biblioteca->livros = (tLivros**)realloc(biblioteca->livros, (*biblioteca).tam_max_atual * sizeof(tLivros*));
        
            if ((*biblioteca).livros == NULL) {
                printf("Erro na realocacao do vetor de livros (na remocao) da biblioteca!\n");
                ApagaBiblioteca(biblioteca);
                exit(1);
            }

            printf("Livro removido com sucesso!\n");
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
        printf("\nLista de Livros na Biblioteca:\n");
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
        if ((*biblioteca).livros != NULL) {
            for (l = 0; l < (*biblioteca).tamanho; l++) {
                if ((*biblioteca).livros[l] != NULL) {
                    ApagaLivro((*biblioteca).livros[l]);
                }
            }
            free((*biblioteca).livros);
        }
        free(biblioteca);
        biblioteca = NULL;
    }
}