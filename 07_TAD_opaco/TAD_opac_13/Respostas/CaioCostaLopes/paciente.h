#ifndef _paciente
#define _paciente

#include "data.h"
#include "lesao.h"

#define TAM_NOME 100 // Quantidade máxima de caracteres do nome de um paciente;
#define TAM_CSUS 19 // Quantidade máxima de caracteres do cartão do SUS do paciente;
#define QTD_LESAO 10 // Quantidade máxima de lesões que um paciente pode ter;

typedef struct paciente tPaciente;

/**
 * @brief Cria (aloca a memória dinamicamente de) um paciente;
 * 
 * @return tPaciente* Ponteiro para a estrutura do tipo "tPaciente" que contém os campos de dados (informações) do paciente (inicializados);
 */
tPaciente *CriaPaciente();

/**
 * @brief Lê os dados de um paciente (da entrada padrão);
 * 
 * @param p Ponteiro para a estrutura do tipo "tPaciente" que contém os campos de dados do paciente que serão preenchidos;
 */
void LePaciente(tPaciente *p);

/**
 * @brief Obtém o cartão do sus de um paciente;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPaciente" que contém os dados do paciente
 * @return char* Ponteiro para o vetor de caracteres (cartão do SUS);
 */
char *GetCartaoSusPaciente(tPaciente *p);

/**
 * @brief Obtém a quantidade de lesões que o paciente possui (atualmente);
 * 
 * @param p Ponteiro para a estrutura do tipo "tPaciente" que contém os dados do paciente;
 * @return int Quantidade atual de lesões que o paciente possui;
 */
int GetQtdLesoesPaciente(tPaciente *p);

/**
 * @brief Obtém a quantidade de cirurgias qe o paciente precisará realizar;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPaciente" que contém os dados do paciente;
 * @return int Quantidade de cirurgias pelo qual o paciente terá que se submeter;
 */
int GetQtdCirurgiasPaciente(tPaciente *p);

/**
 * @brief Obtém a data de naciemento do paciente;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPaciente" que possui os dados do paciente;
 * @return tData* Ponteiro para a estrutura do tipo "tData" que contém os dados da data (de nascmento neste caso) do paciente;
 */
tData *GetNascimentoPaciente(tPaciente *p);

/**
 * @brief Adiciona uma lesão a lista de lesões do paciente;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPaciente" que contém os dados de um paciente;
 */
void AdicionaLesaoPaciente(tPaciente *p);

/**
 * @brief Imprime os dados de um paciente;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPaciente" que possui os dados de um paciente;
 */
void ImprimePaciente(tPaciente *p);

/**
 * @brief Libera (a memória alocada dinamicamente de) um paciente;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPaciente";
 */
void LiberaPaciente(tPaciente *p);

#endif