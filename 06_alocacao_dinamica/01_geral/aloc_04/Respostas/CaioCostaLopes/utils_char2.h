#ifndef _UTILS_CHAR_H_
#define _UTILS_CHAR_H_

#define TAM_PADRAO 10

/**
 * @brief Cria um vetor de caracteres que consegue armazenar uma string igual a "TAM_PADRAO", alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas posições com o caractere "_" e a última posição deve conter o caractere '\0';
 * 
 * @return char* Ponteiro para o vetor criado;
 * 
 * OBS: Se houver erro de alocação, imprimir uma mesagem de erro e encerrar o programa;
 */
char *CriaVetorTamPadrao();

/**
 * @brief Aumenta o tamanho de um vetor alocado dinamicamente.
 * O vetor deve ser aumentao para conseguir alocar mais "TAM_PADRAO" caracteres (o vtor só pode ter tamamhos múltiplos de "TAM_PADRAO");
 * 
 * @param vetor Vetor a ser aumentado dinamicamente; 
 * @param tamanhoantigo Tamanho do vetor a ser modificado;
 * @return char* Ponteiro para o "novo" vetor;
 * 
 * OBS: Preencha as novas posições com "_", e lembre-se que a última posição deve conter o caractere '\0'.
 */
char *AumentaTamanhoVetor(char *vetor, int tamanhoantigo);

/**
 * @brief Lê uma string do tamanho especificado até um "enter" (caractere '\n') ser apertado;
 * Caso seja necessário alterar o tamanho do vetor, o tamanho deve ser atualizado para que o programa saiba o novo tamanho do vetor;
 * 
 * @param vetor Ponteiro para o vetor a ser lido;
 * @param tamanho Ponteiro para uma variável do tipo inteiro que armazena o tamanho atual do vetor;
 * @return char* Ponteiro para o vetor lido;
 */
char *LeVetor(char *vetor, int *tamanho);

/**
 * @brief Imprime a string;
 * 
 * @param vetor Ponteiro para o vetor a ser liberado;
 */
void ImprimeString(char *vetor);

/**
 * @brief Libera memória alocada para um vetor de caracteres;
 * 
 * @param vetor Ponteiro para o vetor a ser liberado;
 */
void LiberaVetor(char *vetor);

#endif