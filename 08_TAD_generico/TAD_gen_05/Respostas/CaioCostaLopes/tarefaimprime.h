#ifndef _tarefaimprime
#define _tarefaimprime

typedef struct impr tImpr;

/**
 * @brief Cria (aloca a memória dinâmicamente de) uma tarefa a ser impressa na tela;
 * 
 * @param msg Mensagem que deve ser impressa em tela;
 *
 * @return Ponteiro para a estrutura do tipo "tImpr" que contém os campos de dados inicializados da tarefa de impressão;
 */
tImpr* CriaTarefaImprimir(char *msg);

/**
 * @brief Executa uma tarefa de impressão na tela;
 *
 * @param imp Ponteiro para a estrutura do tipo "tImpr" que contém os dados da tarefa de impressão atualizados;
 */
void ExecutaTarefaImprimir(void *imp);

/**
 * @brief Destrói (desaloca a memória dinamicamente) uma tarefa de impressão em tela;
 *
 * @param imp - Ponteiro para a estrutura do tipo "tImpr" que contém os dados da tarefa de impressão a ser destruída;
 */
void DestroiTarefaImprimir(void *imp);

#endif