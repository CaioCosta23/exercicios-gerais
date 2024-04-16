#ifndef _PONTO
#define _PONTO

struct ponto {
	float x;
	float y;
};
typedef struct ponto Ponto;

/**
 * @brief Cria o ponto;
 * 
 * @param x Coordenada X;
 * @param y Coordenada Y;
 * @return Ponto coordenadas (X, Y);
 */
Ponto pto_cria (float x, float y);

/**
 * @brief Obtém a coordenada X do ponto;
 * 
 * @param p Estrutura do tipo Ponto;
 * @return float valor da coordenada X;
 */
float pto_acessa_x (Ponto p);

/**
 * @brief Obtém a coordenada Y do ponto;
 * 
 * @param p Estrutura do tipo ponto;
 * @return float Valor da coordenada Y di ponto;
 */
float pto_acessa_y (Ponto p);

/**
 * @brief Atribui um valor a coordenada X do ponto;
 * 
 * @param p Estrutura do tipo Ponto;
 * @param x Coordenada X;
 * @return Ponto Estrutura do tipo ponto com o valor da coordenada X atribuida;
 */
Ponto pto_atribui_x (Ponto p, float x);

/**
 * @brief Atribui um valor a coordenada Y do ponto;
 * 
 * @param p Estrutura do tipo Ponto;
 * @param y Coordenada Y;
 * @return Ponto Estrutura do tipo ponto com o valor da coordenada y atribuida; 
 */
Ponto pto_atribui_y (Ponto p, float y);

/**
 * @brief Calcula a distância entre dois pontos;
 * 
 * @param p1 Primeiro ponto;
 * @param p2 Segundo ponto;
 * @return float Valor da distância entre dois pontos;
 */
float pto_distancia (Ponto p1, Ponto p2);

#endif