#ifndef _franquia
#define _franquia

typedef struct franquia *tFranquia;

#define MAX_NOME 32

/**
 * @brief Cria (aloca a memória dinamicamente) e lê os dados de uma franquia;
 * 
 * @return tFranquia Estrutura (do tipo ponteiro) do tipo "tFranquia" que contém os campos de dados da franquia;
 */
tFranquia LeFranquia();

/**
 * @brief Obtém o nome da franquia;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que contém os dados da franquia;
 * @return char* Ponteiro para o nome da franquia;
 */
char *GetNomeFranquia(tFranquia f);

/**
 * @brief Obtém o nome da conferência da franquia;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que contém os dados da franquia;
 * @return char* Ponteiro para o nome da conferência da franquia;
 */
char *GetNomeConferencia(tFranquia f);

/**
 * @brief Adiciona nos registros uma vitória em casa para franquia;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que contém os dados da franquia;
 */
void AdicionaVitoriaCasaFranquia(tFranquia f);

/**
 * @brief Adiciona nos registros uma vitória fora casa para franquia;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que contém os dados da franquia;
 */
void AdicionaVitoriaForaFranquia(tFranquia f);

/**
 * @brief Adiciona nos registros uma derrota em casa para franquia;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que contém os dados da franquia;
 */
void AdicionaDerrotaCasaFranquia(tFranquia f);

/**
 * @brief Adiciona nos registros uma derrota fora casa para franquia;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que contém os dados da franquia;
 */
void AdicionaDerrotaForaFranquia(tFranquia f);

/**
 * @brief Obtém o número de vitórias de uma franquia em casa;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que contém os dados da franquia;
 * @return int Número de vitórias em casa da franquia;
 */
int GetVitoriaCasaFranquia(tFranquia f);

/**
 * @brief Obtém o número de vitória de uma franquia fora casa;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que contém os dados da franquia;
 * @return int Número de vitórias fora de casa da franquia;
 */
int GetVitoriaForaFranquia(tFranquia f);

/**
 * @brief Obtém o número de derrotas de uma franquia em casa;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que contém os dados da franquia;
 * @return int Número de derrotas em casa da franquia;
 */
int GetDerrotaCasaFranquia(tFranquia f);

/**
 * @brief Obtém o número de derrotas de uma franquia fora de casa;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que contém os dados da franquia;
 * @return int Número de derrotas fora de casa da franquia;
 */
int GetDerrotaForaaFranquia(tFranquia f);

/**
 * @brief Imprime as informações de uma franquia;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que contém os dados da franquia;
 */
void ImprimeFranquia(tFranquia f);

/**
 * @brief Libera (a memória alocada dinâmicamente de) uma franquia;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que contém os dados da franquia;
 */
void LiberaFranquia(tFranquia f);

#endif