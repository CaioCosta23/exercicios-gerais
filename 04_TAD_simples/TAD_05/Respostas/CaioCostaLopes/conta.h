#ifndef _CONTA_H_
#define _CONTA_H_

#include "usuario.h"

typedef struct Conta {
    int numero; // Número da conta;
    tUsuario user; // Usuário da conta;
    float saldo; // Saldo da conta;
}tConta;

/**
 * @brief Cria uma nova conta bancária;
 * 
 * @param numero Número da conta;
 * @param user Usuário da conta;
 * @return tConta Nova conta criada;
 */
tConta CriaConta(int numero, tUsuario user);

/**
 * @brief Imprime os dados de uma conta;
 * 
 * @param conta Conta bancária a ser impressa;
 */
void ImprimeConta(tConta conta);

/**
 * @brief Compara o número de uma conta bancária com um número dado;
 * 
 * @param conta Conta bancária ser comparada;
 * @param numero Número a ser comparado;
 * @return int 1 se os números forem iguais e 0, caso contrário;
 */
int VerificaConta(tConta conta, int numero);

/**
 * @brief Realiza um saque da conta bancária;
 * 
 * @param conta Conta bancária a ter o vlaor sacado;
 * @param valor Valor a ser sacado;
 * @return tConta A conta com  o novo saldo após o saque;
 */
tConta SaqueConta (tConta conta, float valor);

/**
 * @brief realiza um depósito em uma conta bancária;
 * 
 * @param conta Conta Bbncária a ter o valor depositado;
 * @param valor Valor a ser depositado;
 * @return tConta Conta com o novo saldo após o depósito;
 */
tConta DepositoConta(tConta conta, float valor);

#endif