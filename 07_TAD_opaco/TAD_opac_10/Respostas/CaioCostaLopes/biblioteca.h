#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "livro.h"

#define NUM_INICIAL_LIVROS 5

typedef struct Biblioteca tBiblioteca;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma biblioteca com seus parâmetros inicializados;  
 * 
 * @return tBiblioteca* Ponteiro para a estrutura do tipo "tBiblioteca";
 */
tBiblioteca *InicializarBiblioteca();

/**
 * @brief Adiciona um novo livro na biblioteca (caso o mesmo já nçao tenha sido adicionado e se a biblioteca não estiver cheia);
 * 
 * @param biblioteca Ponteiro para a estrutura do tipo "tBiblioteca" que terá um livro adicionado;
 * @param livro Ponteiro para a estrutura do tipo "tLivros" que será adicionado a biblioteca;
 */
void AdicionarLivroNaBiblioteca(tBiblioteca *biblioteca, tLivros *livro);

/**
 * @brief Remove um livro da biblioteca (se ele existir dentro da biblioteca e se a biblioteca nçao estiver vazia);
 * 
 * @param biblioteca Ponteiro para a estrutura do tipo "tBiblioteca" que terá um livro removido;
 * @param livro Ponteiro para a estrutura do tipo "tLivros" que será removido da biblioteca;
 */
void RemoverLivroDaBiblioteca(tBiblioteca *biblioteca, char titulo[]);

/**
 * @brief Verifica se o titulo do livro digitado é igual a algum título da lista de títulos passado;
 * 
 * @param livro Ponteiro para a estrutura do tipo "tLivros" que terá seu título comparado com os títulos da lista;
 * @param titulo Lista (vetor/'array') de títulos de livros  a serem comparados com o título do livro; 
 * @return int 1 se um dos títulos da lista for igual ao título do livro, 0 caso contrário;
 */
int VerificaTituloDoLivroNaBiblioteca(tLivros *livro, char titulo[]);

/**
 * @brief Lista (Imprime) todos os livros que estão na biblioteca;
 * 
 * @param biblioteca Ponteiro para a estrutura do tipo "tBiblioteca" que terá seus livros listados;
 */
void ListarLivrosdaBiblioteca(tBiblioteca *biblioteca);

/**
 * @brief Apaga (desaloca a memória dinamicamente de) uma biblioteca;
 * 
 * @param biblioteca Ponteiro para a estrutura do tipo "tBiblioteca" que será apagada;
 */
void ApagaBiblioteca(tBiblioteca *biblioteca);

#endif