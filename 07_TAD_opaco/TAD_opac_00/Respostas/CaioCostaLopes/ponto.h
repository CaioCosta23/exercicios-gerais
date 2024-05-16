#ifndef _PONTO
#define _PONTO

/**
 * @brief Tipo Abstrato de Dados (TAD) - Opaco: "ponto" ("tPonto");
 * 
 * Dados Originais: Ponto(x, y);
 */
typedef struct ponto *tPonto;

/**
 * @brief cria uma variável do tipo "tPonto" (alocada dinâmicamente);
 * 
 * @param x Valor da coordenada X do ponto;
 * @param y Valor da coordenada Y do ponto;
 * @return tPonto Variável do tipo "tPonto" com seus atributos inicializados (e a memória alocada dinamicamente);
 */
tPonto Pto_Cria(float x, float y);

/**
 * @brief Acessa a coordenada X do ponto;
 * 
 * @param p Estrutura do tipo "tPonto" que terá a coordenada X obtida;
 * @return float Valor da coordenada X;
 */
float Pto_Acessa_x(tPonto p);

/**
 * @brief Acessa a coordenada Y do ponto;
 * 
 * @param p Estrutura do tipo "tPonto" que terá a coordenada Y obtida;
 * @return float Valor da coordenada Y;
 */
float Pto_Acessa_y(tPonto p);

/**
 * @brief Atribui a coordenada atribui um valor a coordenada X do ponto;
 * 
 * @param p Estrutrutura do tipo "tPonto" que terá um valor atrribuido a sua coordenada X;
 * @param x Valor que será atribuido a coordenada X do ponto;
 */
void Pto_Atribui_x(tPonto p, float x);

/**
 * @brief Atribui a coordenada atribui um valor a coordenada Y do ponto;
 * 
 * @param p Estrutrutura do tipo "tPonto" que terá um valor atrribuido a sua coordenada Y;
 * @param y Valor que será atribuido a coordenada Y do ponto;
 */
void Pto_Atribui_y(tPonto p, float y);

/**
 * @brief Calcula a distância entre dois pontos;
 * 
 * @param p1 Estrutura do tipo "tPonto" do primeiro ponto;
 * @param p2 Estrutura do tipo "tPonto" do segundo ponto;
 * @return float Valor da distância (Euclidiana) calculada entre o ponto 1 (p1) e o ponto 2 (p2);
 */
float Pto_Distancia(tPonto p1, tPonto p2);

/**
 * @brief Apaga (desaloca a memória dinamicamente) a estrutura do tipo "tPonto";
 * 
 * @param p Estrutura do tipo "tPonto" que será apagada;
 */
void Pto_Apaga(tPonto p);

#endif