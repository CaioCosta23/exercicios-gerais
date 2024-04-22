#ifndef _empresa
#define _empresa

#include "funcionario.h"

typedef struct empresa {
    int id;
    tFuncionario **funcionarios;
    int qtdFuncionarios;
}tEmpresa;

/**
 * @brief Cria uma estrutura do tipo "tEmpresa" vázia (com atributos inicializados);
 * 
 * @return tEmpresa* Ponteiro para a estrutura do tipo "tEmpresa";
 */
tEmpresa *CriaEmpresa();

/**
 * @brief Lê os dados de uma empresa da entrada padrão;
 * 
 * @param empresa Ponteiro para a estrutura do tipo "tEmpresa";
 */
void LeEmpresa(tEmpresa *empresa);

/**
 * @brief Adiciona um funcionário a uma empresa caso o ID (Identificador) do funcionário ainda não esteja registrado na empresa;
 * 
 * @param empresa Ponteiro para a estrutura do tipo "tEmpresa" na qual o funcionário será adicionado (registrado);
 * @param funcionario Ponteiro para uma estrutura do tipo "tFuncionario" que contém os dados do funcionário que será adicionado a empresa;
 */
void ContrataFuncionarioEmpresa(tEmpresa *empresa, tFuncionario *funcionario);

/**
 * @brief Imprime todos os dados de uma empresa;
 * 
 * @param empresa Ponteiro para uma estrutura do tipo "tEmpresa" que terá seus dados impressos;
 */
void ImprimeEmpresa(tEmpresa *empresa);

/**
 * @brief Apaga (libera a memória alocada dinamicamente da) empresa;
 * 
 * @param empresa Ponteiro para uma estrutura do tipo "tEmpresa" que será apagada (liberada);
 */
void ApagaEmpresa(tEmpresa *empresa);

#endif