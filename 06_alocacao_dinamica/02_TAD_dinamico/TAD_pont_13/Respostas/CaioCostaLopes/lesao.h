#ifndef _lesao
#define _lesao

#define TAM_ID 10 // Quantidade de caracteres máxima reservada para armazenar o ID (identificador) da lesão;
#define TAM_DIAG 100 // Quantidade de caracteres reservado para o armazenamento do nome do diagnostico do paciente;
#define TAM_REG 100 // Quqnatidade máxima de caracteres reservada para armazenar o nome da região da lesão;

typedef struct lesao {
    char *id;
    char *diagnostico;
    char *regiao_corpo;
    int chance_malignidade;
}tLesao;

/**
 * @brief Cria uma estrutura do tipo "tLesao" que será responsável por armazenar dados e informações da lesão;
 * 
 * @return tLesao* Ponteiro para a estrutura do tipo "tLesão" com seus parâmetros inicializados;
 */
tLesao *CriaLesao();

/**
 * @brief Lê as informações de uma lesão da entrada padrão;
 * 
 * @param l Ponteiro para uma estrutura do tipo "tLesao" que terá os dados coletados da entrada padrão e armazenados;
 */
void LeLesao(tLesao *l);

/**
 * @brief Obtém o ponteiro para o ID (identificador) da lesão;
 * 
 * @param l Ponteiro para a estrutura do tipo "tLesao" que terá o seu ID (identificador) obtido;
 * @return char Ponteiropara o ID (identificador) da lesão;
 */
char *GetIdLesao(tLesao *l);

/**
 * @brief Verifica se a lesão precisa de cirurgia;
 * 
 * @param l Ponteiro para a estrutura do tipo "tLesao" que será verificada;
 * @return int 1 se a lesão precisará de cirurgia, 0 caso contrário;
 */
int PrecisaCirurgiaLesao(tLesao *l);

/**
 * @brief Apaga (libera a memória alocada dinamicamente da) lesão;
 * 
 * @param l Ponteiro para a estrutura do tipo "tLesao" que será (liberada dinamicamente) apagada;
 */
void LiberaLesao(tLesao *l);

#endif