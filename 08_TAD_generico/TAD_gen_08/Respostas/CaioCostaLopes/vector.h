#ifndef _DATA_STRUCTURES_VECTOR_H_
#define _DATA_STRUCTURES_VECTOR_H_

typedef void *DataType;
typedef struct Vector Vector;

/**
 * @brief Cria (aloca a memória dinamicamente de) um vetor;
 * 
 * @return Ponteiro para a estrutura do tipo "Vector" que contém os campos de dados inicializados do vetor;
*/
Vector *VectorConstruct();

/**
 * @brief Adiciona um elemento no final do vetor;
 * 
 * @param v Ponteiro para a estrutura do tipo "Vector" que contém os dados atualizados do vetor;
 * @param val Valor a ser adicionado no final do vetor;
*/
void VectorPushBack(Vector *v, DataType val);

/**
 * @brief Remove o primeiro elemento do vetor e organiza os demais elementos, ou seja, 
 * o segundo elemento passa a ser o primeiro, o terceiro passa a ser o segundo, e assim por diante.
 * 
 * @param v Ponteiro para a estrutura do tipo "Vector" que contém os dados atualizados do vetor;
 * 
 * @return DataType Elemento removido;
*/
DataType VectorPopFront(Vector *v);

/**
 * @brief Retorna o 'i-ésimo' elemento do vetor;
 * 
 * @param v Ponteiro para a estrutura do tipo "Vector" que contém os dados atualizados do vetor;
 * @param i Índice do elemento;
 * 
 * @return DataType Elemento do vetor;
*/
DataType VectorGet(Vector *v, int i);

/**
 * @brief Obtém o tamanho do vetor;
 * 
 * @param v Ponteiro para a estrutura do tipo "Vector" que contém os dados atualizados do vetor;
 * 
 * @return int Tamanho do vetor;
*/
int VectorSize(Vector *v);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) um vetor;
 * 
 * @param v Ponteiro para a estrutura do tipo "Vector" que contém os dados atualizados do vetor;
 * 
 * @param destroy Função ("callback") que libera a memória alocada para cada elemento do vetor;
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType));

#endif