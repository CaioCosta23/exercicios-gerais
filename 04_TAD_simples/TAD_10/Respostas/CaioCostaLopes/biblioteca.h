#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "livro.h"

#define MAX_LIVROS 10

typedef struct {
    tLivros livros[MAX_LIVROS];
    int tamanho;
}tBiblioteca;

/**
 * @brief Inicializa uma biblioteca vazia;
 * 
 * @return tBiblioteca Biblioteca inicializada;
 */
tBiblioteca inicializarBiblioteca();

/**
 * @brief Adiciona um livro à biblioteca;
 * 
 * @param biblioteca Biblioteca onde o livro será adicionado;
 * @param livro Livro a ser adicionado;
 * @return tBiblioteca Biblioteca atualizada com o livro adicionado;
 * OBS: Se estiver dentro do tamanho máximo, imprimir "Livro adicionado com sucesso!", senão imprimir "A biblioteca está cheia. Não é possivel adicionar mais livros."
 */
tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro);

/**
 * @brief Remove um livro da biblioteca pelo seu título;
 * 
 * @param biblioteca Biblioteca do qual o livro será removido;
 * @param titulo Títuo do livro a ser removido;
 * @return tBiblioteca Biblioteca atualizada após a remoção do livro;
 * OBS: Se o título for encontrado, imprimir "Livro removido com sucesso!" sennão, imprimir "Livro não encointrado na biblioteca.";
 */
tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char titulo[]);

/**
 * @brief Verifica se o título digitado é igual ao título do livro;
 * 
 * @param livro Livro cujo o título será verificado;
 * @param titulo Título digitado pelo usuário;
 * @return int 0 se o título for igual;
 */
int verificaTituloDoLiivroNaBiblioteca(tLivros livro, char titulo[]);

/**
 * @brief Lista todos os livros presentes na biblioteca;
 * 
 * @param biblioteca Biblioteca cujo os livros serão listados;
 * OBS: Se não houver livros na biblioteca, imprimir "A biblioteca está vazia!";
 */
void listarLivrosDaBiblioteca(tBiblioteca biblioteca);

#endif