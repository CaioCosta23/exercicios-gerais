#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "livro.h"

#define MAX_LIVROS 10

typedef struct {
    tLivros *livros[MAX_LIVROS];
    int tamanho;
}tBiblioteca;

/**
 * @brief Inicializa uma estrutura do tipo "tBiblioteca" (alocando sua memória dinâmicamente) vazia;
 * 
 * OBS: Os dados do tipo ponteiro deverão ser inicializados com o valor 'NULL';
 * 
 * @return tBiblioteca* Estrutura do tipo "tBiblioteca" com seus dados inicioalizados;
 */
tBiblioteca *InicializarBiblioteca();

/**
 * @brief Adiciona um livro na biblioteca;
 * 
 * OBS: Se a biblioteca já estiver com a quantidade máxima de livros, imprimir "A biblioteca está cheia. Não é possiível adicionar mais livros.",
 *      caso contrário, imprima "Livro adicionando com sucesso!";
 * 
 * @param biblioteca Ponteiro para uma estrutura do tipo "tBiblioteca" que contém os dados da biblioteca;
 */
void AdicionarLivroNaBiblioteca(tBiblioteca *biblioteca, tLivros *livro);

/**
 * @brief Remove um livro da biblioteca;
 * 
 * OBS: Se o titulo do livro não for encontradi ou não hover livros na biblioteca, imprimir "Livro não encontrado na biblioteca.",
 *      caso contrário, imprimir "Livro removido com sucesso!";
 * 
 * @param biblioteca Ponteiro para a estrutura do tipo "tBiblioteca" que contem os dados da biblioteca;
 * @param titulo Titulo do livro que se busca remover da biblioteca;
 */
void RemoverLivroDaBiblioteca(tBiblioteca *biblioteca, char titulo[]);

/**
 * @brief Verifica se o titulo digitado é igual ao título do livro;
 * 
 * @param livro Ponteiro para uma estrutura do tipo "tLivros" que conterá o título do livro a ser verificado;
 * @param titulo Título do livro digitado pelo usuário;
 * @return int 1 se o título for igual, 0 caso contrário; 
 */
int VerificaTituloDoLivroNaBiblioteca(tLivros *livro, char *titulo);

/**
 * @brief Lista todos os livros presentes na biblioteca até o momento;
 * 
 * OBS: Se não hover livros na biblioteca, imprimir "A biblioteca está vázia!";
 * 
 * @param biblioteca Ponteiro para a estrutura do tipo "tBiblioteca" que contém os dados da biblioteca;
 */
void ListarLivrosDaBiblioteca(tBiblioteca *biblioteca);

/**
 * @brief Apaga (libera a memória alocada dinamicamente da) biblioteca;
 * 
 * @param bilblioteca Ponteiro para uma estrutura do tipo "tBilblioteca" que contém todos os dados da biblioteca até o momento;
 */
void ApagaBiblioteca(tBiblioteca *bilblioteca);

#endif