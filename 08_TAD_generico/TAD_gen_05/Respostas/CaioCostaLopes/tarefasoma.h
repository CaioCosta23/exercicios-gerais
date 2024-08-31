#ifndef _tarefasoma
#define _tarefasoma

typedef struct soma tSoma;

/**
 * @brief Cria (aloca a memória dinâmicamente de) uma tarefa de soma;
 * 
 * @param n1 - Primeiro número que será somado;
 * @param n2 - Segundo número que será somado;
 *
 * @return Ponteiro para a estrutura do tipo "tSoma" que contém os campos de dados inicializados da tarefa de multiplicação;
 */
tSoma* CriaTarefaSoma(float n1, float n2);

/**
 * @brief Executa uma tarefa de soma;
 *
 * @param sum Ponteiro para a estrutura do tipo "tSoma" que contém os dados da tarefa de soma atualizados;
 */
void ExecutaTarefaSoma(void *sum);

/**
 * @brief Destrói (desaloca a memória dinamicamente) uma tarefa de soma;
 *
 * @param sum Ponteiro para a estrutura do tipo "tSoma" que contém os dados da tarefa de soma a ser destruída;
 */
void DestroiTarefaSoma(void *sum);

#endif