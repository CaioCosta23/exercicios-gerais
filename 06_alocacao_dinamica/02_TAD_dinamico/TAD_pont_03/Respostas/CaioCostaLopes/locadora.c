#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

#define MAX_FILMES 100

tLocadora *CriarLocadora() {
    // Aloca dinâmicamente uma locadora;
    tLocadora *locadora = (tLocadora *)malloc(sizeof(tLocadora));

    // Caso a alocação dê errado, indica na tela e encerra o programa;
    if (locadora == NULL) {
        printf("Erro na alocacao da locadora!\n");
        exit(1);
    }

    // Aloca dinâmicamente um vetor de filmes da locadora;
    locadora->filme = (tFilme **)malloc(MAX_FILMES * sizeof(tFilme*));

    // Caso a alocação dê errado, indica na tela e encerra o programa;
    if ((*locadora).filme == NULL) {
        printf("Erro na alocacao do vetor de filmes!");
    }
    // Inicializa os atributos numéricos da locadora;   
    locadora->numFilmes = 0;
    locadora->lucro = 0;

    return locadora;
}

int VerificarFilmeCadastrado(tLocadora *locadora, int codigo) {
    int f;

    // Verifica se o código passado já pertence a algum filme já cadastrado;
    for (f = 0; f < (*locadora).numFilmes; f++) {
        if (ObterCodigoFilme((*locadora).filme[f]) == codigo) {
            return 1;
        }
    }
    return 0;
}

void CadastrarFilmeLocadora(tLocadora *locadora, tFilme *filme) {
    // Verifica se o filme já está cadastrado e informa ao usuário;
    if (VerificarFilmeCadastrado(locadora, (*filme).codigo)) {
        printf("Filme ja cadastrado no estoque\n");
        
        /* Caso o filme já esteja cadastrado, isso siginifica que ele não será adicionando a lista (vetor) de filmes da locadora
        * fazendo com que fique a cargo dessa mesma função liberar a memória do filme que foi criado (alocado), lido, mas não será 
        * utlizado (já que a função de destruir tanto o filme como a locadora não se englobam aqui);
        */
        free(filme);
    }else {
        // Realoca o vetor de filmes para a quantidade atual de filmes registrados;
        locadora->filme = (tFilme **)realloc((*locadora).filme, ((*locadora).numFilmes + 1) * sizeof(tFilme*));
        // Caso a realocação não funcione, desaloca tudo e encerra o programa;
        if ((*locadora).filme == NULL) {
            printf("Erro na realocacao do vetor de filmes!\n");
            DestruirLocadora(locadora);
            exit(1);
        }
        // Adiciona o filme ao vetor de filmes e contabiliza na locadora;
        locadora->filme[(*locadora).numFilmes] = filme;
        locadora->numFilmes += 1;

        printf("Filme cadastrado %d - %s\n", (*filme).codigo, (*filme).nome);
    }
}

void LerCadastroLocadora(tLocadora *locadora) {
    int codigo;
    tFilme *filme = NULL;
    
    // Enquanto um código numérico for repassado, cria, lê e cadastra um filme;
    while (scanf("%d,", &codigo) == 1) {
        filme = CriarFilme();
        LeFilme(filme, codigo);

        CadastrarFilmeLocadora(locadora, filme);
    }
}

