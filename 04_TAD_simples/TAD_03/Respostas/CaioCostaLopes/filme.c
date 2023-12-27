#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filme.h"

tFilme criaFilme(char nome[], int codigo, int valor, int quantidade) {
    tFilme filme;

    strcpy(filme.nome, nome);
    filme.codigo = codigo;
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAluga = 0;

    return filme;
}

tFilme leFilme(int codigo) {
    char nome[MAX_CARACTERES];
    int valor, quantidade;
    tFilme filme;

    scanf(",%19[^,],%d,%d\n", nome, &valor, &quantidade);

    filme = criaFilme(nome, codigo, valor, quantidade);
}

int obterCodigoFilme(tFilme filme) {
    return filme.codigo;
}

void imprimeNomeFilme(tFilme filme) {
    printf("%s", filme.nome);
}

int obterValorFilme(tFilme filme) {
    return filme.valor;
}

int obterQtdEstoque(tFilme filme) {
    return filme.qtdEstoque;
}

int obterQuantidadeAlugadaFilme(tFilme filme) {
    return filme.qtdAluga;
}

int ehMesmoCodigoFilme(tFilme filme, int codigo) {
    return (filme.codigo == codigo);
}

tFilme alugarFilme(tFilme filme) {
    filme.qtdAluga += 1;
    filme.qtdEstoque -= 1;

    return filme;
}

tFilme devolverFilme(tFilme filme) {
    filme.qtdAluga -=1;
    filme.qtdEstoque += 1;

    return filme;
}

int comparaNomesFilme (tFilme filme1, tFilme filme2) {
    return (strcmp(filme1.nome, filme2.nome));
}