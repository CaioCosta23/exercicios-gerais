#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filme.h"

#define MAX_CARACTERES 20

struct Filme {
    char nome[MAX_CARACTERES];
    int codigo;
    int valor;
    int qtdEstoque;
    int qtdAlugada;
};

tFilme *CriarFilme() {
    tFilme *filme = (tFilme*)malloc(sizeof(tFilme));

    if (filme == NULL) {
        printf("Erro na alocacao do filme!\n");
        return filme;
    }

    strcpy(filme->nome, "");
    filme->codigo = -1;
    filme->valor = -1;
    filme->qtdEstoque = 0;
    filme->qtdAlugada = 0;

    return filme;
}

void LeFilme(tFilme *filme, int codigo) {
    scanf("%[^,],%d,%d\n", filme->nome, &filme->valor, &filme->qtdEstoque);
    filme->codigo = codigo;
}

int ObterCodigoFilme(tFilme *filme) {
    return (*filme).codigo;
}

int ObterValorFilme(tFilme *filme) {
    return (*filme).valor;
}

int ObterQtdEstoqueFilme(tFilme *filme) {
    return (*filme).qtdEstoque;
}

int ObterQtdAlugadaFilme(tFilme *filme) {
    return (*filme).qtdAlugada;
}

int EhMesmoCodigoFilme(tFilme *filme, int codigo) {
    return ((*filme).codigo == codigo);
}

void AlugarFilme(tFilme *filme) {
    filme->qtdAlugada += 1;
    filme->qtdEstoque -= 1;
}

void DevolverFilme(tFilme *filme) {
    filme->qtdAlugada -= 1;
    filme->qtdEstoque += 1;
}

int CompararNomesFilmes(tFilme *filme1, tFilme *filme2) {
    return strcmp((*filme1).nome, (*filme2).nome);
}

void ImprimirNomeFilme(tFilme *filme) {
    printf("%s", (*filme).nome);
}

void DestruirFilme(tFilme *filme) {
    if (filme != NULL) {
        free(filme);
        filme = NULL;
    }
}