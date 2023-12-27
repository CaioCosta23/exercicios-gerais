#ifndef _FILME_H
#define _FILME_H

#define MAX_CARACTERES 20


typedef struct Filme {
    int codigo;
    char nome [MAX_CARACTERES];
    int valor;
    int qtdEstoque;
    int qtdAlugada;
}tFilme;

/**
 * @brief Cria um novo filme;
 * 
 * @param nome Nome do filme;
 * @param codigo Codigo do filme;
 * @param valor Valor do filme;
 * @param quantidade Quantidade em estoque;
 * @return tFilme Filme criado;
 */
tFilme criaFilme(char nome[], int codigo, int valor, int quantidade);

/**
 * @brief Lê um filme;
 * 
 * @param codigo Código do filme;
 * @return tFilme Filme;
 */
tFilme leFilme (int codigo);

/**
 * @brief Obtém o código de um filme;
 * 
 * @param filme filme a ser consultado;
 * @return int Código do filme;
 */
int obterCodigoFilme(tFilme filme);

/**
 * @brief Imprime o nome de um filme;
 * 
 * @param filme Filme a ser impresso;
 */
void imprimeNomeFilme(tFilme filme);

/**
 * @brief Obtém o valor de um filme;
 * 
 * @param filme Filme a ser consultado;
 * @return int Valor do filme;
 */
int obterValorFilme(tFilme filme);

/**
 * @brief Obtém a quantidade em estoque de um filme;
 * 
 * @param filme Filme a ser consultado;
 * @return int Qauntidade de fitas do filme em estoque na locadora;
 */
int obterQtdEstoqueFilme(tFilme filme);

/**
 * @brief Obtém a quandidade alugada de um filme;
 * 
 * @param filme Filme a ser consultado;
 * @return int Quantidade alugada de um filme;
 */
int obterQuantidadeAlugadaFilme(tFilme filme);

/**
 * @brief Verifica se um filme possui um determinado código;
 * 
 * @param filme Filme a ser consultado;
 * @param codigo Código a ser verificado;
 * @return int 1 se o filme possui código e 0, caso contrário;
 */
int ehMesmoCodigoFilme(tFilme filme, int codigo);

/**
 * @brief Aluga um filme;
 * 
 * @param filme Filme a ser alugado;
 * @return tFilme Filme com a quantidade alugada atualizada;
 */
tFilme alugarFilme(tFilme filme);

/**
 * @brief Devolve um filme;
 * 
 * @param filme Filme a ser devolvido;
 * @return tFilme Filme com a quantidade alugada atualizada;
 */
tFilme devolveFilme(tFilme filme);

/**
 * @brief Compara os nomes de dois filmes;
 * 
 * @param filme1 Primeiro filme a ser comparado;
 * @param filme2 Segundo filme a ser comparado;
 * @return int 0 se s nomes sao iguais, um valor negativo se o nome do primeiro filme for menor que o segundo
 * um valor positivo se o nome do segundo filme for maior que o primeiro;
 */
int compararNomesFilme (tFilme filme1, tFilme filme2);

#endif