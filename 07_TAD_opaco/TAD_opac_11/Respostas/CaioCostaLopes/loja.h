#ifndef _LOJA_H_
#define _LOJA_H_

#include "vendedor.h"

typedef struct Loja tLoja;

/**
 * @brief Abre (aloca a memória dinamicamente de) uma loja, e inicializa seus campos de informação;
 * 
 * @param id ID (Identificador) da loja;
 * @param aluguel Valor do aluguel da loja;
 * @return tLoja* Ponteiro para a a estrutura do tipo "tJogo";
 */
tLoja *AbreLoja(int id, float aluguel);

/**
 * @brief Compara um ID d(identificador) com o ID (identificador) de uma loja, a fim de verificar se a loja existe;
 * 
 * @param loja Ponteiro para a estrutura do tipo "tLoja" que terá seu ID (Identificador) comparado com um outro;
 * @param id ID (Identificador) a ser comparado com o da loja;
 * @return int 1 se o ID (Identificador) da loja é igual ao outro ID (Identificador) e 0 caso contrário;
 */
int VerificaIdLoja(tLoja *loja, int id);

/**
 * @brief Contrata (adiciona) um novo vendedor (na lista/vetor/'array' de vendedores da loja) - se o mesmo não estiver regitrado;
 * 
 * @param loja Ponteiro para a estrutura do tipo "tLoja" em que será contratado (adicionado) o vendedor;
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" que será contratado (adicionado a lista de vendedores) na loja;
 */
void ContrataVendedor(tLoja *loja, tVendedor *vendedor);

/**
 * @brief Registra uma nova venda na loja;
 * 
 * @param loja Ponteiro para a a estrutura do tipo "tLoja" em  que será registrada a venda;
 * @param nome Nome do vendedor que realizou a venda;
 * @param valor Valor da venda;
 */
void RegistraVenda(tLoja *loja, char *nome, float valor);

/**
 * @brief Calcula o lucro total da loja;
 * 
 * @param loja Ponteiro para a estrutura do tipo "tLoja" em que será registrado o calculo do lucro total obtido pela loja (lucro de total de vendas menos despesas totais);
 */
void CalculaLucro(tLoja *loja);

/**
 * @brief Imprime o relatório da loja;
 * 
 * @param loja Ponteiro para a estrutura do tipo "tLoja" que terá suas informações impressas;
 */
void ImprimeRelatorioLoja(tLoja *loja);

/**
 * @brief Apaga (desaloca a memória alocada dinamicamente de) uma loja;
 * 
 * @param loja Ponteiro para a estrutura do tipo "tLoja" que será apagada;
 */
void ApagaLoja(tLoja *loja);

#endif