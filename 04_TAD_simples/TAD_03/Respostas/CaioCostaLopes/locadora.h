#ifndef _LOCADORA_H
#define _LOCADORA_H

#include "filme.h"

#define MAX_FILMES 100

typedef struct Locadora {
    tFilme filme[MAX_FILMES];
    int numFilmes;
    int lucro;
}tLocadora;

/**
 * @brief Cria uma nova locadora;
 * 
 * @return tLocadora Locadora criada;
 */
tLocadora criarLocadora();

/**
 * @brief Verifica se um filme está cadastrado na locadora;
 * 
 * @param locadora Locadora a ser consultada;
 * @param codigo Código do filme a ser verificado;
 * @return int 1 se o filme verificado está cadastrado e 0. caso contrário;
 */
int verificaFilmeCadastrado(tLocadora locadora, int codigo);

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado;
 * 
 * @param locadora Locadora a ser atualizada;
 * @param filme Filme a ser cadastrado;
 * @return tLocadora Locadora atualizada;
 */
tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme);

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão;
 * 
 * @param locadora Locadora a ser atualizada;
 * @return tLocadora Locadora atualizada;
 */
tLocadora lerCadastroLocadora (tLocadora locadora);

/**
 * @brief Aluga um conjunto de filmes da locadora;
 * 
 * @param locadora Locadora a ser atualizada;
 * @param codigos Lista (array) com os códigos dos filmes a serem alugados;
 * @param quantidadeCodigos Quantidade de códigos na lista (array);
 * @return tLocadora Locadora atualizada;
 */
tLocadora alugarFilmesLocadora (tLocadora locadora, int codigos[], int quantidadeCodigos);

/**
 * @brief Lẽ o aluguel de um conjunto de filmes a partir da entrada padrão;
 * 
 * @param locadora Locadora a ser atualizada;
 * @return tLocadora Locadora atualizada;
 */
tLocadora lerLocadoraAluguelLocadora (tLocadora locadora);

/**
 * @brief Devolve um conjunto de filmes a serem alugados;
 * 
 * @param locadora Locadora a ser atualizada;
 * @param codigos Lista (array) com os códigos dos filmes a serem  devolvidos;
 * @param quantidadeCodigos Quantidade de códigos da lista (array);
 * @return tLocadora Locadora atualizada;
 */
tLocadora devolverFilmesLocadora(tLocadora locadora, int codigos[], int quantidadeCodigos);

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão;
 * 
 * @param locadora Locadora a ser atualizada;
 * @return tLocadora Locadora atualizada;
 */
tLocadora lerDevolucaoLocadora(tLocadora locadora);

/**
 * @brief Ordena os filmes davoid locadora por nome;
 * 
 * @param locadora Locadora a ser ordenada;
 * @return tLocadora Locadora ordenada;
 */
tLocadora ordenarFilmesLocadora(tLocadora locadora);

/**
 * @brief Imprime o estoque da locadora;
 * 
 * @param locadora Locadora a ser consultada;
 */
void consultarEstoqueLocadora(tLocadora locadora);

/**
 * @brief Imprime o lucro da locadora;
 * 
 * @param locadora Locadora a ser consultada;
 */
void consultarLucroLocadora (tLocadora locadora);

#endif