#ifndef _FLIME_H
#define _FILME_H

#define MAX_CARACTERES 20

typedef struct Filme {
    int codigo;
    char nome[MAX_CARACTERES];
    int valor;
    int qtdEstoque;
    int qtdAlugada;
}tFilme;

/**
 * @brief Cria um novo filme e define a quantidade alugada como 0;
 * 
 * @return tFilme* Ponteiro para o filme criado ou encerra caso não seja possível alocar a memória;
 */
tFilme *CriarFilme();

/**
 * @brief Lê um filme do arquivo de entrada e define o código do filme;
 * 
 * @param filme Ponteiro para o filme a ser lido;
 * @param codigo Código do filme a ser lido;
 */
void LeFilme(tFilme *filme, int codigo);

/**
 * @brief Obtem o código do filme;
 * 
 * @param filme Ponteiro para o filme;
 * @return int Código do filme;
 */
int ObterCodigoFilme(tFilme *filme);

/**
 * @brief Imprime o nome do filme;
 * 
 * @param filme Ponteiro para o filme;
 */
void ImprimirNomeFilme(tFilme *filme);

/**
 * @brief Obtém o valor do filme;
 * 
 * @param filme Ponteiro para o filme;
 * @return int valor do filme;
 */
int ObterValorFilme(tFilme *filme);

/**
 * @brief Obtém a quantidade em estoque do filme;
 * 
 * @param filme Ponteiro para o filme;
 * @return int Quantidade alugada do filme;
 */
int ObterQtdEstoqueFilme(tFilme *filme);

/**
 * @brief Obtem a quantidade alugada do filme;
 * 
 * @param filme Ponteiro  para o filme;
 * @return int Quantidade alugada do filme;
 */
int ObterQtdAlugadaFilme(tFilme *filme);

/**
 * @brief Verifica se o filme posuui o código passado como parâmetro;
 * 
 * @param filme Ponteiro para o filme;
 * @param codigo Código a ser comparado;
 * @return int 1 se o filme possui o mesmo código passado como parâmetro, 0 caso contrário;
 */
int EhMesmoCodigoFilme(tFilme *filme, int codigo);

/**
 * @brief Incrementa a quantidade alugada e decrementa a quantidade em estoque do filme;
 * 
 * @param filme Ponteiro para o filme;
 */
void AlugarFilme(tFilme *filme);

/**
 * @brief Decrementa a quantidade alugada e incrementa a quantidade em estoque do filme
 * 
 * @param filme Ponteiro para o filme;
 */
void DevolverFilme (tFilme *filme);

/**
 * @brief Compara dois filmes pelo nome;
 * 
 * @param filme1 Ponteiro para o primeiro filme;
 * @param filme2 Ponteiro para o segundo filme;
 * @return int 1 se o nome do primeiro filme for maior que o nome do segundo filme, -1 se o nome do primeiro filme for menor que o segundo filme, 0 se os nomes forem iguais;
 */
int CompararNomesFilmes(tFilme *filme1, tFilme *filme2);

/**
 * @brief Libera a memória alocada para o filme;
 * 
 * @param filme Ponteiro para o filme a ser destruido;
 */
void DestruirFilme(tFilme *filme);

#endif