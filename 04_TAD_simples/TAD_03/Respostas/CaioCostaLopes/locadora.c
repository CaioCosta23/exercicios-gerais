#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

tLocadora criaLocadora() {
    tLocadora locadora;

    locadora.numFilmes = 0;
    locadora.lucro = 0;

    return locadora;
}

int verificaFilmeCadastrado(tLocadora locadora, int codigo) {
    int f;

    for (f = 0; f < locadora.numFilmes; f++) {
        if (obterCodigoFilme(locadora.filme[f]) == codigo) {
            return 1;
        }
    }
    return 0;
}

tLocadora cadastrarFilmeLocadora(tLocadora locadora, tFilme filme) {
    if (verificaFilmeCadastrado(locadora, filme.codigo)) {
        printf("Filme ja cadastrado no estoque\n");
    }else {
        locadora.filme[locadora.numFilmes] = filme;
        locadora.numFilmes += 1;

        printf("Filme cadastrado %d - %s\n", filme.codigo, filme.nome);
    }
    return locadora;
}

tLocadora lerCadastroLocadora(tLocadora locadora) {
    char codigo;
    tFilme filme;

    scanf("%c", &codigo);

    while(1) {
        codigo = codigo - '0';

        filme = leFilme((int)codigo);

        locadora = cadastrarFilmeLocadora(locadora, filme);
    }
    printf("\n");

    return locadora;
}

tLocadora alugarFilmesLocadora(tLocadora locadora, int codigos[], int quantidadeCodigos) {
    int c, f;
    int existeFilme;

    for (c = 0; c < quantidadeCodigos; c++) {
        existeFilme = 0;
        for (f = 0; f < locadora.numFilmes; f++) {
            if (ehMesmoCodigoFilme(locadora.filme[f], codigos[c])) {
                existeFilme = 1;
                break;
            }
            if (existeFilme) {
                if (obterQtdEstoqueFilme(locadora.filme[f]) > 0) {
                    locadora.filme[f] = alugarFilme(locadora.filme[f]);
                    printf("Total de filmes alugados: 1 com custo de R$%d\n", obterValorFilme(locadora.filme[f]));
                }else {
                    printf("Filme %d - ", obterCodigoFilme(locadora.filme[f]));
                    imprimeNomeFilme(locadora.filme[f]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                }
            }else {
                printf("Filme %d nao cadastrado.\n", codigos[c]);
            }
        }
    }
    printf("\n");

    return locadora;    
}

tLocadora lerLocadoraAluguelLocadora(tLocadora locadora) {
    char codigo;
    int qtdCodigos = 0;
    int codigosFilmes[MAX_FILMES];

    while(1) {
        scanf("%c\n", &codigo);
        
        if (codigo == '#') {
            break;
        }

        codigosFilmes[qtdCodigos] = (int)codigo - (int)'0';
        qtdCodigos++;
    }
    locadora = alugarFilmesLocadora(locadora, codigosFilmes, qtdCodigos);

    return locadora;
}

tLocadora devolverFilmesLocadora(tLocadora locadora, int codigos[], int quantidadeCodigos) {
    int c, f;
    int existeFilme;

    for (c = 0; c < quantidadeCodigos; c++) {
        existeFilme = 0;
        for (f = 0; f < locadora.numFilmes; f++) {
            if (ehMesmoCodigoFilme(locadora.filme[f], codigos[c])) {
                existeFilme = 1;
                break;
            }
            if (existeFilme) {
                if (obterQuantidadeAlugada(locadora.filme[f]) > 0) {
                    locadora.filme[f] = devolveFilme(locadora.filme[f]);
                    locadora.lucro += obterValorFilme(locadora.filme[f]);
                    printf("Filme %d - ");
                    imprimeNomeFilme(locadora.filme[f]);
                    printf(" Devolvido!\n");
                }else {
                    printf("Nao eh possivel devolver o filme %d - ", obterCodigoFilme(locadora.filme[f]));
                    imprimeNomeFilme(locadora.filme[f]);
                    printf("\n");
                }
            }else {
                printf("Filme %d nao cadastrado.\n", codigos[c]);
            }
        }
    }
    printf("\n");

    return locadora;
}

tLocadora lerDevolucaoLocadora(tLocadora locadora) {
    char codigo;
    int qtdCodigos = 0;
    int codigosFilmes[MAX_FILMES];

    while(1) {
        scanf("%c\n", &codigo);
        
        if (codigo == '#') {
            break;
        }

        codigosFilmes[qtdCodigos] = (int)codigo - (int)'0';
        qtdCodigos++;
    }
    locadora = devolverFilmesLocadora(locadora, codigosFilmes, qtdCodigos);

    return locadora;
}

tLocadora ordenaFilmesLocadora(tLocadora locadora) {
    int f, o;
    tFilme aux;

    for (f = 0; f < (locadora.numFilmes - 1); f++) {
        for(o = f + 1; o < locadora.numFilmes; o++) {
            if (comparaNomesFilme(locadora.filme[f], locadora.filme[o]) > 0) {
                aux = locadora.filme[f];
                locadora.filme[f] = locadora.filme[o];
                locadora.filme[o] = aux;
            }
        }
    }
    return locadora;
}

void consultarEstoqueLocadora(tLocadora locadora) {
    int f, cont = 1;

    printf("~ESTOQUE~\n");

    for (f = 0; f < locadora.numFilmes; f++) {
        printf("%d - ");
        imprimeNomeFilme(locadora.filme[f]);
        printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[f]));

        cont++;
    }
    printf("\n");
}

void consultarLucroLocadora(tLocadora locadora) {
    printf("Lucro total R$%d\n", locadora.lucro);
}