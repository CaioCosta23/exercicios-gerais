#ifndef _UTILS_H_
#define _UTILS_H_

/**
 * @brief Cria um vetor de inteiros com o tamanho especificado (alocado dinan=micamente);
 * 
 * @param tamanho Tamanho do vetor a ser criado;
 * @return int Ponteiro para o vetor criado;
 * OBBS: Se houver erro na alocação, imprime uma mesnagem informando que houve erro e encerra o programa;
 */
int *CriaVetor(int tamanho);

/**
 * @brief Lê um vetor de inteiros de tamanho especificado;
 * 
 * @param vetor Ponteiro para o vetor a ser lido;
 * @param tamanho Tamanho do vetor a ser lido;
 */
void LeVetor(int *vetor, int tamanho);

/**
 * @brief Calcula a média dos valores de um vetor de inteiors com tamanho especificado;
 * 
 * @param vetor Ponteiro para o vetor a ser lido;
 * @param tamanho Tamanho do vetor a ser lido;
 * @return float Média dos valores do vetor;
 */
float CalculaMedia (int *vetor, int tamanho);

/**
 * @brief Libera a memória alocada para um vetor de inteiros;
 * 
 * @param vetor Ponteiro pata o vetor a ser liberado;
 */
void LiberaVetor(int *vetor);

#endif