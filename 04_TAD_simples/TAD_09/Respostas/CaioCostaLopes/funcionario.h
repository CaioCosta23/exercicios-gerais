#ifndef _funcionario
#define _funcionario

typedef struct funcionario {
    int id;
    float salario;
}tFuncionario;

/**
 * @brief Cria um funcionario à partir de valores de nome e salario;
 * 
 * @param id ID (identificador) do funcionario a ser criado;
 * @param salario Salario do funcionario a ser criado;
 * @return tFuncionario Funcionário criado;
 */
tFuncionario criaFuncionario(int id, float salario);

/**
 * @brief Lê dados de um funcionário da entrada padrao;
 * 
 * @return tFuncionario Funcionário criado à partir dos dados lidos;
 */
tFuncionario leFuncionario();

/**
 * @brief Obtém o ID (identificador) de um funciionário;
 * 
 * @param funcionario Funcionário que se deseja obter o ID (identificador);
 * @return int ID (identificador) do funcionário;
 */
int getIdFuncionario(tFuncionario funcionario);

/**
 * @brief Imprime todos os dados de um funcionário;
 * 
 * @param funcionario Funcionário que terá seus dados impressos;
 */
void imprimeFuncionario(tFincionario funcionario);