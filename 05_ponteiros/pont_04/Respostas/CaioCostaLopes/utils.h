#ifndef _UTILS_H_
#define _UTILS_H_

/**
 * @brief Lê uma sequência de inteiros da entrada padrão e os armazena em um array (lista);
 * 
 * @param array Ponteiro para onde os inteiros serao armazenados;
 * @param tamanho Tamanho do array (lista);
 */
void LeNumeros(int *array, int tamanho);

/**
 * @brief Encontra o maior, o menor e a média dos valores em um array de inteiros;
 * 
 * @param array Ponteiro para array de inteiros;
 * @param tamanho Tamanho do array (lista);
 * @param maior Ponteiro para uma variável que armazenará o maior valor;
 * @param menor Ponteiro para uma variável que armazenará o menor valor;
 * @param media Ponteiro para uma variável que armazenará a média dos valores;
 */
void EncontraMaiorMedia(int *array, int tamanho, int *maior, int *menor, float *media);

#endif