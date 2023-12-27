#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filme.h"

tFilme criarFilme(char nome[], int codigo, int valor, int quantidade) {
    tFilme filme;

    strcpy(filme.nome, nome);
    filme.codigo = codigo;
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAlugada = 0;

    return filme;
}

tFilme leFilme(int codigo) {
    char nome[MAX_CARACTERES];
    int valor, quantidade;
    tFilme filme;

    scanf(",%19[^,],%d,%d\n", nome, &valor, &quantidade);

    filme = criarFilme(nome, codigo, valor, quantidade);

    return filme;
}

int obterCodigoFilme(tFilme filme) {
    return filme.codigo;
}

void imprimirNomeFilme(tFilme filme) {
    printf("%s", filme.nome);
}

int obterValorFilme(tFilme filme) {
    return filme.valor;
}

int obterQtdEstoque(tFilme filme) {
    return filme.qtdEstoque;
}

int obterQuantidadeAlugadaFilme(tFilme filme) {
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme(tFilme filme, int codigo) {
    return (filme.codigo == codigo);
}

tFilme alugarFilme(tFilme filme) {
    filme.qtdAlugada += 1;
    filme.qtdEstoque -= 1;

    return filme;
}

tFilme devolverFilme(tFilme filme) {
    filme.qtdAlugada -=1;
    filme.qtdEstoque += 1;

    return filme;
}

int comparaNomesFilmes(tFilme filme1, tFilme filme2) {
    return (strcmp(filme1.nome, filme2.nome));
}