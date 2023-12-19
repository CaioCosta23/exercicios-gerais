#ifndef _VETOR_H_
#define _VETOR_H_

#define TAMANHO_MAXIMO 10

typedef int (*Operation)(int, int);

typedef struct vetor {
    int elementos[TAMANHO_MAXIMO];
    int tamanhoUtilizado;
}Vetor;

/**
 * @brief Lê um vetor da entrada padrão;
 * 
 * @param vetor Ponteiro para o vetor que será lido;
 */
void LeVetor(Vetor *vetor);

/**
 * @brief Aplica uma operação em um vetor;
 * 
 * @param vetor Ponteiro para o vetor que será utilizado;
 * @param op Ponteiro para a função que será aplicada;
 * @return int Resultado da operação;
 */
int AplicarOperacaoVetor(Vetor *vetor, Operation op);

#endif