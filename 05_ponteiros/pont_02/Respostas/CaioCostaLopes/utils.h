#ifndef _UTILS_H_
#define _UTILS_H_

/**
 * @brief Lê do usuário um intervalo de numeros inteiros;
 * 
 * @param m Ponteiro para a variável que receberá o valor do início do intrvalo;
 * @param n Ponteiro para a variável que receberá o valor do fim do intervalo;
 */
void LeIntevalo(int *m, int *n);

/**
 * @brief Verifica se um número é primo;
 * 
 * @param n Número a ser verificado;
 * @return int 1 se o número é primo e 0 caso contrário;
 */
int EhPrimo (int n);

/**
 * @brief Obtém o maior e o menor número primo de um intervalo;
 * 
 * @param m Início do intervalo;
 * @param n Fim do intervalo;
 * @param menor Ponteiro para a variável que contém o menor número primo encontrado;
 * @param maior Ponteiro para a variável que contém o maior número primo encontrado; 
 */
void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior);

#endif