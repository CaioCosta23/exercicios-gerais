#ifndef _sistema
#define _sistema

#include "data.h"

typedef struct Sitema tSistema;

/**
 * @brief Cria (aloca a memória dinâmicamente de) um sistema de gerenciamento de tiquets de estacionamento;
 * 
 * @return tSistema* Ponteiro para a estrutura do tipo "tSistema" que contém os campos de dados do sistema inicializados;
 */
tSistema *CriaSitema();

/**
 * @brief Lê s dados do sitema e dos tíquetes a serem processados;
 * 
 * @param sys Ponteiro para a estrutura do tipo "tSistema" que aramzenará os dados do sistema junto aos tíquetes;
 */
void LeSistema(tSistema *sys);

/**
 * @brief Processa um tíquete e calcula o valor que o moorista deve pagar;
 * 
 * @param sys Ponteiro para a estrutura do tipo "tSistema" que contém os dados do sistema e dos tíquetes;
 * @param dataEntrada Ponteiro para a estrutura do tipo "tData" que contém os dados da data de entrada do carro no estacionamento;
 * @param dataSaida Ponteiro para a estrutura do tipo "tData" que contém os dados da data de saída do carro do estacionamento;
 * @return float Valor a ser pago pelo usuário (motorista) pelo tíquete (que está registrado com a data de entrada e saída em questão);
 */
float CalculaPrecoTiquete(tSistema *sys, tData *dataEntrada, tData *dataSaida);

/**
 * @brief Imprime o faturamento do sistema;
 * 
 * @param sys Ponteiro para a estrutura do tipo "tSistema" que contém os dados do sistema;
 */
void ImprimeFaturamentoSistema(tSistema *sys);

/**
 * @brief Destrói (libera a memória alocada dinamicamente do) sistema;
 * 
 * @param sys Ponteiro para a estrutura do tipo "tSistema" que contém os dados do sistema;
 */
void DestroiSistema(tSistema *sys);

#endif