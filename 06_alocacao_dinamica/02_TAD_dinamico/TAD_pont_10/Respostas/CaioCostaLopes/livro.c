#include <stdio.h>
#include <string.h>
#include "livro.h"

#define MAX_CARACTERES_STRINGS 50

tLivros *CriaLivro() {
    tLivros *livro = (tLivros*)malloc(sizeof(tLivros));

    if (livro == NULL) {
        printf("Erro na alocacao do livro!\n");
        return livro;
    }
    
    livro->titulo = NULL;
    livro->autor = NULL;
    livro->anoPublicacao = -1;

    return livro;
}

void LeLivro(tLivros *livro) {
    char titulo[MAX_CARACTERES_STRINGS];
    char autor[MAX_CARACTERES_STRINGS];

    scanf("%s %s %d", titulo, autor, &livro->anoPublicacao);

    livro->titulo = (char*)malloc(strlen(titulo) * sizeof(char));
    if ((*livro).titulo != NULL) {
        livro->autor = (char*)malloc(strlen(autor) * sizeof(char));
        if ((*livro).autor != NULL) {
            strcpy(livro->autor, autor);
        }else {
            printf("Erro na alocacao do nome do autor do livro!\n");
            ApagaLivro(livro);
        }
        strcpy(livro->titulo, titulo);
    }else {
        printf("Erro na alocacao do titulo do livro!\n");
        ApagaLivro(livro);
    }
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
    }
}