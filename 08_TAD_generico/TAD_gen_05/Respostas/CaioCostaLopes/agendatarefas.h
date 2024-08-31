#ifndef _agendatarefas
#define _agendatarefas

typedef struct agendatarefas tAgendaTarefas;

/**
 * @brief Cria (aloca a memória dinamicamente para) uma agenda de tarefas;
 *
 * @param numElem A quantidade de elementos (tarefas) que serão armazenadas na agenda de tarefas;
 *
 * @return Ponteiro para a estrutura do tipo "tAgendaTarefas" que contém os campos de dados da agenda de tarefas inicializados;
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem);

/**
 * @brief Cadastra uma tarefa na agenda de tarefas;
 *
 * @param tar - Ponteiro para a estrutura do tipo "tAgenda" que contém os dados atualizados da agenda de tarefas;
 * @param prioridade - Prioridade de execução da nova tarefa que será cadastrada;
 * @param tarefa - Ponteiro para a estrutura do tipo "void" (vazio) que receberá uma tarefa (de qualquer tipo);
 * @param executa - Ponteiro para função ("callback") de executar tarefa;
 * @param destroi - Ponteiro para função ("callback") para destruir a tarefa;
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) );   

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas;
 *
 * @param tar Ponteiro para a estrutura do tipo "tAgenda" que contém os dados atualizados da agenda de tarefas;
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar);

/**
 * @brief Destroi (desaloca a memória dinamicamente de) uma agenda de tarefas;
 *
 * @param tar Ponteiro para a estrutura do tipo "tAgenda" que contém os dados atualizados da agenda de tarefas que será destruída;
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar);

#endif
