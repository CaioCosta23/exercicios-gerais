#ifndef _conta
#define _conta

typedef struct Conta tConta;

/**
 * @brief Cria (aloca a memória alocada dinamicamente) uma estrutura do tipo "tConta" inicializada;
 * 
 * @param id ID (Identificador) da conta que será criada;
 * @return tConta* Ponteiro para a estrutura do tipo "tConta" com os campos de dados inicializados;
 */
tConta *CriaConta(int id);

/**
 * @brief Altera o saldo de uma conta;
 * 
 * @param conta Ponteiro para a conta do tipo "tConta" que terá o valor do saldo da conta alterado;
 * @param valor Valor para o qual será alterado o saldo da conta;
 */
void AlteraSaldoConta(tConta *conta, float valor);

/**
 * @brief Compara um ID (Identificador) com o ID da conta;
 * 
 * @param conta Ponteiro para a estrutura do tipo "tAgencia" que contém o ID (Identificador) da conta que será comparado;
 * @param id ID (Identificador) que será comparado com o ID da conta;
 * @return int 1 se os IDs forem os mesmos, 0 caso contrário;
 */
int ConfereIdConta(tConta *conta, int id);

/**
 * @brief Obtém o ID (Identificador) de uma conta;
 * 
 * @param conta Ponteiro para a estrutura do tipo "tConta" que contém os dados atualizados da conta;
 * @return int Valor ID (Identificador) da conta;
 */
int RetornaIdConta(tConta *conta);

/**
 * @brief Obtém o valor do saldo de uma conta;
 * 
 * @param conta Ponteiro para a estrutura do tipo "tConta" que contém os dados atualizados da conta;
 * @return float Valor do saldo da conta;
 */
float RetornaSaldoConta(tConta *conta);

/**
 * @brief Destrói (desaloca a memória alocada dinamicamente) uma conta;
 * 
 * @param conta Ponteiro para a estrutura do tipo "tConta" que será destruída (desalocada);
 */
void DestroiConta(tConta *conta);

#endif