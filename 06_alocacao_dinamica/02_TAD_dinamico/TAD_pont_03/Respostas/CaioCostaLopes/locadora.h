#ifndef _LOCADORA_H
#define _LOCADORA_H

#include "filme.h"

typedef struct Locadora {
    tFilme **filme;
    int numFilmes;
    int lucro;
}tLocadora;

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL;
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente;
 */
tLocadora *CriaLocadora();

/**
 * @brief Verifica se um filme está cadastrado na locadora;
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada;
 * @param codigo Código do filme a ser verificado;
 * @return int 1 se o filme está cadastrado, 0 caso contrário;
 */
int VerificaFilmeCadastrado(tLocadora *locadora, int codigo);

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado;
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada;
 * @param filme Ponteiro para o filme a ser cadastrado;
 */
void CadastrarFilmeLocadora(tLocadora *locadora, tFilme filme);

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora;
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada;
 */
void LerCadastroLocadora(tLocadora *locadora);

/**
 * @brief Aluga um ou mais filmes da locadora;
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada;
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados;
 * @param quatidadeCodigos Número de códigos de filmes a serem alugados;
 */
void  AlugarFilmesLocadora(tLocadora *locadora, int *codigos, int quatidadeCodigos);

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora;
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada;
 */
void LerAluguelLocadora(tLocadora *locadora);

/**
 * @brief Devolve um ou mais filmes alugados da locadora;
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada;
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos;
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos;
 */
void DevolverFilmesLocadora(tLocadora *locadora, int codigos, int quantidadeCodigos);

/**
 * @brief Lê os dados de devolução de um  ou mais filmes e os devolve na locadora;
 * 
 * @param locadora Ponteiro para a instância tLocadora a ser atualizada;
 */
void LerDevolucaoLocadora(tLocadora *locadora);

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética;
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada;
 */
void OrdenarFilmesLocadora(tLocadora *locadora);

/**
 * @brief Consulta o estoque de filme da locadora;
 * 
 * @param locadora Ponteiro pata a instância de tLocadora a ser consultada;
 */
void ConsultarestoqueLocadora(tLocadora *locadora);

/**
 * @brief Consulta o lucro da locadora;
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada;
 */
void ConsultarLucroLocadora(tLocadora *locadora);

/**
 * @brief Destrói uma instância de tLocadora;
 * 
 * @param locadora Ponteiropara a instância de tLocadora a ser destruida;
 */
void DestruirLocadora(tLocadora *locadora);

#endif