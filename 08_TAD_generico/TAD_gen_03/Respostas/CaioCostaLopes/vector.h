#ifndef _DATA_STRUCTURES_VECTOR_H_
#define _DATA_STRUCTURES_VECTOR_H_

typedef void *data_type;
typedef struct Vector Vector;

/**
 * @brief Cria (aloca a memória dinamicamente de) um vetor vazio;
 * 
 * @return Vector* Ponteiro para a estrutura do tipo "Vector" que contém os campos de dados do vetor inicializados;
 */
Vector *VectorConstruct();

/**
 * @brief Adiciona um elemento no final do vetor;
 * 
 * @param v Ponteiro para a estrutura do tipo "Vector" que contém os dados do vetor atualizados;
 * @param val Valor a ser adicionado;
 */
void VectorPushBack(Vector *v, data_type val);

/**
 * @brief Retorna o i-ésimo elemento do vetor;
 * 
 * @param v Ponteiro para a estrutura do tipo "Vector" que contém os dados do vetor atualizados;
 * @param i Índice do elemento no vetor;
 * @return data_type Elemento do vetor;
 */
data_type VectorGet(Vector *v, int i);

/**
 * @brief Obtém o tamanho do vetor;
 * 
 * @param v Ponteiro para a estrutura do tipo "Vector" que contém os dados do vetor atualizados;
 * @return int Tamanho do vetor;
 */
int VectorSize(Vector *v);

/**
 * @brief Destrói (libera a memória alocada dinamicamente de) um vetor;
 * 
 * @param v Ponteiro para a estrutura do tipo "Vector" que contém os dados do vetor que será destruído;
 * @param destroy Função que libera/ destrói (desaloca a memória alocada dinamicamente de) cada elemento do vetor;
 */
void VectorDestroy(Vector *v, void (*destroy)(data_type));

#endif