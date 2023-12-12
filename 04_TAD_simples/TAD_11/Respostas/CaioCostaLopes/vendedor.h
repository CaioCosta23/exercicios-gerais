#ifndef _VENDEDOR_H_
#define _VENDEDOR_H_

typedef struct Vendedor {
    char nome[50]; // Nome do vendedor;
    float valor_vendido; //Valor total vendido pelo vendedor;
    float salario; // Salário base do vendedor;
    float prct_comissao; // porcentagem de comissão do vendedor
}tVendedor;

/**
 * @brief Registra um novo vendedor;
 * 
 * @param nome Nome do vendedor;
 * @param salario Salario do vendedor;
 * @param prct_comissao Porcentagem de comissao do vendedor;
 * @return tVendedor Vendedor e seus dados atualizados;
 */
tVendedor RegistraVendedor(char nome[50], float salario, float prct_comissao);

/**
 * @brief Verifica se o nome de um vendedor é igual ao outro;
 * 
 * @param vendedor Vendedor e seus dados;
 * @param nome Nome a ser comparado com o do vendedor analisado;
 * @return int 1 se os nomes foresm iguais e 0 caso contrario;
 */
int VerificaNomeVendedor(tVendedor vendedor, char nome[50]);

/**
 * @brief Contabiliza uma venda para um vendedor;
 * 
 * @param vendedor vendedor e seus dados;
 * @param valor Valor da venda a ser contabilizda;
 * @return tVendedor Vendedor com os dados atualizados (em com a venda contabilizada);
 */
tVendedor ContabilizaVenda(tVendedor vendedor, float valor);

/**
 * @brief Obtém o valor do salário de um vendedor;
 * 
 * @param vendedor Vendedor e seus dados;
 * @return float Salario do vendedor;
 */
float GetSalario(tVendedor vendedor);

/**
 * @brief Obtém o valor da comissão de um vendedor;
 * 
 * @param vendedor Vendedor e seus dados;
 * @return float Valor da comissão do vendedor;
 */
float GetComissao(tVendedor vendedor);

/**
 * @brief Obtém o valor total vendido por um vendedor;
 * 
 * @param vendedor Vendedor e seus dados;
 * @return float Valor total vendido por um vendedor;
 */
float GetTotalVendido(tVendedor vendedor);

/**
 * @brief Obtém o total recebido por um vendedor;
 * 
 * @param vendedor Vendedor e seus dados
 * @return float Valor total recebido por um vendedor;
 */
float GetTotalRecebido(tVendedor vendedor);

/**
 * @brief Imprime o relatṕorio de um vendedor;
 * 
 * @param vendedor Vendedor e seus dados;
 */
void ImprimeRelatorioVendedor(tVendedor vendedor);

#endif