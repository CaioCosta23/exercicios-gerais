#ifndef _BANCO_H_
#define _BANCO_H_

#include "conta.h"

typedef struct Banco {
    tConta **contas;
    int qtdContas;
    int contasAlocadas;
}tBanco;

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta;
 * 
 * OBS: Se não for possível alocar memória, o programa é encerrado;
 * 
 * @return tBanco* Ponteiro para o novo banco;
 */
tBanco *CriaBanco();

/**
 * @brief Abre uma nova conta do banco e adiciona ao vetor de contas do banco;
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada;
 */
void AbreContaBanco(tBanco *banco);

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e se ela tiver saldo sufciente;
 * 
 * @param banco Ponteiro para o banco da conta que será realizado o saque o valor;
 */
void SaqueContaBanco(tBanco *banco);

/**
 * @brief Realiza um depoósito em uma conta do banco se ela existir;
 * 
 * @param banco Ponteiro para o banco da conta que será depositado o valor;
 */
void DepositoContaBanco(tBanco *banco);

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e se a conta de origem tiver saldo suficiente;
 * 
 * @param banco Ponteiro para o banco onde será realizada a transfrência entre as contas;
 */
void TransferenciaContaBanco(tBanco *banco);

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados;
 * 
 * @param banco Ponteiro para o banco a ter seus dados impressos;
 */
void ImprimeRelatorioBanco(tBanco *banco);

/**
 * @brief Destrói (desaloca a memória do) banco e todas as suas contas;
 * 
 * @param banco Ponteiro apara o banco a (ter sua memória desalocada) ser destruído
 */
void DestroiBanco(tBanco *banco);

#endif