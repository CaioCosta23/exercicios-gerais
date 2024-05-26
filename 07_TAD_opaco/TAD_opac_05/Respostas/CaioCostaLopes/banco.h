#ifndef _BANCO_H_
#define BANCO_H_

typedef struct Banco tBanco;

/**
 * @brief Cria um novo banco com 5 contas inicializada (e com a mmória alocada dinamicamente);
 * 
 * @return tBanco* Ponteiro para a estrutura do tipo "tBanco";
 */
tBanco *CriaBanco();

/**
 * @brief Abre uma nova conta no banco e adiciona a lista (vetor/'array') de contas;
 * 
 * @param banco Ponteiro para estrutura do tipo "tBanco" onde as contas aberta serão aramzenadas;S
 */
void AbreContaBanco(tBanco *banco);

/**
 * @brief Realiza um saque na conta do banco (se ela existir);
 * 
 * @param banco Ponteiro para a estrutura do tipo "tBanco" de onde será feito o saque;
 */
void SaqueContaBanco(tBanco *banco);

/**
 * @brief Realiza um depoósito na conta do banco (se ela existir);
 * 
 * @param banco Ponteiro para a estrutura do tipo "tBanco" onde será feito o depósito;
 */
void DepositoContaBanco(tBanco *banco);

/**
 * @brief Realiza uma transferência de uma conta para outra em um banco;
 * 
 * @param banco Ponteiro para a estrutura do tipo "tBanco" onde será realizada a transferência dos valores entre as contas (se elas existirem) dentro do banco;
 */
void TransferenciaContaBanco(tBanco *banco);

/**
 * @brief Imprime o relatório do banco com informações de todas as contas armazenadas;
 * 
 * @param banco Ponteiro para a estrutura do tipo "tBanco" do qual serão impressas as informações daas contas;
 */
void ImprimeRelatorioBanco(tBanco *banco);

/**
 * @brief Destrói (desaloca a memória alocada dinamicamente de) um banco;
 * 
 * @param banco Ponteiro para a estrutura do tipo "tBanco" que será destruída;
 */
void DestroiBanco(tBanco *banco);

#endif