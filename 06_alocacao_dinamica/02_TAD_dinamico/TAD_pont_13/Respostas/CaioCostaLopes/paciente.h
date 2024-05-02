#ifndef _paciente
#define _paciente

#include "data.h"
#include "lesao.h"

#define TAM_NOME 100 // Quantidade de caracteres utilizada para armazenar o nome do paciente;
#define TAM_CSUS 19 // Quantidade de caracteres que será disponibilizada para armazenar o cartão do SUS de um paciente;
#define QTD_LESAO 10 // Quantidade máxima de lesões que podem ser registradas de um paciente;

typedef struct paciente {
    char *nome;
    tData *nascimento;
    char *cartaoSus;
    char genero;
    tLesao **listaLesao;
    int qtdLesoes;
    int maxLesoes;
}tPaciente;

/**
 * @brief Cria uma estrutura do tipo "tPaciente" (com a memória alocada dinamicamente) que armazenará os dados e informações do paciente;
 * 
 * @return tPaciente* Ponteiro para uma estrutura do tipo "tPaciente" (com a memória alocada dinamicamente) com os dados do paciente inicializados;
 */
tPaciente *CriaPaciente();

/**
 * @brief Lê as informações de um paciente da entrada padrão;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPaciente" em que serão armazenadas as informações do paciente lido;
 */
void LePaciente(tPaciente *p);

/**
 * @brief Adiciona uma lesão à lista de lesões do paciente;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPaciente" que terá uma lesão atribuida;
 * @param l Ponteiro para a estrutura do tipo "tLesao" que contém os dados da lesão que será atribuída ao paciente;
 */
void AdicionaLesaoPaciente(tPaciente *p, tLesao *l);

/**
 * @brief Retorna o número do cartão do SUS de um paciente;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPaciente" que terá o número do cartão do SUS obtido;
 * @return char* Ponteiro para o número do cartão do SUS (que está armazendado no formato caractere);
 */
char *GetCartaoSusPaciente(tPaciente *p);

/**
 * @brief Retorna a quantidade de lesões do paciente;
 * 
 * @param p Ponteiro pata a estrutura do tipo "tPaciente" contendo as informações do paciente;
 * @return int Quantidade de lesões que o paciente possui;
 */
int GetQtdLesoesPaciente(tPaciente *p);

/**
 * @brief Retorna a quantidade de cirurgias necessárias para tratar as lesões do paciente;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPaciente" que contém as informações e dados do paciente;
 * @return int 
 */
int GetQtdCirurgiasPaciente(tPaciente *p);

/**
 * @brief Retorna a data de nascimento do paciente;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPaciente" que contém os dados e informações;
 * @return tData* Data de nascimento do paciente;
 */
tData *GetNascimentoPaciente(tPaciente *p);

/**
 * @brief Imprime as informações de um paciente na saída padrão;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPaciente" com as informações do paciente  que será impresso;
 */
void ImprimePaciente(tPaciente *p);

/**
 * @brief Apaga (libera a memória alocada dinamicamente de) um paciente;
 * 
 * @param p 
 */
void LiberaPaciente(tPaciente *p);

#endif