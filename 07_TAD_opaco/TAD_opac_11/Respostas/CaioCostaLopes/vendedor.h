#ifndef _VENDEDOR_H_
#define _VENDEDOR_H_

typedef struct Vendedor tVendedor;

/**
 * @brief Cria/Registra (aloca a memória dinamicamente de) um novo vendedor;
 * 
 * @param nome Nome do vendedor;
 * @param salario valor do salário do vendedor;
 * @param prct_comisao Valor (decimal) da porcentagem da comissão que o vendedor receberá do valor de cada venda por ele efetuada;
 * @return tVendedor* Ponteiro para a estrutura do tipo "tVendedor" com os seus campos inicializados com os dados passados anteriormente;
 */
tVendedor *RegistraVendedor(char *nome, float salario, float prct_comisao);

/**
 * @brief Verifica se o nome do vendedor é igual a um otro nome;
 * 
 * @param vendedor Ponteiro para a etrutura do tipo "tVendedor" que terá seu nome comparado com outro nome;
 * @param nome Nome a ser comparado com o do vendedor;
 * @return int 1 se o nome do vendedor for igual ao outro nome, 0 caso contrário;
 */
int VerificaNomeVendedor(tVendedor *vendedor, char nome[]);

/**
 * @brief Contabiliza uma venda en nome de um vendedor;
 * 
 * @param vendedor ponteiro para a estrutura do tipo "tVendedor" para o qual será contabilizada a venda;
 * @param valor Valor da venda efetuada;
 */
void ContabilizaVenda(tVendedor *vendedor, float valor);

/**
 * @brief Obtém o salário de um vendedor;
 * 
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" que contém o salário do vendedor;
 * @return float Valor do salário do vendedor;
 */
float GetSalario(tVendedor *vendedor);

/**
 * @brief Obtém o valor (decimal - da porcentagem) da comissão que o vendedor obtém em cada venda;
 * 
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" qque contém o valor (decimal - da porcentagem) da comissão do vendedor;
 * @return float Valor (decimal - da porcentagem) da comissão do vendedor;
 */
float GetComissao(tVendedor *vendedor);

/**
 * @brief Obtém o valor total vendido pelo vendedor;
 * 
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" do qual será obtido ottal vendidi pelo vendedor;
 * @return float Valor total vendido pelo vendedor;
 */
float GetTotalVendido(tVendedor *vendedor);

/**
 * @brief Obtém o valor total que será recebido pelo vendedor (incluindo salário e valor rcebido por comissões de venda);
 * 
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" que contém os dados dos valores recebido pelo vendedor (em salário e comissões de venda);
 * @return float Valor total recebido pelo vendedor (salário mais comissões de vendas);
 */
float GetTotalRecebido(tVendedor *vendedor);

/**
 * @brief Imprime o relatório de vendas de um vendedor;
 * 
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" que terá as informações de venda de um vendedor impressas;
 */
void ImprimeRelatorioVendedor(tVendedor *vendedor);

/**
 * @brief Apaga (desaloca a memória dinamicamente de) um vendedor;
 * 
 * @param vendedor Ponteiro para a estrutura do tipo "tVendedor" que será apagada;
 */
void ApagaVendedor(tVendedor *vendedor);

#endif