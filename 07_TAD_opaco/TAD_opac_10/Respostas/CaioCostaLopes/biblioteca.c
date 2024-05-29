#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

struct Biblioteca {
    tLivros **livros; // Vetor de livros; 
    int qtdLivros; // Quantidade de livros na biblioteca (atualmente);
    int qtdMaximo; // Quantidade máxima de livros que a biblioteca comporta (atualmente);
};

tBiblioteca *InicializarBiblioteca() {
    tBiblioteca *biblioteca = (tBiblioteca*)malloc(sizeof(tBiblioteca));

    if (biblioteca == NULL) {
        printf("Errro na alocacao de memoria da biblioteca!\n");
        exit(1);
    }

    biblioteca->qtdLivros = 0;
    biblioteca->qtdMaximo = NUM_INICIAL_LIVROS;

    biblioteca->livros = (tLivros**)malloc((*biblioteca).qtdMaximo * sizeof(tBiblioteca*));
    if ((*biblioteca).livros == NULL) {
        printf("Erro na alocacao do vetor de livros da biblioteca!\n");
        ApagaBiblioteca(biblioteca);
        exit(1);
    }

    return biblioteca;
}

void AdicionarLivroNaBiblioteca(tBiblioteca *biblioteca, tLivros *livro) {
    if ((*biblioteca).qtdLivros == (*biblioteca).qtdMaximo) {
        biblioteca->qtdMaximo += NUM_INICIAL_LIVROS;
        
        biblioteca->livros = (tLivros**)realloc((*biblioteca).livros, (*biblioteca).qtdMaximo *sizeof(tLivros*));
        if ((*biblioteca).livros == NULL) {
            printf("Erro na realocacao de memoria do vetor (na adicao) de livros");
            ApagaBiblioteca(biblioteca);
            exit(1);
        }
    }
    biblioteca->livros[(*biblioteca).qtdLivros] = livro;
    biblioteca->qtdLivros += 1;

    printf("Livro adicionado com sucesso!\n");
}

void RemoverLivroDaBiblioteca(tBiblioteca *biblioteca, char titulo[]) {
    int l, o, posicao;
    int achado = 0;
    tLivros *livroAuxiliar;

    if ((*biblioteca).qtdLivros > 0) {
        for (l = 0; l < (*biblioteca).qtdLivros; l++) {
            if (!(VerificaTituloDoLivroNaBiblioteca((*biblioteca).livros[l], titulo))) {
                achado = 1;
                posicao = l;
                break;
            }
        }
        if (achado) {
            for (o = posicao; o < (*biblioteca).qtdLivros; o++) {
                livroAuxiliar = (*biblioteca).livros[o + 1];
                biblioteca->livros[o + 1] = (*biblioteca).livros[o];
                biblioteca->livros[o] = livroAuxiliar;
            }
            ApagaLivro((*biblioteca).livros[o]);
            biblioteca->qtdLivros -= 1;

            printf("Livro removido com sucesso!\n");
        }else {
            printf("Livro nao encontrado na biblioteca!\n");
        }
    }
}

int VerificaTituloDoLivroNaBiblioteca(tLivros *livro, char titulo[]) {
    return strcmp(getTitulo(livro), titulo);
}

void ListarLivrosDaBiblioteca(tBiblioteca *biblioteca) {
    int l;

    if ((*biblioteca).qtdLivros > 0) {
        printf("\nLista de Livros da Biblioteca:\n");
        for (l = 0; l < (*biblioteca).qtdLivros; l++) {
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
            for (l = 0; l < (*biblioteca).qtdLivros; l++) {
                ApagaLivro((*biblioteca).livros[l]);
            }
            free((*biblioteca).livros);
            biblioteca->livros = NULL;
        }
        free(biblioteca);
        biblioteca = NULL;
    }
}