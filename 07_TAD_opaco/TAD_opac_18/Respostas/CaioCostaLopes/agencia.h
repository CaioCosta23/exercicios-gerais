#ifndef _agencia
#define _agencia

#include "conta.h"

typedef struct Agencia tAgencia;

/**
 * @brief Cria (aloca a memória dinamicamente) uma estrutura do tipo "tAgencia" inicializada;
 * 
 * @return tAgencia* Ponteiro para a estrutura do tipo "tAgencia" com seus campos de dados inicializados;
 */
tAgencia *CriaAgencia();

/**
 * @brief Lê as informações de uma agencia (contas e operações);
 * 
 * @param agencia Ponteiro para a estrutura do tipo "tAgencia" onde serão armazenadas as informações lidas;
 */
void LeOperacoes(tAgencia *agencia);

/**
 * @brief Busca uma conta na agencia que possui um id especifico;
 * 
 * @param agencia Ponteiro para a estrutura do tipo "tAgencia" que contém os dados (atualizados) da agência;
 * @param id ID (Identificador) da conta que será buscada;
 * @return tConta* Ponteiro para a estrutura do tipo "tConta" (que contém os dados da conta) da conta buscada na agencia;
 */
tConta *BuscaContaPorId(tAgencia *agencia, int id);

/**
 * @brief Imprime informações de qualquer operação suspeita dentro da agência;
 * 
 * @param agencia Ponteiro para a estrutura do tipo "tAgencia" com os dados atualizados da agência;
 */
void ImprimeOperacoesSuspeitas(tAgencia *agencia);

/**
 * @brief Imprime os dados dos dois correntistas com o maior saldo na agencia;
 * 
 * @param agencia Ponteiro para a estrutura do tipo "tAgencia" que contém os dados atualizados da agencia;
 */
void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia *agencia);

/**
 * @brief Imprime o saldo total que a agência possui;
 * 
 * @param agencia Ponteiro para a estrutura do tipo "tAgencia" que contém os dados atualzadaos da agência;
 */
void ImprimeSaldoTotal(tAgencia *agencia);

/**
 * @brief Destrói (desaloca a memória alocada dinâmicamente) uma agência;
 * 
 * @param agencia Ponteiro para a estrutura do tipo "tAgencia" que será destruída (desalocada);
 */
void DestroiAgencia(tAgencia *agencia);