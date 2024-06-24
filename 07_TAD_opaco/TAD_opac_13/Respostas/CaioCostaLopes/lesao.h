#ifndef _lesao
#define _lesao

#define TAM_ID 10 // Quantidade máxima de caracteres do identificador da lesão;
#define TAM_DIAG 100 // Quantidade máxima de caracteres do diagnóstico da lesão;
#define TAM_REG 100 // Quantidade máxima de caracteres do nome da região da lesão;

typedef struct lesao tLesao;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma lesão;
 * 
 * @return tLesao* Ponteiro para a estrutura do tipo "tLesao" que contém os campos de dados (inicializados) da lesão;
 */
tLesao *CriaLesao();

/**
 * @brief Lê (da entrada padrão) as informações sobre uma lesão;
 * 
 * @param l Ponteiro para a estrutura do tipo "tLesao" que contém os campos de dados das informações que serão lidas sobre a lesão;
 */
void LeLesao(tLesao *l);

/**
 * @brief Obtém o ID (Identificador da lesão);
 * 
 * @param l Ponteiro para a estrutura do tipo "tLesao" que contém os dados da lesão;
 * @return char* Ponteiro para o vetor de caracteres que contém os dados da lesão;
 */
char *GetIdLesao(tLesao *l);

/**
 * @brief Verifica se a lesão precisa de cirurgia;
 * 
 * @param l Ponteiro para a estrutura do tipo "tLesao" que contém os dados da lesão;
 * @return int 1 se a lesão precisar de cirurgia e 0 caso contrário;
 */
int PrecisaCirurgiaLesao(tLesao *l);

/**
 * @brief Libera (a memória alocada dinamicamente de) uma lesão;
 * 
 * @param l Ponteiro para a estrutura do tipo "tLesao";
 */
void LiberaLesao(tLesao *l);

#endif