#ifndef _CONTA_H_
#define _CONTA_H_

#include "usuario.h"

typedef struct Conta {
    int numero;
    float saldo;
    tUsuario *user;
}tConta;

/**
 * @brief Cria (aloca dinâmicamente a memória para) uma nova conta;
 * 
 * OBS: Se não for possível alocar a memória, o programa é encerrado;
 * 
 * @return tConta* Um ponteiro para uma nova conta criada;
 */
tConta *CriaConta();

/**
 * @brief Verifica se uma conta possui um número já especificado;
 * 
 * @param conta Ponteiro para uma conta a ser verificada;
 * @param numero Número da conta a ser verificada;
 * @return int 1 se a conta possui o número especificado, 0 caso contrário;
 */

/**
 * @brief Lê os dados de uma conta e do usuário através da entrada padrão;
 * 
 * @param conta Ponteiro para a conta a ser lida;
 */
void LeConta(tConta *conta);

/**
 * @brief Verifica se o número de uma conta é igual a outra (fornecida);
 * 
 * @param conta Ponteiro para a estrutura do tipo "tConta" que conterá o número da conta a ser verificada;
 * @param numero Número a ser comparada com o número da conta;
 * @return int 1 se os números forem iguais, 0 caso contrário;
 */
int VerificaConta(tConta *conta, int numero);

/**
 * @brief Realiza um saque em uma conta caso o saldo seja suficiente;
 * 
 * @param conta Ponteiro para a conta a ter um valor sacada;
 * @param valor Valor a ser sacado;
 */
void SaqueConta(tConta *conta, float valor);

/**
 * @brief Realiza um depośito em uma conta;
 * 
 * @param conta Ponteiro para a conta a ter um valor depositado;
 * @param valor Valor a ser depositado;
 */
void DepositoConta(tConta *conta, float valor);

/**
 * @brief Realiza uma transferência entre duas contas, caso o saldo da conta de origem seja suficiente;
 * 
 * @param destino Ponteiro para a conta de destino da tranferência;
 * @param origem Ponteiro para a conta de origem da transferência;
 * @param valor Valor a ser transferido;
 */
void TransferenciaConta(tConta *destino, tConta *origem, float valor);

/**
 * @brief Imprime os dados de uma conta e do proprietário da mesma;
 * 
 * @param conta Ponteiro para a conta que terá seus dados impressos;
 */
void ImprimeConta(tConta *conta);

/**
 * @brief Destrói (desaloca a memória da) conta;
 * 
 * @param conta Ponteiro para a conta a ser (desalocada a memória) destruída;
 */
void DestroiConta(tConta *conta);

#endif