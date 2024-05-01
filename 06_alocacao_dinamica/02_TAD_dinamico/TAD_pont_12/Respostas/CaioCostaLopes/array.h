#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct Array {
    int *data;
    int tamanho;
}Array;

/**
 * @brief Inicializa uma estrutura do tipo "Array" (que contem a data apontando para NULL com tamanho 0);
 * 
 * @return Array* Estrutura do tipo "Array" (alocada dinâmicamente) com seus parâmetros inicializados;
 */
Array *CriarArray();

/**
 * @brief Lê os elementos do array a partir da entrada padrão e aloca memória para eles;
 * 
 * @param array Ponteiro para uma estrutura do tipo "Array" a ser preenchda;
 */
void LeArray(Array *array);

/**
 * @brief Ordena os elementos do array em ordem crescente;
 * 
 * @param array Ponteiro para a estrutura do tipo "Array" que terá seus elementos ordenados;
 */
void OrdenarArray(Array *array);

/**
 * @brief Realiza uma busca binária no array pelo elemento especificado;
 * 
 * @param array Ponteiro para a estrutura do tipo "Array" que terá seus elementos analisados em busca de um elemento específico;
 * @param elementoBuscado Elemento a ser buscado dentro do vetor (array);
 * @return int Indice do elemento buscado na lista (array), ou -1 caso não seja encontrado;
 */
int BuscaBinariaArray(Array *array, int elementoBuscado);

/**
 * @brief Apaga (desaloca a memória alocada dinamicamente do) array;
 * 
 * @param array Ponteiro para a estrutura do tipo "Array" que será apagada (desalocada);
 */
void DestruirArray(Array *array);

#endif