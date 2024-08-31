#ifndef _tarefamultiplica
#define _tarefamultiplica

typedef struct mult tMult;

/**
 * @brief Cria (aloca a memória dinâmicamente de) uma tarefa de multiplicação;
 * 
 * @param n1 - Primeiro número que será multiplicado;
 * @param n2 - Segundo número que será multiplicado;
 *
 * @return Ponteiro para a estrutura do tipo "tImpr" que contém os campos de dados inicializados da tarefa de multiplicação;
 */
tMult* CriaTarefaMultiplicar(float n1, float n2);

/**
 * @brief Executa uma tarefa de multiplicação;
 *
 * @param mult - Ponteiro para a estrutura do tipo "tImpr" que contém os dados da tarefa de multiplicação atualizados;
 */
void ExecutaTarefaMultiplicar(void *mult);

/**
 * @brief Destrói (desaloca a memória dinamicamente) uma tarefa de multiplicação;
 *
 * @param mult Ponteiro para a estrutura do tipo "tImpr" que contém os dados da tarefa de impressão a ser destruída;
 */
void DestroiTarefaMultiplicar(void *mult);

#endif