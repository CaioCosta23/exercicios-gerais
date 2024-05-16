#ifndef _CIRCULO
#define _CIRCULO

#include "ponto.h"

/**
 * @brief Tipo Abstrato de Dados (TAD) - Opaco: circulo ("tCirculo");
 * 
 * Dados Originais: centro, raio;
 */
typedef struct circulo *tCirculo;

/**
 * @brief Cria (e aloca dinamicamente a memória de) um circulo com centro nas coordenadas (x, y) e raio 'r';
 * 
 * @param x Coordenada X do centro do circulo;
 * @param y Coordenada Y do centro do circulo;
 * @param r Raio do circulo;
 * @return tCirculo Ponteiro para a estrutura do tipo "tCirculo" com os dados inicializados (e a memória alocada dinamicamente)
 */
tCirculo Circulo_Cria(float x, float y, float r);

/**
 * @brief Acessa o ponto que representa o centro do círculo;
 * 
 * @param c Estrutura do tipo "tCirculo" que terá o ponto de seu centro acessado;
 * @return tPonto Estrutura do tipo "tPonto" que será acessada dentro do círculo;
 */
tPonto Circulo_Acessa_Centro (tCirculo c);

/**
 * @brief Acessa o raio do círculo;
 * 
 * @param c Estrutura do tipo "tCirculo" que terá o valor de seu raio acessado
 * @return float Raio do círculo;
 */
float Circulo_Acessa_Raio(tCirculo c);

/**
 * @brief Atribui um ponto ao centro do círculo;
 * 
 * @param c Estrutura do tipo "tCirculo" que terá um ponto atribuído ao seu centro;
 * @param p Estrutura do tpo "tPonto" que será atribuída ao centro do círculo;
 */
void Circulo_Atribui_Centro(tCirculo c, tPonto p);

/**
 * @brief Atribui um valor ao raio do círculo;
 * 
 * @param c Estrutura do tipo "tCirculo" que terá um valor atribuído ao seu raio;
 * @param r Valor que será atribuido ao raio do círculo;
 */
void Circulo_Atribui_Raio(tCirculo c, float r);

/**
 * @brief Indica se um determinado ponto está dentro do círculo;
 * 
 * @param c Estrutura do tipo "tCirculo" que será utilizada como base de verificação; 
 * @param p Estrutura do tipo "tPonto" que será verificado (se está ou não dentro do círculo);
 * @return int 1 se o ponto estiver dentro do circulo, 0 caso contrário;
 */
int Circulo_Interior (tCirculo c, tPonto p);

/**
 * @brief Apaga (libera a memória alocada dinamicamente de) um círculo; 
 * 
 * @param c Estrutura do tipo "tCirculo" que será apagada (e terá sua memória desalocada dinamicamente); 
 */
void Circulo_Apaga(tCirculo c);


#endif