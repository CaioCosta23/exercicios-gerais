#ifndef _STRING_UTILS_H_
#define STRING_UTILS_H_

/**
 * @brief Retorna o tamanho de uma string;
 * 
 * @param str String para se obter o tamanho;
 * @return int Tamanho da string;
 */
int string_lenght(char str[]);

/**
 * @brief Copia uma string de origem para o destino;
 * 
 * @param str String de origem;
 * @param dest String de destino;
 */
void string_copy(char str[], char dest[]);

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas;
 * 
 * @param str String a ser convertida;
 */
void string_upper(char str[]);

/**
 * @brief Converte todos os caracteres de uma string para minúsculo; 
 * 
 * @param str String a ser convertida;
 */
void string_lower(char str[]);

/**
 * @brief Inverte uma string;
 * 
 * @param str String a ser invertida;
 */
void string_reverse(char str[]);

#endif