void AlugarFilmesLocadora(tLocadora *locadora, int codigos[], int quantidadeCodigos) {
    int c, f;
    int existeFilme;
    int contAlugados = 0, custo = 0;

    // Verifica se os filmes existem no vetor de filmes da locadora;
    for (c = 0; c < quantidadeCodigos; c++) {
        existeFilme = 0;
        for (f = 0; f < (*locadora).numFilmes; f++) {
            if (EhMesmoCodigoFilme((*locadora).filme[f], codigos[c])) {
                existeFilme = 1;

                // Caso o filme esteja registrado, verifica sua quantidade em estoque;
                if (ObterQtdEstoqueFilme((*locadora).filme[f]) > 0) {
                    // Caso ainda haja o filme em estoque (1 unidade ou mais), aluga o filme e contabiliza o valor do aluguel;
                    AlugarFilme((*locadora).filme[f]);
                    custo += ObterValorFilme((*locadora).filme[f]);
                    contAlugados++;
                }else {
                    // Caso não haja o filme em estoque, informa ao usuário;
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
    // Informa quantos filmes foram alugados e qual o custo total;
    if (contAlugados > 0) {
        printf("Total de filmes alugados: %d com custo de R$%d\n", contAlugados, custo);
    }
}

void LerAluguelLocadora(tLocadora *locadora) {
    int codigo;
    int qtdCodigos = 0;
    int codigosFilmes[MAX_FILMES];
    
    // Lê os códigos de todos os filmes a serem alugados e os armazena em um vetor;
    while(scanf("%d\n", &codigo) == 1) {
        codigosFilmes[qtdCodigos] = codigo;
        qtdCodigos++;
    }
    AlugarFilmesLocadora(locadora, codigosFilmes, qtdCodigos);
}

void DevolverFilmesLocadora(tLocadora *locadora, int codigos[], int quantidadeCodigos) {
    int c, f;
    int existeFilme;

    // Verifica se os filmes existem no vetor de filmes da locadora;
    for (c = 0; c < quantidadeCodigos; c++) {
        existeFilme = 0;
        for (f = 0; f < (*locadora).numFilmes; f++) {
            if (EhMesmoCodigoFilme((*locadora).filme[f], codigos[c])) {
                existeFilme = 1;
                // Caso o filme esteja registrado, verifica sua quantidade alugada;
                if (ObterQtdAlugadaFilme((*locadora).filme[f]) > 0) {
                    // Caso ainda haja o filme alugado (1 unidade ou mais), devolve o filme e contabiliza o valor do aluguel;
                    DevolverFilme((*locadora).filme[f]);
                    locadora->lucro += ObterValorFilme((*locadora).filme[f]);

                    printf("Filme %d - ", codigos[c]);

                    ImprimirNomeFilme((*locadora).filme[f]);
                    printf(" Devolvido!\n");
                }else {
                    // Caso não haja o filme em alugado, informa ao usuário;
                    printf("Nao e possivel devolver o filme %d - ", ObterCodigoFilme((*locadora).filme[f]));
                    ImprimirNomeFilme((*locadora).filme[f]);
                    printf(".\n");
                }
                break;
            }
        }
        if ((!(existeFilme))) {
            printf("Filme %d nao cadastrado.\n", codigos[c]);
        }
    }
}

void LerDevolucaoLocadora(tLocadora *locadora) {
    int codigo;
    int qtdCodigos = 0;
    int codigosFilmes[MAX_FILMES];

    // Lê os códigos de todos os filmes a serem devolvidos e os armazena em um vetor;
    while(scanf("%d\n", &codigo) == 1) {
        codigosFilmes[qtdCodigos] = codigo;
        qtdCodigos++;
    }
    DevolverFilmesLocadora(locadora, codigosFilmes, qtdCodigos);
}

void OrdenarFilmesLocadora(tLocadora *locadora) {
    int f, o;
    tFilme *filmeAuxiliar;
    // Ordena os filmes da locadora em ordem alfabética;
    for (f = 0; f < ((*locadora).numFilmes - 1); f++) {
        for (o = f + 1; o < (*locadora).numFilmes; o++) {
            // Compara os nomes dos filmes para ver se precisa ordenar ou não;
            if (CompararNomesFilmes((*locadora).filme[f], (*locadora).filme[o]) > 0) {
                filmeAuxiliar = (*locadora).filme[f];
                locadora->filme[f] = (*locadora).filme[o];
                locadora->filme[o] = filmeAuxiliar;
            }
        }
    }
}

void ConsultarEstoqueLocadora(tLocadora *locadora) {
    int f;
    int cont = 1;

    printf("~ESTOQUE~\n");

    // Imprime o estoque de filmes da locadora;
    for (f = 0; f < (*locadora).numFilmes; f++) {
        printf("%d - ", ObterCodigoFilme((*locadora).filme[f]));
        ImprimirNomeFilme((*locadora).filme[f]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme((*locadora).filme[f]));

        cont++;
    }
}

void ConsultarLucroLocadora(tLocadora *locadora) {
    // Verifica se a locadora possui algum lucro, e caso tenha, imprime na saída padrão;
    if ((*locadora).lucro > 0) {
        printf("\nLucro total R$%d\n", (*locadora).lucro);
    }
}

void DestruirLocadora(tLocadora *locadora) {
    int f;

    // Destroi (desaloca) cada filme da locadora;
    for (f = 0; f < (*locadora).numFilmes; f++) {
        DestruirFilme((*locadora).filme[f]);
    }
    // Desaloca o vetor utilizado para armazenar cada filme da locadora;
    free((*locadora).filme);
    // Desaloca a locadora;
    free(locadora);
}