#ifndef _empresa
#define _empresa
#include "funcionario.h"

typedef struct empresa {
    int id;
    tFuncionario funcionarios[20];
    int qtdFuncionarios;
}tEmpresa;

/**
 * @brief Cria uma empresa à partir de um id;
 * 
 * @param id ID (identificador) da empresa a ser criada;
 * @return tEmpresa empresa criada à partir do ID (identificador) fornecido;
 */
tEmpresa criaEmpresa(int id);

/**
 * @brief Lê os dados de uma empresa da entrada padrao;
 * 
 * @return tEmpresa Empresa a ser criada à partir dos dados lidos;
 */
tEmpresa leEmpresa();

/**
 * @brief Adiciona um funcionario a uma empresa caso o ID (identificador) do funcionário ainda não esteja registrado na empresa;
 * 
 * @param empresa Empresa na qual o funcionário será adicionado;
 * @param funcionario Funcionário que deve ser adicionado a empresa;
 * @return tEmpresa Empresa atualizada com a nova lista de funcionários;
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario);

/**
 * @brief Imprime todos os dados da empresa;
 * 
 * @param empresa Empresa a ser impressa;
 */
void imprimeEmpresa(tEmpresa empresa);

#endif