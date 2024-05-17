#ifndef _JOGADA_H
#define _JOGADA_H

typedef struct Jogada tJogada;

/**
 * @brief Cria (aloca a memória dinamicamente) uma jogada;
 * 
 * @return tJogada* Ponteiro para a estrutura do tipo "tJogada" inicializada;
 */
tJogada *CriaJogada();

/**
 * @brief Lê uma jogada e armazena em uma estrutura do tipo "tJogada";
 * 
 * @param jogada Ponteiro para a estrutura do tipo "tJogada" a ser preenchida;
 */
void LeJogada(tJogada *jogada);

/**
 * @brief Obtém a coordenada X da jogada;
 * 
 * @param jogada Ponteiro para a estrutura do tipo "tJogada" que terá a jogada obtida;
 * @return int Coordenada X da jogada;
 */
int ObtemJogadaX(tJogada *jogada);

/**
 * @brief Obtém a coordenada Y da jogada;
 * 
 * @param jogada Ponteiro para a estrutura do tipo "tJogada" que terá uma jogada obtida;
 * @return int Coordenada Y da jogada;
 */
int ObtemJogadaY(tJogada *jogada);

/**
 * @brief Verifica se a jogada foi bem sucedida;
 * 
 * @param jogada Ponteiro para a estrutura do tipo "tJogada" que será verificada;
 * @return int 1 se a jogada for bem sucedida, caso contrário;
 */
int FoiJogadaBemSucedida(tJogada *jogada);

/**
 * @brief Destrói (desaloca memória dinamicamente) uma jogada;
 * 
 * @param jogada Ponteiro para a estrutura do tipo "tJogada" que será destruída (desalocada);
 */
void DestroiJogada(tJogada *jogada);

#endif