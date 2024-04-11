#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filme.h"

tFilme *CriarFilme() {
    // Aloca dinamicamente um filme;
    tFilme *filme = (tFilme *)malloc(sizeof(tFilme));

    // Verifica se a alocação foi bem sucedida e, caso não seja, informa ao usuário e encerra o programa;
    if (filme == NULL) {
        printf("Erro na alocacao do filme!\n");
        exit(1);
    }

    // Inicializa os atributos do filme;
    strcpy(filme->nome, "");
    filme->codigo = - 1;
    filme->valor = - 1;
    filme->qtdEstoque = 0;
    filme->qtdAlugada = 0;

    return filme;
}

void LeFilme(tFilme *filme, int codigo) {
    // Lê as informações do filme e os atribui ao filme;;
    scanf("%[^,],%d,%d\n", (*filme).nome, &(*filme).valor, &(*filme).qtdEstoque);
    filme->codigo = codigo;
}

int ObterCodigoFilme(tFilme *filme) {
    return (*filme).codigo;
}

void ImprimirNomeFilme(tFilme *filme) {
    printf("%s", (*filme).nome);
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

void DestruirFilme(tFilme *filme) {
    // Destroi (desaloca o filme);
    free(filme);
}