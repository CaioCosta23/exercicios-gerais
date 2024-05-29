#include <stdio.h>
#include <string.h>
#include "livro.h"

#define MAX_CARACTERES_STRING 50

struct Livros {
    char *titulo;
    char *autor;
    int anoPublicacao;
};

tLivros *CriaLivro() {
    tLivros *livro = (tLivros*)malloc(sizeof(tLivros));

    if(livro != NULL) {
        livro->titulo = (char*)malloc((MAX_CARACTERES_STRING * 2) * sizeof(char));
        if ((*livro).titulo == NULL) {
            printf("Erro na alocacao do titulo do livro!\n");
            ApagaLivro(livro);
        }else {
            livro->autor = (char*)malloc(MAX_CARACTERES_STRING * sizeof(char));
            if ((*livro).autor == NULL) {
                printf("Erro na alocacao do nome do autor do livro!\n");
                ApagaLivro(livro);
            }else {
                livro->anoPublicacao = -1;
            }
        }
    }else {
        printf("Erro na alocacao do livro!\n");
    }
    return livro;
}

void LerLivro(tLivros *livro) {
    scanf("%s %s %d", livro->titulo, livro->autor, &livro->anoPublicacao);
}

char *getTitulo(tLivros *livro) {
    return (*livro).titulo;
}

void ImprimeLivro(tLivros *livro) {
    printf("Titulo: %s\n", (*livro).titulo);
    printf("Autor: %s\n", (*livro).autor);
    printf("Ano de Publicacao: %d\n", (*livro).anoPublicacao);
}

void ApagaLivro(tLivros *livro) {
    if (livro != NULL) {
        if ((*livro).titulo != NULL) {
            if ((*livro).autor != NULL) {
                free((*livro).autor);
                livro->autor = NULL;
            }
            free((*livro).titulo);
            livro->titulo = NULL;
        }
        free(livro);
        livro = NULL;
    }
}