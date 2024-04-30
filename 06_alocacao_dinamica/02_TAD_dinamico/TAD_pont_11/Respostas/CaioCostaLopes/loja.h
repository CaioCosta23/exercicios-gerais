#ifndef _LOJA_H_
#define _LOJA_H_

#include "vendedor.h"

typedef struct Loja {
    int id;
    int totalVendedores;
    int maxVendedores;
    float aluguel;
    float lucro;
    tVendedor **vendedores;
}tLoja;


/**
 * @brief Abre (Cria uma estrutura do tipo "tLoja" - e aloca dinamicamente a estrutura) uma loja;
 * 
 * @param id ID (identificador) da loja criada;
 * @param aluguel Aluguel da loja;
 * @return tLoja* loja com seus dados inicializados;
 */
tLoja *AbreLoja(int id, float aluguel);

/**
 * @brief Verifica se o ID (identificador) de uma loja é igual ao da outra;
 * 
 * @param loja Ponteiro para a estrutura do tipo "tLoja" que terá seu ID (identificador) verificado (comparado com outro ID fornecido);
 * @param id ID (identificador) fornecido para ser comparado com o da loja;
 * @return int 1 se os IDs forem iguais e 0 caso contrário;
 */
int VerificaIdLoja(tLoja *loja, int id);

/**
 * @brief Contrata (adiciona) um novo vendedor à loja;
 * 
 * @param loja Ponteiro para a estrutura do tipo "tLoja" no qual o vendedor será adicionado;
 * @param vendedor Ponteiro para uma estrutura do tipo "tVendedor" que faz referência ao vendedor que será contratado (adicionado) pela loja;
 */
void ContrataVendedor(tLoja *loja, tVendedor *vendedor);

/**
 * @brief Registra uma nova venda para um vendedor da loja;
 * 
 * @param loja Ponteiro para uma estrutura do tipo "tLoja"
 * @param nome Nome do vendedor que realizou a venda;
 * @param valor Valor da venda realizada;
 */
void RegistraVenda(tLoja *loja, char *nome, float valor);

/**
 * @brief Calcula o lucro da loja;
 * 
 * @param loja Ponteiro para a estrutura do tipo "tLoja" que terá seu lucro calculado;
 */
void CalculaLucro(tLoja *loja);

/**
 * @brief Imprime o relatório da loja;
 * 
 * @param loja Ponteiro para a estrutura do tipo "tLoja" que terá os dados da loja impressos no relatório;
 */
void ImprimeRelatorioLoja(tLoja *loja);

/**
 * @brief Apaga (e desaloca dinamicamente) a loja;
 * 
 * @param Loja Ponteiro para a estrutura do tipo "tLoja" que será apagada;
 */
void ApagaLoja(tLoja *Loja);

#endif