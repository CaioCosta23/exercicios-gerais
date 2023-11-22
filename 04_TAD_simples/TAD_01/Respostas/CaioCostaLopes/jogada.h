#ifndef _JOGADA_H
#define _JOGADA_H

typedef struct jogada {
    int x;
    int y;
    int sucesso;
}tJogada;

/**
 * @brief Lê uma jogada e retorna uma estrutura do tipo "tJogada" e define o valor da variável com sucesso; 
 * 
 * Se a jogada foi lida com sucesso, ou seja, foi lido um valor para x e outro para y, então, sucesso = 1, caso contrário, sucesso = 0;
 * @return Jogada lida;
 */
tJogada LeJogada();

/**
 * @brief Retorna a coordenada X da jogada;
 * 
 * @param jogada Jogada realizada;
 * @return int Coordenada X da jogada;
 */
int ObtemJogadaX(tJogada jogada);

/**
 * @brief Retorna a coordenada Y da jogada;
 * 
 * @param jogada Jogada realizada;
 * @return int Coordenada Y da Jogada;
 */
int ObtemJogadaY(tJogada jogada);

/**
 * @brief  Retorna um valor inteiro representando se a jogada foi bem sucedida ou não;
 * 
 * @param jogada Jogada Realizada;
 * @return int 1 se a jogada foi bem sucedida e 0, caso contrário;
 */
int FoiJogadaBemSucessedida(tJogada, jogada);

#endif