#if !defined(_FILA_H_)
#define _FILA_H_

#include "vector.h"

typedef struct Fila Fila;

/**
 * @brief Cria (aloca amemória dinamicamente de) ma fila;
 * 
 * @return Ponteiro para a estrutura do tipo "Fila" que contém os campos dados iniializados da fila;
*/
Fila *FilaConstruct();

/**
 * @brief Obtém o tamanho da fila
 * 
 * @param f Ponteiro para a estrutura do tipo "Fila" que contém os dados atualizados da fila;
 * 
 * @return int Tamanho da fila;
*/
int FilaSize(Fila *f);

/**
 * @brief Remove o primeiro elemento da fila;
 * 
 * @param f Ponteiro para a estrutura do tipo "Fila" que contém os dados atualizados da fila;
 * 
 * OBS: Note que a fila é uma estrutura FIFO (First In, First Out), ou seja, o primeiro elemento a ser adicionado é o primeiro a ser removido.
 * Portanto, apesar da fila estar implementada com um vector, ele não é adequado para implementar uma fila, pois a remoção de um elemento do início do vetor é uma operação custosa.
 * @return DataType Elemento removido da fila;
*/
DataType FilaPop(Fila *f);

/**
 * @brief Adiciona um elemento no final da fila;
 * 
 * @param f Ponteiro para a estrutura do tipo "Fila" que contém os dados atualizados da fila;
 * @param val Valor a ser adicionado no final da fila;
*/
void FilaPush(Fila *f, DataType val);

/**
 * @brief Desaloca a memória alocada para a fila
 * 
 * @param f Ponteiro para a fila
 * @param destroy Função ("callback") que libera a memória alocada para cada elemento da fila;
*/
void FilaDestroy(Fila *f, void (*destroy)(DataType));

#endif
