#ifndef __gerpacotes
#define __gerpacotes

#include "pacote.h"

typedef struct gereciadorpacotes tGerenciador;

/**
 * @brief Cria (aloca a memória dinamicamente de) um gerenciador de pacotes;
 * 
 * @return tGerenciador* Ponteiro para a estrutura do tipo "tGerenciador" que contém os campos de dados do gerenciador inicializados;
 */
tGerenciador *CriaGerenciador();

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes;
 * 
 * @param geren Ponteiro para a estrutura do tipo "tGerenciador" que contém os dados atualizados do gerenciador; 
 * @param pac Ponteiro para a estrutura do tipo "tPacote" que contém os dados atualizados de um pacote;
 */
void AdicionaPacoteNoGerenciador(tGerenciador *geren, tPacote *pac);

/**
 * @brief Imprime um pacote específico do gerenciador (que está na posição de índice - passado como parâmetro - no vetor/lista de pacotes);
 * 
 * @param gen Ponteiro para a estrutura do tipo "tGerenciador" que contém os dados atualizados do gerenciador;
 * @param idx Índice da posição nao vetor/lista em que se encotra o pacote que se deseja imprimir;
 */
void ImprimePacoteNoIndice(tGerenciador *geren, int idx);

/**
 * @brief Imprime as informações de todos os pacotes armazenados no gerenciador de pacotes;
 * 
 * @param geren Ponteiro para a estrutura do tipo "tGerenciador" que contém os dados atualizados do gerenciador;
 */
void ImprimeTodosPacotes(tPacote *geren);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) um gereciador de pacotes;
 * 
 * @param geren Ponteiro para a estrutura do tipo "tGerenciador" que contém os dados atualizados do gerenciador;
 */
void DestroiGerenciador(tGerenciador *geren);

#endif