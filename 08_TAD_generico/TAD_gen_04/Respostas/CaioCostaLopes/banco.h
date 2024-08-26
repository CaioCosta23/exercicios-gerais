#if !defined(_BANCO_H_)
#define _BANCO_H_

#include "agencia.h"
#include "vector.h"

typedef struct Banco tBanco;

/**
 * @brief Cria (aloca a mmemória dinâmicamente de) um banco;
 * 
 * @return tBanco* Ponteiro para a estrutura do tipo "tBanco" que contém os campos de dados do banco inicializados;
 */
tBanco *CriaBanco();

/**
 * @brief Lê as informações de um banco;
 * 
 * @param banco Ponteiro para a estrutura o tipo "tBanco" onde serão armazenadas as informações do banco;
 */
void LeBanco(tBanco *banco);
/**
 * @brief Adiciona uma agência no banco;
 * 
 * @param banco Ponteiro para a estrutura do tipo "tBanco" que contém os dados atualizados do banco;
 * @param agencia Ponteiro para a estrutura do tipo "tAgencia" que será adicionada ao banco;
 */
void AdicionaBanco(tBanco *banco, tAgencia *agencia);

/**
 * @brief Insere uma conta em uma agência pertencente ao banco;
 * @param banco Ponteiro para a estrutura do tipo "tBanco" que contém os dados atualizados do banco;
 * @param numAgencia Número da agência em que a conta será inserida;
 * @param cliente Ponteiro para a estrutura do tipo "tConta" que será adicionada a uma agência do banco;
 * @OBS: Verificar se a agência onde a conta será inserida pertece ao banco;
*/
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente);

/**
 * @brief Imprime um relatório sobre todas as contas de todas as agências do banco;
 * @param banco Ponteiro para a estrutura do tipo "tBanco" que contém os dados atualizados do banco;
 */
void ImprimeRelatorioBanco(tBanco *banco);

/**
 * @brief Destrói (desaloca a memória dinâmicamente de) um banco.
 * @param banco Ponteiro para a estrutura do tipo "tBanco" que contém os dados atualizados do banco a ser destruído.
 */
void DestroiBanco(tBanco *banco);

#endif

