#ifndef _defesa
#define _defesa

#define QUADRADO 'Q' //Caractere que indica uma defesa do tipo quadrado;
#define CIRCULO 'C' // Caractere que indica uma defesa do tipo círculo;
#define MAX_TAM 100 // Tamanho máximo do nome da defesa;

// A estrutura tDefesa contém o tipo da defesa, as coordenadas do centro, o tamanho e o poder de defesa.
typedef struct defesa *tDefesa;

/**
 * @brief Lê os dados (e cria alocando a memória dinâmicamente para uma estrutura do tipo ponteiro de "tDefesa") de uma defesa de uma cidade;
 * 
 * @return tDefesa Estrutura (do tipo ponteiro) "tDefesa" que contém os dados inicializados da defesa;
 */
tDefesa LeDefesa();

/**
 * @brief Verifica se um ponto está dentro da área de defesa;
 * 
 * @param defesa Estrutura (do tipo ponteiro) "tDefesa" que contém os dados atualizados da defesa;
 * @param x Coordenada x do ponto;
 * @param y Coordenada y do ponto;
 * @return int 1 se o ponto está dentro da área de defesa, 0 caso contrário.
 */
int VerificaSeDentroArea(tDefesa defesa, float x, float y);

/**
 * @brief Registra o uso da defesa (e, consequentemente, diminui o poder de defesa);
 * 
 * @param defesa Estrutura (do tipo ponteiro) "tDefesa" que contém os dados atualizados da defesa;
 */
void UsaDefesa(tDefesa defesa);

/**
 * @brief Obtém o (nível de) poder da defesa;
 * 
 * @param defesa Estrutura (do tipo ponteiro) "tDefesa" que contém os dados atualizados da defesa;
 * @return float (Nível de) Poder de defesa da defesa;
 */
float GetDefesaPoder(tDefesa defesa);

/**
 * @brief Verifica se a defesa pode defender o ataque;
 * 
 * @param defesa Estrutura (do tipo ponteiro) "tDefesa" que contém os dados atualizados da defesa;
 * @return int 1 se a defesa pode defender, 0 caso contrário.
 */
int PodeDefender(tDefesa defesa);

/**
 * @brief Imprime as informações de uma defesa de uma cidade;
 * 
 * @param defesa Estrutura (do tipo ponteiro) "tDefesa" que contém os dados atualizados da defesa;
 */
void ImprimeDefesa(tDefesa defesa);

/**
 * @brief Libera (desaloca a memória dinamicamente a) defesa.
 * 
 * @param defesa Estrutura (do tipo ponteiro) "tDefesa" que contém os dados atualizados da defesa;
 */
void LiberaDefesa(tDefesa defesa);

#endif