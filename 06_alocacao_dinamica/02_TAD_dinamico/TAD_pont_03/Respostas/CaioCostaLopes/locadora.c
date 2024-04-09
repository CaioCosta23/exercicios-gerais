#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

#define MAX_FILMES 100

tLocadora *CriarLocadora() {
    tLocadora *locadora = (tLocadora *)malloc(sizeof(tLocadora));

    if (locadora == NULL) {
        printf("Erro na alocacao da locadora!\n");
        exit(1);
    }

    locadora->filme = (tFilme **)malloc(MAX_FILMES * sizeof(tFilme*));
    locadora->numFilmes = 0;
    locadora->lucro = 0;

    return locadora;
}

int VerificaFilmeCadastrado(tLocadora *locadora, int codigo) {
    int f;

    for (f = 0; f < (*locadora).numFilmes; f++) {
        if (ObterCodigoFilme((*locadora).filme[f]) == codigo) {
            return 1;
        }
    }
    return 0;
}

void CadastrarFilmeLocadora(tLocadora *locadora, tFilme *filme) {
    if (VerificaFilmeCadastrado(locadora, (*filme).codigo)) {
        printf("Filme ja cadastrado no estoque\n");
    }else {
        (*locadora).filme[(*locadora).numFilmes] = filme;
        (*locadora).numFilmes += 1;

        printf("Filme cadastrado %d - %s\n", (*filme).codigo, (*filme).nome);
    }
}

void LerCadastroLocadora(tLocadora *locadora) {
    int codigo;
    tFilme *filme;

    while (scanf("%d,", &codigo) == 1) {
        LeFilme(filme, codigo);

        CadastrarFilmeLocadora(locadora, filme);
    }
}

void AlugarFilmesLocadora(tLocadora *locadora, int codigos[], int quantidadeCodigos) {
    int c, f;
    int existeFilme;
    int contAlugados = 0, custo = 0;

    for (c = 0; c < quantidadeCodigos; c++) {
        existeFilme = 0;
        for (f = 0; f < (*locadora).numFilmes; f++) {
            if (EhMesmoCodigoFilme((*locadora).filme[f], codigos[c])) {
                existeFilme;

                if (ObterQtdEstoqueFilme((*locadora).filme[f]) > 0) {
                    AlugarFilme((*locadora).filme[c]);
                    custo += ObterValorFilme((*locadora).filme[f]);
                    contAlugados++;
                }else {
                    printf("Filme %d - ", ObterCodigoFilme((*locadora).filme[f]));
                    ImprimirNomeFilme((*locadora).filme[f]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                }
                break;
            }
        }
        if (!(existeFilme)) {
            printf("Filme %d nao cadastrado.\n", codigos[c]);
        }
    }
    if (contAlugados > 0) {
        printf("Total de filmes alugados: %d com custo de R$%d\n", contAlugados, custo);
    }
}

void LerAluguelLocadora(tLocadora *locadora) {
    int codigo;
    int qtdCodigos = 0;
    int codigosFilmes[MAX_FILMES];
    
    while(scanf("%d\n", &codigo) == 1) {
        codigosFilmes[qtdCodigos] = codigo;
        qtdCodigos++;
    }
    AlugarFilmesLocadora(locadora, codigosFilmes, qtdCodigos);
}

void DevolverFilmesLocadora(tLocadora *locadora, int codigos) {

}

void LerDevolucaoLocadora(tLocadora *locadora) {

}

void OrdenarFilmesLocadora(tLocadora *locadora) {
}

void ConsultarEstoqueLocadora(tLocadora *locadora) {
    int f;
    int cont = 1;

    printf("~ESTOQUE~\n");

    for (f = 0; f < (*locadora).numFilmes; f++) {
        printf("%d - ", ObterCodigoFilme((*locadora).filme[f]));
        ImprimirNomeFilme((*locadora).filme[f]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme((*locadora).filme[f]));

        cont++;
    }
}

void ConsultarLucroLocadora(tLocadora *locadora) {
    if ((*locadora).lucro > 0) {
        printf("\nLucro total R$%d\n", (*locadora).lucro);
    }
}

void DestruirLocadora(tLocadora *locadora) {
    int f;

    for (f = 0; f < (*locadora).numFilmes; f++) {
        DestruiFilme((*locadora).filme[f]);
    }
    free((*locadora).filme);
    free(locadora);
}