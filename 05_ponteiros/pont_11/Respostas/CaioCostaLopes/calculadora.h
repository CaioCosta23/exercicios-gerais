#ifndef _CALCULADORA_H
#define _CALCULADORA_H

/**
 * @brief Ponteiro para função que recebe dois números de ponto flutuante (deciamais - 'float') e realiza uma operação matemática;
 * 
 */
typedef float(*CalculatoraCallback)(float, float);

/**
 * @brief Função que realiza uma operação matemática entre dois números;
 * 
 * @param num1 Primeiro Número;
 * @param num2 Segundo Número;
 * @param operacao Ponteiro para a função que realiza a operação matemática;
 * @return float Resultado da operação matemática;
 */
float Calcular(float num1, float num2, CalculatoraCallback operacao);

#endif