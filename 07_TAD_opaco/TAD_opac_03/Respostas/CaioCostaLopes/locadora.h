#ifndef _LOCADORA_H
#define _LOCADORA_H

#include "filme.h"

typedef struct Locadora tLocadora;

/**
 * @brief Cria uma nova (estrutura do tipo "tLocadora") locadora;
 * 
 * @return tLocadora* Ponteiro para uma estrutura do tipo "tLocadora" com seus dados inicializados;
 */
tLocadora *CriarLocadora();

/**
 * @brief Verifica se um filme já está cadastrado na locadora;
 * 
 * @param locadora Ponteiro para a estrutura do tipo "tLocadora" que terá o filme verificado;
 * @param codigo Código que será comparado aos códigos dos filmes já resgistrados na locadora;
 * @return int 1 se o filme já estiver cadastrado, 0 caso contrário;
 */
int VerificarFilmeCadastrado(tLocadora *locadora, int codigo);

/**
 * @brief Cadastra um novo filme na locadora (caso ele ainda não esteja registrado na mesma);
 * 
 * @param locadora Ponteiro para a estrutura do tipo "tLocadora" que terá um  filme adicionado;
 * @param filme Pontero para a estrutura do tipo "tFilme" que será adicionado a locadora;
 */
void CadastrarFilmeLocadora(tLocadora *locadora, tFilme *filme);

/**
 * @brief Lê os dados de cadastro de um filme e o cadastro na locadora;
 * 
 * @param locadora Ponteiro para a estrutura do tipo "tLocadora" que terá o filme aramazendado após a leitura de seus dados (caso o mesmo já não esteja cadastrado);
 */
void LerCadastroLocadora(tLocadora *locadora);

/**
 * @brief Aluga um ou mais filmes da locadora;
 * 
 * @param locadora Ponteiro para a estrutura do tipo "tLocadora" de onde serão alugados os filmes;
 * @param codigos Lista (vetor/'array') de códigos a serem verificados;
 * @param quantidadeCodigos Quantidade de códigos presentes na lista de códigos;
 */
void AlugarFilmesLocadora(tLocadora *locadora, int codigos[], int quantidadeCodigos);

/**
 * @brief Lê o aluguel de um conjunto de filmes à partir da entrada padrão;
 * 
 * @param locadora Ponteiro para a estrutura do tipo "tLocadora" que terá seu(s) filme(s) alugado(s);
 */
void LerAluguelLocadora(tLocadora *locadora);

/**
 * @brief Devolve um ou mais filmes alugados à locadora;
 * 
 * @param locadora Ponteiro para a estrutura do tipo "tLocadora" que terá seu(s) filme(s) devolvido(s);
 * @param codigos Lista (vetor/'array') de códigos a serem verificados e comparados para saber qual deles será devolvido;
 * @param quantidadeCodigos Quantidade de códigos da lista de códigos;
 */
void DevolverFilmesLocadora(tLocadora *locadora, int codigos[], int quantidadeCodigos);

/**
 * @brief Lê os dados de um ou mais filmes que serão devolvidos a locadora;
 * 
 * @param locadora Ponteiro para a estrutura do tipo "tLocadora" que terá seu(s) filme(s) devolvido(s);
 */
void LerDevolucaoLocadora(tLocadora *locadora);

/**
 * @brief Ordena os filmes cadastrados na locadora em ordem alfabética;
 * 
 * @param locadora Ponteiro para a estrutura do tipo "tLocadora" que terá seus filmes ordenados;
 */
void OrdenarFilmesLocadora(tLocadora *locadora);

/**
 * @brief Consulta o estoque de filmes da locadora;
 * 
 * @param locadora Ponteiro para a estrutura do tipo "tLocadora" que terá seu estoque consultado;
 */
void ConsultarEstoqueLocadora(tLocadora *locadora);

/**
 * @brief Consulta o lucro da locadora;
 * 
 * @param locadora Ponteiro para a estrutura do tipo "tLocadora" que terá su lucro consultado;
 */
void ConsultarLucroLocadora(tLocadora *locadora);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) uma locadora; 
 * 
 * @param locadora Ponteiro para a estrutura do tipo "tLocadora" que será destruída (e terá sua memória desalocada dinamicamente);
 */
void DestruirLocadora(tLocadora *locadora);

#endif