#ifndef _empresa
#define _empresa

#include "funcionario.h"

typedef struct empresa tEmpresa;

/**
 * @brief Cria (aloca a memória alocada dinamicamente) uma empresa com seus dados inicializados;
 * 
 * @return tEmpresa* Ponteiro para a estrutura do tipo "tEmpresa";
 */
tEmpresa *CriaEmpresa();

/**
 * @brief Lê os dados de uma empresa;
 * 
 * @param empresa Ponteiro para a estrutura do tipo "tEmpresa" com os campos que serão preenchidos com as informações lidas;
 */
void LeEmpresa(tEmpresa *empresa);

/**
 * @brief Adiciona um funcionário a empresa (caso o mesmo ainda não esteja registrado na empresa);
 * 
 * @param empresa Ponteiro para a estrutura do tipo "tEmpresa" na qual será adicionado (contratado) o funcionário;
 * @param funcionario Ponteiro para a estrutura do tipo "tFuncionário" que será adicionado (contratado) na lista (vetor/'array') de funcionários da empresa;
 */
void ContrataFuncionarioEmpresa(tEmpresa *empresa, tFuncionario *funcionario);

/**
 * @brief Imprime os dados da empresa;
 * 
 * @param empresa Ponteiro para a estrutura do tipo "tEmpresa" que contém os dados da empresa, e que serão impressos;
 */
void ImprimeEmpresa(tEmpresa *empresa);

/**
 * @brief Apaga (desaloca a memória alocada dinamicamente de) uma empresa;
 * 
 * @param empresa Ponteiro para a estrutura do tipo "tEmpresa" que será apagada;
 */
void ApagaEmpresa(tEmpresa *empresa);

#endif