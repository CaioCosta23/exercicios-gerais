#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct Array Array;

/**
 * @brief Cria (aloca memória dinamicamente para um) array (lista/ vetor) com seus parâmetros inicializados;
 * 
 * @return Array* Ponteiro para a estrutura do tipo "Array";
 */
Array *CriarArray();

/**
 * @brief Lê os elementos de um 'array' (lista/vetor);
 * 
 * @param array Ponteiro para a estrutura do tipo "Array" que terá seus campos preenchidos com as informações;
 */
void LerArray(Array *array);

/**
 * @brief Ordena os elementos de um array em ordem crescente;
 * 
 * @param array Ponteiro para a estrutura do tipo "Array" que terá seus elementos ordenados;
 */
void OrdenarArray(Array *array);

/**
 * @brief Realiza uma busca binária pelo 'array' (lista/vetor), buscando um elemento em específico;
 * 
 * @param array Ponteiro para a estrutura do tipo "Array" onde será realizada a busca do elemento;
 * @param elementoBuscado Elemento buscado;
 * @return int Índice do elemento buscado - caso o elemento buscado não seja encontrado, retorna o valor -1;
 */
int BuscaBinariaArray(Array *array, int elementoBuscado);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) um 'array' (lista/vetor); 
 * 
 * @param array Ponteiro para a estrutura do tipo "Array" que srá destruída;
 */
void DestruirArray(Array *array);

#endif