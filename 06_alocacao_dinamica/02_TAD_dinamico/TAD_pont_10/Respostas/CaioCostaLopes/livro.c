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

void LerLivro(tLivros *livro) {
    //char titulo[MAX_CARACTERES_STRINGS * 2];
    char autor[MAX_CARACTERES_STRINGS];

    livro->titulo = (char*)malloc((MAX_CARACTERES_STRINGS * 2) * sizeof(char));
    if ((*livro).titulo == NULL) {
        printf("Erro na alocacao do titulo do livro!\n");
        ApagaLivro(livro);
    }
    livro->autor = (char*)malloc(MAX_CARACTERES_STRINGS * sizeof(char));
    if ((*livro).autor == NULL) {
        printf("Erro na alocacao do nome do autor do livro!\n");
        ApagaLivro(livro);
    }
    
    scanf("%s %s %d", livro->titulo, livro->autor, &livro->anoPublicacao);
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