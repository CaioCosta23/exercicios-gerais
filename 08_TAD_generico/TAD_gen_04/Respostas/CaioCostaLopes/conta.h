#if !defined(_CONTA_H_)
#define _CONTA_H_

#include "vector.h"

typedef struct Conta tConta;

/**
 * @brief Cria (aloca a mmemória dinâmicamente de) uma conta;
 * 
 * @return tConta* Ponteiro para a estrutura do tipo "tConta" que contém os campos de dados da conta inicializados;
 */
tConta *CriaConta();

/**
 * @brief Lê as informações de uma conta;
 * 
 * @param conta Ponteiro para a estrutura o tipo "tConta" onde serão armazenadas as informações da conta;
 */
void LeConta(tConta *conta);

/**
 * @brief Obtém o saldo de uma conta bancária.
 * @param conta Ponteiro para a estrutura do tipo "tConta" que contém os dados atualizados da conta;
 * @return Saldo da conta bancária.
 */
float GetSaldoConta(tConta *conta);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) uma conta;
 * 
 * @param conta Ponteiro para a estrutura do tipo "tAgencia" que contém os dados atualizados da conta que será destruída;
 */
void DestroiAgencia(DataType *conta);

#endif