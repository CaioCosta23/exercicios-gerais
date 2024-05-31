#ifndef _partida
#define _partida

typedef struct partida *tPartida;
struct partida {
    char *time1;
    char *time2;
    int pontos1;
    int pontos2;
};

#define TIME_CASA 1;
#define TIME_FORA 2;

/**
 * @brief Cria (aloca a memória dinamicamente) e lê os dados de uma partida;
 * 
 * @return tPartida Estrutura (do tipo ponteiro) do tipo "tPartida" com os seus campos preenchidos à partir da leitura dos dados;
 */
tPartida LePartida();

/**
 * @brief Obtém o nome do primeiro time da partida (time da casa);
 * 
 * @param p Estrutura (do tipo ponteiro) do tipo "tPartida" que contém o nome da primeira equipe (equipe da casa) que disputou a partida; 
 * @return char* Nome da equipe 1 (time da casa) que disputou a partida;
 */
char *GetTime1Partida(tPartida *p);

/**
 * @brief Obtém o nome do segundo time da partida (time de fora);
 * 
 * @param p Estrutura (do tipo ponteiro) do tipo "tPartida" que contém o nome da segunda equipe (equipe de fora) que disputou a partida; 
 * @return char* Nome da equipe 2 (time de fora) que disputou a partida;
 */
char *GetTime2Partida(tPartida *p);

/**
 * @brief Obtém o número (constante) que representa a equipe vencedora da partida;
 * 
 * @param p Estrutura (do tipo ponteiro) do tipo "tPartida" que contém os dados da partida, que ajudarão a identificar qual time foi o vencedor;
 * @return int Número (constante) que representa a equipe vencedora da partida;
 */
int GetVencedorPartida(tPartida p);

/**
 * @brief Imprime as informações de uma partida;
 * 
 * @param p Estrutura (do tipo ponteiro) do tipo "tPartida" que terá suas informações impressas;
 */
void ImprimePartida(tPartida p);

/**
 * @brief Libera (a memória alocada dinamicamente de) uma partida;
 * 
 * @param p Estrutura (do tipo ponteiro) do tipo "tPartida" que será liberada;
 */
void LiberaPartida(tPartida *p);

#endif