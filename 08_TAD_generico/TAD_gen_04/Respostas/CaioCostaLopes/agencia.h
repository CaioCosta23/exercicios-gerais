#if !defined(_AGENCIA_H_)
#define _AGENCIA_H_

#include "conta.h"
#include "vector.h"

typedef struct Agencia tAgencia;

/**
 * @brief Cria (aloca a mmemória dinâmicamente de) uma agência;
 * 
 * @return tAgencia* Ponteiro para a estrutura do tipo "tAgencia" que contém os campos de dados da agência inicializados;
 */
tAgencia *CriaAgencia();

/**
 * @brief Lê as informações de uma agência;
 * 
 * @param agencia Ponteiro para a estrutura o tipo "tAgencia" onde serão armazenadas as informações da agência;
 */
void LeAgencia(tAgencia *agencia);

/**
 * @brief Adiciona uma conta na agência;
 * 
 * @param agencia Ponteiro para a estrutura do tipo "tAgencia" que contém os dados atualizados da agência;
 * @param conta Ponteiro para a estrutura do tipo "tConta" que será adicionada a agência;
 */
void AdicionaConta(tAgencia *agencia, tConta *conta);

/**
 * @brief Comparaum número específico com o número de uma agência bancária;
 * 
 * @param numAgencia Número da agencia bancária;
 * @param agencia2 Ponteiro para a estrutura do tipo "tAgencia" que contém os dados atualizados da agência a ser verificada;
 * @return int 1 se os números forem iguais, 0 caso contrário;
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2);

/**
 * @brief Obtém o saldo médio (média do saldo de todas as contas) da agência;
 * 
 * @param agencia Ponteiro para a estrutura do tipo "tAgencia" que contém os dados atualizados da agência;
 * @return float Valor médio dos saldos das contas da agência;
 */
float GetSaldoMedioAgencia(tAgencia *agencia);

/**
 * @brief Função que imprime todos os dados de todas as contas da agência;
 * 
 * @param agencia Ponteiro para a estrutura do tipo "tAgencia" que contém os dados atualizados da agência que será impressa;
 */
void ImprimeDadosAgencia(tAgencia *agencia);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) uma agência;
 * 
 * @param agencia Ponteiro para a estrutura do tipo "tAgencia" que contém os dados atualizados da agência que será destruída;
 */
void DestroiAgencia(DataType *agencia);

#endif