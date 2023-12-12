#ifndef LIVRO_H
#define LIVRO_H

typedef struct {
    char titulo[100];
    char autor[50];
    int anoPublicacao;
}tLivros;

/**
 * @brief Lê os atributos de um livro à partir dea entrada padrão;
 * 
 * @return tLivros Livro com os seus respectivos atributos lidos;
 */
tLivros lerLivro();

/**
 * @brief Imprime os atributos de um livro;
 * 
 * @param livro Livro cujo os atributos erão lidos;
 */
void imprimeLivro(tLivros livro);

#endif