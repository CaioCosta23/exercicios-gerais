#ifndef LIVRO_H
#define LIVRO_H

#include <stdlib.h>

typedef struct {
    char *titulo;
    char *autor;
    int anoPublicacao;
}tLivros;

/**
 * @brief Cria uma estrutura do tipo "tLivros" com seus dados inicializados;
 * 
 * OBS: Os dados do tipo ponteiro devem ser inicializados com o valor 'NULL';
 * 
 * @return tLivros* Ponteiro para a estrutura "tLivros" vazia, com seus dados inicailizados;
 */
tLivros *CriaLivro();

/**
 * @brief Lê os atributos de um livro à partir da entrada padrão;
 * 
 * @param livro Ponteiro para a estrutura do tipo "tLivros" que conterá os dados lidos do livro;
 */
void LerLivro(tLivros *livro);

/**
 * @brief Imprime os atributos de um livro;
 * 
 * @param livro Ponteiro para a estrutura do tipo "tLivros" que contém os dados do livro;
 */
void ImprimeLivro(tLivros *livro);

/**
 * @brief Apaga (libera a memória alocada dinamicamente) o livro;
 * 
 * @param livro Ponteiro para a estrutura do tipo "tLivro" que será apagado;
 */
void ApagaLivro(tLivros *livro);

#endif