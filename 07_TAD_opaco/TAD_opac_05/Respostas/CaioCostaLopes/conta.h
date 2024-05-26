#ifndef _CONTA_H_
#define _CONTA_H_

typedef struct Conta tConta;

/**
 * @brief Cria uma conta (aloca a memória dinamicamente) com seus parâmetros inicializados;
 * 
 * @return tConta* Ponteiro para a estrutura do tipo "tConta" que receberá os dados das contas;
 */
tConta *CriaConta();

/**
 * @brief Lê os dados de uma conta de um usuário;
 * 
 * @param conta Ponteiro para a estrutura do tipo "tConta" que conterá os campos para os dados da conta a serem armazenados;
 */
void LeConta(tConta *conta);

/**
 * @brief Verifica/Compara a conta (seu ID - Identificador)tem o mesmo ID de um número especifico;
 * 
 * @param conta Ponteiro para a estrutura do tipo "tConta" da conta que será verificada/comparada com o número especificado;
 * @param numero Numero a ser verfificado/comparado ao da conta;
 * @return int 1 se o numero especificado é igual ao da conta (ID - identificador), 0 caso contrário;
 */
int VerificaConta(tConta *conta, int numero);

/**
 * @brief Realiza um saque em uma conta (caso o saldo da conta seja maior que 0 e seja suficiente para o saque solicitado);
 * 
 * @param conta Ponteiro para a estrutura do tipo "tConta" que contém os dados da conta onde será feito o saque;
 * @param valor Valor a ser sacado;
 */
void SaqueConta(tConta *conta, float valor);

/**
 * @brief Deposita um valor na conta (caso o valor a ser depoistado seja maior que 0);
 * 
 * @param conta Ponteiro para a estrutura do tipo "tConta" com os dados da conta na qual será realizado o depósito;
 * @param valor Valor a ser depositado;
 */
void DepositoConta(tConta *conta, float valor);

/**
 * @brief realiza uma transferência de um valor de uma conta para outra;
 * 
 * @param destino Ponteiro para a estrutura do tipo "tConta" com os dados da conta para onde será transferido o valor;
 * @param origem Ponteiro para a estrutura do tipo "tConta" com os dado da conta de onde será tranferido o valor;
 * @param valor Valor a ser transferido de uma conta para outra;
 */
void TansferenciaConta(tConta *destino, tConta *origem, float valor);

/**
 * @brief Imprime os dados de uma conta;
 * 
 * @param conta Ponteiro para a estrutura do tipo "tConta" com os dados que serão impressos;
 */
void ImprimeConta(tConta *conta);

/**
 * @brief Destrói (dealoca a memória dinamicamente de) uma conta;
 * 
 * @param conta Ponteiro para a estrutura do tipo "tConta" que será destruída;
 */
void DestroiConta(tConta *conta);

#endif