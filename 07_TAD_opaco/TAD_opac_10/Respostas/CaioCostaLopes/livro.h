#ifndef LIVRO_H
#define LIVRO_H

#include <stdlib.h>

typedef struct Livros tLivros;

/**
 * @brief Cria (aloca a memória dinamicamente de) um livro com seus parâmetros inicializados;
 * 
 * @return tLivros* Ponteiro para a estrutura do tipo "tLivros";
 */
tLivros *CriaLivro();

/**
 * @brief Lê os dados de um livro e os armazena;
 * 
 * @param livro Ponteiro para a estrutura do tipo "tLivros" onde estão os campos em que as informações lidas serão armazenadas;
 */
void LerLivro(tLivros *livro);

/**
 * @brief Obtém o título de um livro;
 * 
 * @param livro Ponteiro para a estrutura do tipo "tLivro" de onde será obtido o título;
 * @return char* Ponteiro para o título do livro;
 */
char *getTitulo(tLivros *livro);

/**
 * @brief Imprime as informações de um livro;
 * 
 * @param livro Ponteiro para a estrutura odo tipo "tLivros" que terá suas informações impressas;
 */
void ImprimeLivro(tLivros *livro);

/**
 * @brief Apaga (desaloca a memória dinamicamente de) um livro;
 * 
 * @param livro Ponteiro para a estrutura do tipo "tLivros" que será apagada;
 */
void ApagaLivro(tLivros *livro);

#endif