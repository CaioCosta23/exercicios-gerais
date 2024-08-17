#ifndef _operacao
#define _operacao

#include "conta.h"

typedef struct Operacao tOperacao;

/**
 * @brief Cria (aloca a memóia dinamicamente) uma estrutura do tipo "tOperacao" inicializada;
 * 
 * @param conta Ponteiro para a estrutura do tipo "tConta" da conta o qual a operação será associada;
 * @param valor Valor da operação;
 * @return tOperacao* Ponteiro para a estrutura do tipo "tOperacao" que contém os campos de dados da operação inicailizados;
 */
tOperacao *CriaOperacao(tConta *conta, float valor);

/**
 * @brief Obtém o valor de uma operação específica;
 * 
 * @param op Ponteiro para a estrutura do tipo "tOperacao" que contém os dados da operação a ter seu valor obtido;
 * @return float Valor da operação realizada;
 */
float ConsultaValorOperacao(tOperacao *op);

/**
 * @brief Imprime uma operação;
 * 
 * @param op Ponteiro para a estrutura do tipo "tOperacao" que contém os dados atualizados de uma operação;
 */
void ImprimeOperacao(tOperacao *op);

/**
 * @brief Destrói (desaloca a memória alocada dinamicamente de) uma operação;
 * 
 * @param op Ponteiro para a estrutura do tipo "tOperacao" que será destruída (desalocada);
 */
void DestroiOperacao(tOperacao *op);

#endif