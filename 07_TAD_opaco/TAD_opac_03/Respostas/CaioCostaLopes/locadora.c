#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

#define MAX_FILMES 100

struct Locadora {
    tFilme **filme;
    int numFilmes;
    int lucro;
};

tLocadora *CriarLocadora() {
    tLocadora *locadora = (tLocadora*)malloc(sizeof(tLocadora));

    if (locadora == NULL) {
        printf("Erro na alocacao da locadora!\n");
        exit(1);
    }

    locadora->filme = (tFilme **)malloc(MAX_FILMES * sizeof(tFilme*));
    if ((*locadora).filme == NULL) {
        printf("Erro na alocacao do vetor de filmes!\n");
        DestruirLocadora(locadora);
        exit(1);
    }

    locadora->numFilmes = 0;
    locadora->lucro = 0;

    return locadora;
}

int VerificarFilmeCadastrado(tLocadora *locadora, int codigo) {
    int f;

    for (f = 0; f < (*locadora).numFilmes; f++) {
        if (ObterCodigoFilme((*locadora).filme[f]) == codigo) {
            return 1;
        }
    }
    return 0;
}

void CadastrarFilmeLocadora(tLocadora *locadora, tFilme *filme) {
    if (VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme))) {
        printf("Filme ja cadastrado no estoque\n");
        DestruirFilme(filme);
    }else {
        locadora->filme = (tFilme**)realloc((*locadora).filme, ((*locadora).numFilmes + 1) * sizeof(tFilme*));
        if ((*locadora).filme == NULL) {
            printf("Erro na realocacao do vetor de filmes!\n");
            DestruirLocadora(locadora);
            exit(1);
        }
        locadora->filme[(*locadora).numFilmes] = filme;
        locadora->numFilmes += 1;

        printf("Filme cadastrado %d - ", ObterCodigoFilme(filme));
        ImprimirNomeFilme(filme);
        printf("\n");
    }
}

void LerCadastroLocadora(tLocadora *locadora) {
    int codigo;
    tFilme *filme = NULL;

    while(scanf("%d,", &codigo) == 1) {
        filme = CriarFilme();
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
                existeFilme = 1;

                if (ObterQtdEstoqueFilme((*locadora).filme[f]) > 0) {
                    AlugarFilme((*locadora).filme[f]);
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

void DevolverFilmesLocadora(tLocadora *locadora, int codigos[], int quantidadeCodigos) {
    int c, f;
    int existeFilme;

    for (c = 0; c < quantidadeCodigos; c++) {
        existeFilme = 0;
        for (f = 0; f < (*locadora).numFilmes; f++) {
            if (EhMesmoCodigoFilme((*locadora).filme[f], codigos[c])) {
                existeFilme = 1;

                if (ObterQtdAlugadaFilme((*locadora).filme[f]) > 0) {
                    DevolverFilme((*locadora).filme[f]);
                    locadora->lucro += ObterValorFilme((*locadora).filme[f]);

                    printf("Filme %d - ", codigos[c]);
                    ImprimirNomeFilme((*locadora).filme[f]);
                    printf(" Devolvido!\n");
                }else {
                    printf("Nao e possivel devolver o filme %d - ", ObterCodigoFilme((*locadora).filme[f]));
                    ImprimirNomeFilme((*locadora).filme[f]);
                    printf(".\n");
                }
                break;
            }
        }
        if (!(existeFilme)) {
            printf("Filme %d nao cadastrado.\n", codigos[c]);
        }
    }
}

void LerDevolucaoLocadora(tLocadora *locadora) {
    int codigo;
    int qtdCodigos = 0;
    int codigosFilmes[MAX_FILMES];

    while(scanf("%d\n", &codigo) == 1) {
        codigosFilmes[qtdCodigos] = codigo;
        qtdCodigos++;
    }
    DevolverFilmesLocadora(locadora, codigosFilmes, qtdCodigos);
}

void OrdenarFilmesLocadora(tLocadora *locadora) {
    int f, o;
    tFilme *filmeAuxiliar;

    for (f = 0; f < ((*locadora).numFilmes - 1); f++) {
        for (o = f + 1; o < (*locadora).numFilmes; o++) {
            if (CompararNomesFilmes((*locadora).filme[f], (*locadora).filme[o]) > 0) {
                filmeAuxiliar = (*locadora).filme[f];
                locadora->filme[f] = (*locadora).filme[f];
                locadora->filme[o] = filmeAuxiliar;
            }
        }
    }
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

    if (locadora != NULL) {
        if ((*locadora).filme != NULL) {
            for (f = 0; f< (*locadora).numFilmes; f++) {
                DestruirFilme((*locadora).filme[f]);
            }
            free((*locadora).filme);
            locadora->filme = NULL;
        }
        free(locadora);
        locadora = NULL;
    }
}