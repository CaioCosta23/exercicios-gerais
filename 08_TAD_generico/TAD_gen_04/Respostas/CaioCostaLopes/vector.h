
#ifndef _DATA_STRUCTURES_VECTOR_H_
#define _DATA_STRUCTURES_VECTOR_H_

typedef void *DataType;
typedef struct Vector Vector;

/**
 * @brief Cria (aloca a mmemória dinâmicamente de) um vetor de dados;
 * 
 * @return Ponteiro para a estrutura do tipo "Vector" que contém os campos de dados do vetor inicializados;
*/
Vector *VectorConstruct();

/**
 * @brief Adiciona um elemento no vetor;
 * 
 * @param v Ponteiro para a estrutura do tipo "Vector" que contém os campos de dados atualizados vetor;
 * @param val Dados (genéricos) a serem adicionados no vetor;
*/
void VectorPushBack(Vector *v, DataType val);

/**
 * @brief Obtém o i-ésimo elemento do vetor;
 * 
 * @param v Ponteiro para a estrutura do tipo "Vector" que contém os campos de dados atualizados vetor;
 * @param i Índice do Dado procurado;
 * @return DataType Dado do vetor
*/
DataType VectorGet(Vector *v, int i);

/**
 * @brief Obtém o tamanho do vetor
 * 
 * @param v Ponteiro para a estrutura do tipo "Vector" que contém os campos de dados atualizados vetor;
 * @return int Tamanho do vetor;
*/
int VectorSize(Vector *v);

/**
 * @brief Libera/destrói (desaloca a memória dinamicamente de) um vetor;
 * 
 * @param v Ponteiro para a estrutura do tipo "Vector" que contém os campos de dados atualizados vetor que será liberado;
 * @param destroy Função que libera/destrói (desaloca a memória dinâmicamentea memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType));

#endif
