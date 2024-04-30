#ifndef _VENDEDOR_H_
#define _VENDEDOR_H_

typedef struct Vendedor {
    char nome;
    float valor_vendido;
    float salario;
    float prct_comissao;
}tVendedor;

/**
 * @brief Regitra (cria) um novo vendedor (estrutura do tipo "tVendedor" - alocada dinâmicamente);
 * 
 * @param nome Nome do vendedor;
 * @param salario Valor do salario recebido pelo vendedor;
 * @param prct_comissao Porcentagem da comissão de cada venda que será recebida pelo vendedor;
 * @return tVendedor* Ponteiro para uma estrutura do tipo "tVendedor" (alocada dinamicamente) que conterá os dados do vendedor;
 */
tVendedor *RegistraVendedor(char *nome, float salario, float prct_comissao);

/**
 * @brief Verifica se o nome de um vendedor é igual a outro fornecido;
 * 
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" que conterá o nome do vendedor a ser comparado com o outro nome fornecido;
 * @param nome Nome fornecido;
 * @return int 1 se o nome do vendedor for igual ao fornecido, 0  caso contrário;
 */
int VerificaNomeVendedor(tVendedor *vendedor, char nome[]);

/**
 * @brief Contabiliza uma venda para um vendedor;
 * 
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" que terá uma venda contabilizada;
 * @param valor Valor da venda a ser contabilizada em nome do vendedor;
 */
void ContabilizaVenda(tVendedor *vendedor, float valor);

/**
 * @brief Obtém o salário de um vendedor;
 * 
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" que terá seu salário obtido;
 * @return float Salário do vendedor;
 */
float GetSalario(tVendedor *vendedor);

/**
 * @brief Obtém a comissão de um vendedor;
 * 
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" que terá sua comissão obtida;
 * @return float Comissão do vendedor;
 */
float GetSalario(tVendedor *vendedor);

/**
 * @brief Obtém o total vendido por um vendedor;
 * 
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" que terá o total das vendas de um vendedor obtido;
 * @return float Valor total vendido pelo vendedor;
 */
float GetTotalVendido(tVendedor *vendedor);

/**
 * @brief Obtém o total recebido por um vendedor;
 * 
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" que terá o total do ganhos obtido;
 * @return float Valor total obtido (salário e comissão) pelo vendedor;
 */
float GetTotalRecebido(tVendedor *vendedor);

/**
 * @brief Imprime o relatório de um vendedor;
 * 
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" que terá os dados impressos;
 */
void ImprimeRelatorioVendedor(tVendedor *vendedor);

/**
 * @brief Apaga (desaloca dinamicamente) um vendedor;
 * 
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" que será apagado (e terá sua estrutura desalocada dinamicamente);
 */
void ApagaVendedor(tVendedor *vendedor);

#endif