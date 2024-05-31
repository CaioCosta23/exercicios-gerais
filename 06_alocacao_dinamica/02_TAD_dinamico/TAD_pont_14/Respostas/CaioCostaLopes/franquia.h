#ifndef _franquia
#define _franquia

typedef struct franquia *tFranquia;
struct franquia {
    char *nome;
    char *conferencia;
    int vit_casa;
    int vit_fora;
    int der_casa;
    int der_fora;
    float aproveitamento;
};

#define MAX_NOME 32 // Tamanho (quantidae de caracteres) máximo do nome de uma franquia;

/**
 * @brief Cria (aloca a memória dinamicamente) e lê os dados de uma franquia;
 * 
 * @return tFranquia Estrutura (do tipo ponteiro) do tipo "tFranquia" que serpa criada e terá os dados lidos e armazenados em seus campos;
 */
tFranquia LeFranquia();

/**
 * @brief Obtém o nome de um franquia;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que contém o nome da franquia;
 * @return char* Ponteiro para o nome da franquia;
 */
char *GetNomeFranquia(tFranquia f);

/**
 * @brief Obtém o nome da confrerência na qual a franquia disputa o campeonato;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que possui o nome da conferência em que a franquia disputa o campeonato;
 * @return char* Ponteiro para a o nome da conferência em que a franquia está localizada;
 */
char *GetConferenciaFranquia(tFranquia f);

/**
 * @brief Adiciona uma vitória em casa para as estatísticas da franquia;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que possui os dados das quantidade de vitórias em casa que a franquia possui;
 */
void AdicionaVitoriaCasaFranquia(tFranquia f);

/**
 * @brief Adiciona uma vitória fora de casa para as estatísticas da franquia;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que possui os dados das quantidade de vitórias fora de casa que a franquia possui;
 */
void AdicionaVitoriaForaFranquia(tFranquia f);

/**
 * @brief Adiciona uma derrota em casa para as estatísticas da franquia;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que possui os dados das quantidade de derrotas em casa que a franquia possui;
 */
void AdicionaDerrotaCasaFranquia(tFranquia f);

/**
 * @brief Adiciona uma derrota fora casa para as estatísticas da franquia;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que possui os dados das quantidade de derrotas fora casa que a franquia possui;
 */
void AdicionaDerrotaForaFranquia(tFranquia f);

/**
 * @brief Obtém a quantidade de vitórias em casa que uma franquia possui (até o momento);
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tPonteiro" que contém a quantidade de vitórias em casa que a franquia possui (até o momento);
 * @return int Quantidade de vitórias em casa que a franquia possui (até o momento);
 */
int GetVitoriaCasaFranquia(tFranquia f);

/**
 * @brief Obtém a quantidade de vitórias fora de casa que uma franquia possui (até o momento);
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tPonteiro" que contém a quantidade de vitórias fora de casa que a franquia possui (até o momento);
 * @return int Quantidade de vitórias fora de casa que a franquia possui (até o momento);
 */
int GetVitoriaForaFranquia(tFranquia f);

/**
 * @brief Obtém a quantidade de derrotas em casa que uma franquia possui (até o momento);
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tPonteiro" que contém a quantidade de derrotas em casa que a franquia possui (até o momento);
 * @return int Quantidade de derrotas em casa que a franquia possui (até o momento);
 */
int GetDerrotaCasaFranquia(tFranquia f);

/**
 * @brief Obtém a quantidade de derrotas de casa que uma franquia possui (até o momento);
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tPonteiro" que contém a quantidade de derrotas de casa que a franquia possui (até o momento);
 * @return int Quantidade de derrotas de casa que a franquia possui (até o momento);
 */
int GetVitoriaCasaFranquia(tFranquia f);

/**
 * @brief Imprime todos os dados de uma franquia;
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que posui todos os dados de um franquia que serão impressos;
 */
void ImprimeFranquia(tFranquia f);

/**
 * @brief Libera (a memória alocada dinamicamente de) uma franquia; 
 * 
 * @param f Estrutura (do tipo ponteiro) do tipo "tFranquia" que será liberada;
 */
void LiberaFranquia(tFranquia f);

#endif