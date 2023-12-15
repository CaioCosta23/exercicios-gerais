#ifndef _ESFERA_UTILS_H
#define _ESFERA_UTILS_H

#define PI 3.14

/**
 * @brief Calcula o volume de uma esfera com raio "R";
 * 
 * @param R Raio da esfera;
 * @param volume Ponteiro para uma variável "float" que armazenará o valor do volume da esfera;
 */
void CalculaVolume (float R, float *volume);

/**
 * @brief Calcula a área de uma esfera com raio "R";
 * 
 * @param R Raio da esfera;
 * @param area Um ponteiro para uma variável 'flaot' que armazenará o valor da área da esfera;
 */
void CalculaArea(float R, float *area);

#endif