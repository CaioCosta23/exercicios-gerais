#ifndef _partida
#define _partida

typedef struct partida *tPartida;

#define TIME_CASA 1
#define TIME_FORA 2

/**
 * @brief Cria (aloca a memória dinamicamente) e lê uma partida;
 * 
 * @return tPartida Estrutura (do tipo ponteiro) do tipo "tPartida" que contém os campos de dados da partida;
 */
tPartida LePartida();

/**
 * @brief Obtém o nome do time 1 da partida;
 * 
 * @param p Estrutura (do tipo ponteiro) do tipo "tPartida" que contém os dados da partida;
 * @return char* Ponteiro para o nome do time 1 da partida;
 */
char *GetTime1Partida(tPartida p);

/**
 * @brief Obtém o nome do time 2 da partida;
 * 
 * @param p Estrutura (do tipo ponteiro) do tipo "tPartida" que contém os dados da partida;
 * @return char* Ponteiro para o nome do time 2 da partida;
 */
char *GetTime2Partida(tPartida p);

/**
 * @brief Obtém o vencedor da partida;
 * 
 * @param p Estrutura (do tipo ponteiro) do tipo "tPartida" que contém os dados da partida;
 * @return int ID (constante) que representa o time que venceu a partida;
 */
int GetVencedorPartida(tPartida p);

/**
 * @brief Imprime os dados da partida;
 * 
 * @param p Estrutura (do tipo ponteiro) do tipo "tPartida" que contém os dados da partida;
 */
void ImprimePartida(tPartida p);

/**
 * @brief Libera (a memória alocada dinamicamente da) partida;
 * 
 * @param p Estrutura (do tipo ponteiro) do tipo "tPartida" que contém os dados da partida;
 */
void LiberaPartida(tPartida p);

#endif