#ifndef _JOGADA_H
#define _JOGADA_H

typedef struct {
    int x;
    int y;
    int sucesso;
}tJogada;

/**
 * @brief Aloca e retirna uma estrutura do tipo "tJogada".
 * Se a alocação falhar, oprograma é encerrado;
 * 
 * @return tJogada* Estrutura do tipo "tJogada" alocada;
 */
tJogada *CriaJogada();

/**
 * @brief Libera memória de uma estruura do tipo "tJogada";
 * 
 * @param jogada Estrutura do tipo "tJogada" a ser liberada;
 */
void DestroiJogada(tJogada *jogada);

/**
 * @brief Lê uma jogadae armazena em uma estrutura do tipo "tJogada";
 * 
 * @param jogada Estrutura do tipo "tJogada" a ser preenchida;
 */
void LeJogada(tJogada *jogada);

/**
 * @brief Obtém a coordenada X da jogada;
 * 
 * @param jogada Estrutura do tipo "tJogada";
 * @return int Coordenada X;
 */
int ObtemJogadaX(tJogada *jogada);

/**
 * @brief Obtém a coordenada Y;
 * 
 * @param jogada Estrutura do tipo "tJogada";
 * @return int Coordenada Y;
 */
int ObtemJogadaY(tJogada *jogada);

/**
 * @brief Verifica se a jogada foi bem sucedida;
 * 
 * @param jogada Estrutura do tipo "tJogada";
 * @return int 1 se a jogada foi bem sucedida, 0 caso contrário;
 */
int FoiJogadaBemSucedida(tJogada *jogada);

#endif