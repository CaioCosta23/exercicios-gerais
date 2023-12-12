#ifndef _LOJA_H
#define _LOJA_H_

#include "vendedor.h"

#define MAX_VENDEDORES 10

typedef struct loja {
    int id; // ID (identificador) da loja;
    int totalVendedores; // Número total de vendedores da loja;
    float aluguel; // Valor do aluguel da loja;
    float lucro; // Lucro da loja;
    tVendedor vendedores [MAX_VENDEDORES]; // Lista (vetor/ "array") d vendedores da loja;
}tLoja;

/**
 * @brief Abre uma nova loja;
 * 
 * @param id ID (identificador) da loja;
 * @param aluguel Valor do aluguel da loja;
 * @return tLoja Loja aberta (com os dados fornecidos);
 */
tLoja AbreLoja(int id, float aluguel);

/**
 * @brief Verifica se o ID (identificador) de uma loja é igual ao outro;
 * 
 * @param loja Loja com os dados completos;
 * @param id ID (identificador) a ser comparado com o da loja;
 * @return int 1 se os IDs (identificadores) forem iguais e 0 caso contrário;
 */
int VerificaIdLoja(tLoja loja, int id);

/**
 * @brief  Contrata um novo vendedor para a loja;
 * 
 * @param loja Loja e seus dados;
 * @param vendedor Vendedor a ser contratado e seus dados;
 * @return tLoja Loja atualizada, com o vendedor já contratado;
 */
tLoja ContrataVendedor(tLoja loja, tVendedor vendedor);

/**
 * @brief Registra uma nova venda para um vendedor da loja;
 * 
 * @param loja Loja e seus dados;
 * @param nome Nome do vendedor que realizou a venda;
 * @param valor Valor da venda a ser registrada;
 * @return tLoja Loja atualizada com o registro da venda;
 */
tLoja RegistraVenda(tLoja loja, char nome[50], float valor);

/**
 * @brief  Calcula o lucro da loja;
 * 
 * @param loja loja e seus dados;
 * @return tLoja Loja atualizada com o lucro calculado;
 */
tLoja CalculaLucro(tLoja loja);

/**
 * @brief  Imprime o relatório da loja;
 * 
 * @param loja Loja e seus dados;
 */
void imprimeRelatorioLoja(tLoja loja);

#endif