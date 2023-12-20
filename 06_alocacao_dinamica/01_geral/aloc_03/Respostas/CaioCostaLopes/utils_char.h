#ifndef _UTILS_CHAR_H_
#define _UTILS_CHAR_H_

/**
 * @brief Cria um vetor de caracteres de tamanho especificado, alocado dinamicamente (neste caso, a string deve ser inicializada com todas as suas posicoes com "_");
 * 
 * @param tamanho Tamanho do vetor a ser criado;
 * @return char* Ponteiro para o vetor criado;
 * OBS: Se houvet erro na alocação, imprimir uma mesnagem de erro e encerrar o programa;
 */
char *CriaVetor(int tamanho);

/**
 * @brief Lê uma string (lista de caracteres)) do tamanho especificado;
 * 
 * @param vetor Ponteiro para o vetor a ser lido;
 * @param tamanho Tamanho do vetor a ser lido;
 */
void LeVetor(char *vetor, int tamanho);

/**
 * @brief Imprime a string (lista de caracteres);
 * 
 * @param vetor Ponteiro para o vetor a ser lido;
 * @param tamanho Tamanho do vetor;
 */
void ImprimeString(char *vetor, int tamanho);

/**
 * @brief Libera a memória alocada para o vetor de caracteres;
 * 
 * @param vetor Ponteiro para o vetor a ser lido;
 */
void LiberaVetor(char *vetor);

#endif
