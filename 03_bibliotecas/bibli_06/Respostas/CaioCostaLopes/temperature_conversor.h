#ifndef _temperature_conversor_
#define _temperature_conversor_

/**
 * @brief Converte a temperatura em Celsius para Kelvin; 
 * 
 * @param temperature Temperatura em Celsius; 
 * @return float Temperatura em Kelvin;
 */
float convert_celsius_to_kelvin(float temperature);

/**
 * @brief Converte a temperatura em Celsius para Fahrenheit;
 * 
 * @param temperature Temperatura em Celsius;
 * @return float Temperatura em Fahrenheit;
 */
float convert_celsius_to_fahrenheit(float temperature);

/**
 * @brief Converte a temperatura em Kelvin para Celsius;
 * 
 * @param temperature Temperatura em Kelvin;
 * @return float Temperatura em Celsius;
 */
float convert_kelvin_to_celsius(float temperature);

/**
 * @brief Converte a temperatura em Kelvin para Fahrenheint;
 * 
 * @param temperature Temperatura em Kelvin;
 * @return float Temperatura em Fahrenheit
 */
float convert_kelvin_to_fahrenheit(float temperature);

/**
 * @brief Converte a temperatura em Fahrenheit para Celsius;
 * 
 * @param temperature Temperatura em Fahrenheit;
 * @return float Temperatura em Celsius;
 */
float convert_fahrenheit_to_celsius(float temperature);

/**
 * @brief Converte a temperatura em Fahrenheit para Kelvin;
 * 
 * @param temperature Temperatura em Fahrenheit;
 * @return float Temperatura em Kelvin;
 */
float convert_fahrenheit_to_kelvin(float temperature);

/**
 * @brief Converte uma temperatura usanda uma função dada;
 * 
 * @param temperature Temperatura a ser convertida;
 * @param convert_func Função de conversão a ser usada;
 * @return float Temperatura convertida;
 */
float convert_temperature(float temperature, float convert_func(float temperature));

#endif