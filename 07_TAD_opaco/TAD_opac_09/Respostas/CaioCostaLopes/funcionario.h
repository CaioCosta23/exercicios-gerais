#ifndef _funcionario
#define _funcionario

typedef struct funcionario tFuncionario;

/**
 * @brief Cria (aloca a memória alocada dinamicamente) uma estrutura do tipo "tFuncionario" com seus dados inicializados;
 * 
 * @return tFuncionario* Ponteiro para a estrutura do tipo "tFuncionario";
 */
tFuncionario *CriaFuncionario();

/**
 * @brief Lê os dados de um funcionário;
 * 
 * @param funcionario Ponteiro para a estrutura do tipo "tFuncionario" que terá seus campos preenchidos com os dados lidos;
 */
void LeFuncionario(tFuncionario funcionario);

/**
 * @brief Obtém o ID (identificador de um funcionário);
 * 
 * @param funcionario Ponteiro para a estrutura do tipo "tFuncionario" que contém o ID (Identificador) do funcionário;
 * @return int ID (Identificador) do funcionário;
 */
int GetIdFuncionario(tFuncionario *funcionario);

/**
 * @brief Imprime os dados de um funcionário;
 * 
 * @param funcionario Ponteiro para a estrutura do tipo "tFuncionario" que contém os dados do funcionário a serem impressos;
 */
void ImprimeFuncionario(tFuncionario *funcionario);

/**
 * @brief Apaga (desaloca a memória dinamicamente de) um funcionário;
 * 
 * @param funcionario Ponteiro para a estrutura do tipo "tFuncionario" que será apagado;
 */
void ApagaFuncionario(tFuncionario *funcionario);

#endif