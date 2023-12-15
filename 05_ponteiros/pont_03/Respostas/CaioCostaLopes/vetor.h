#ifndef _VETOR_H_
#define _VETOR_H_

/**
 * @brief Lê dados do usuário e armazena em um vetor;
 * 
 * @param vet Ponteiro para o vetor que receberá os valores lidos;
 * @param tam Tamanho do vetor;
 */
void LeDadosParaVetor(int *vet, int tam);

/**
 * @brief Imprime os dados de um vetor na tela;
 * 
 * @param n Ponteiro para o vetor a ser impresso;
 * @param tam Tamanho do vetor;
 */
void ImprimeDadosVetor(int *n, int tam);

/**
 * @brief Troca o valor de duas variáveis se o segundo for menor que o primeiro;
 * 
 * @param vet Ponteiro para o vetor a ser percorrido;
 * @param tam Tamanho do vetor;
 * @param paraTrocar Ponteiro para a variável que armazenará o índice do menor valor encontrado;
 * OBS: Essa função tem o comportamento de encontrar o menor valor do vetor de tamanho "tam". Se esse valor for menor que o valor apontado por "paraTrocar",
 * é realizada a troca de posição. Ao final da execução, a variável apontada por "paraTrocar" terá o menor valor encontrado;
 */
void TrocaSeAchaMenor(int *vet, int tam, int *paraTrocar);

/**
 * @brief Ordena um vetor em ordem crescente;
 * 
 * @param vet Ponteiro para o vetor a ser ordenado;
 * @param tam Tamanho do vetor;
 */
void OrdenaCrescente(int *vet, int tam);

#endif