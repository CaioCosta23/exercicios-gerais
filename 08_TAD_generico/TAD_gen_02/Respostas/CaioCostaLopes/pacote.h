#ifndef __pacote
#define __pacote

typedef enum {
    INT = 1, CHAR = 2
}Type;

typedef struct pacote tPacote;

/**
 * @brief Cria (aloca a memória dinamicamente de) um pacote;
 * 
 * @param Type type Tipo de dado que será armazenado no vetor de informações do pacote;
 * @param numEleme Número de elementos do vetor de informações do pacote;
 * @return tPacote* Ponteiro para a estrutura do tipo "tPacote" que contém os campos de dados do pacote inicializados;
 */
tPacote *CriaPacote(Type type, int numEleme);

/**
 * @brief Lê as infrmações de um pacote;
 * 
 * @param pac Ponteiro para a estrutura do tipo "tPacote" que contém os campos de dados que armazenaram as informações que serão lidas do pacote;
 */
void LePacote(tPacote *pac);

/**
 * @brief Calcula a soma dos valores dos dados de um pacote e armazenando esses dados;
 * 
 * @param pac Ponteiro para a estrutura do tipo "tPacote" com seu dados atualizados;
 */
void CalculaSomaVerificacaoPacote(tPacote *pac);

/**
 * @brief Imprime as informações de um pacote;
 * 
 * @param pac Ponteiro para a estrutura do tipo "tPacote" com seu dados atualizados;
 */
void ImprimePacote(tPacote *pac);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) um pacote;
 * 
 * @param pac Ponteiro para a estrutura do tipo "tPacote" com seu dados atualizados;
 */
void DestroiPacote(tPacote *pac);

#endif