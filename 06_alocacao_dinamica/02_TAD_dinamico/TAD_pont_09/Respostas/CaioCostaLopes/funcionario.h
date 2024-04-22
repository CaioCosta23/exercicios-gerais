#ifndef _funcionario
#define _funcionario

typedef struct funcionario {
    int id;
    float salario;
}tFuncionario;

/**
 * @brief Cria uma estrutura do tipo "tFuncionario" que conterá os dados do funcionário (inicializados);
 * 
 * OBS: Seus atributos devem ser inicializados com o valor -1;
 * 
 * @return tFuncionario* Ponteiro para uma estrutura do tipo "tFuncionario" com seus dados inicializados;
 */
tFuncionario *CriaFuncionario();

/**
 * @brief Lê os dados de um funcionário da entrada padrão, armazenando-os na estrutura do tipo "tFuncionario";
 * 
 * @param funcionario Ponteiro para a estrutura do tipo "tFuncionario" que teraá seus dados lidaos da entrada padrão e armazenados;
 */
void LeFuncionario(tFuncionario *funcionario);

/**
 * @brief Obtém o ID (identificador) do funcionário;
 * 
 * @param Funcionario Ponteiro para a estrutura do tipo "tFuncionario" que terá o ID obtido
 */
int GetIdFuncionario(tFuncionario *Funcionario);

/**
 * @brief Imprime todos os dados de um funcionário;
 * 
 * @param funcionario Ponteiro para uma estrutura do tipo "tFuncionario" que terá seus dados impressos;
 */
void ImprimeFuncionario(tFuncionario *funcionario);

/**
 * @brief Apaga (libera a memória alocada dinâmicamente do) funcionário;
 * 
 * @param funcionario Ponteiro para a estrutura do tipo "tFuncionario" que será apagada (liberada);
 */
void ApagaFuncionario(tFuncionario *funcionario);

#endif