#ifndef _cidade
#define _cidade

#define MAX_NOME 10 // Tamanho máximo do nome da cidade;

#define QTD_DEF 10 // Quantidade máxima de defesas que uma cidade pode ter;
#define QTD_MIS 10 // Quantidade máxima de mísseis que uma cidade pode ter;

#define ENCERRAR 'F' // Caractere que indica o fim da entrada;
#define MISSIL 'M' // Caractere que indica um míssil;
#define DEFESA 'D' // Caractere que indica uma defesa;

// A estrutura tCidade contém o nome da cidade, a quantidade de mísseis e defesas, e as listas de mísseis e defesas;
typedef struct cidade *tCidade;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma cidade;
 * 
 * @return tCidade Ponteiro para a estrutura do tipo "tCidade" que contém os dados inicializados da cidade;
 */
tCidade CriaCidade();

/**
 * @brief Lê os dados de uma cidade;
 * 
 * @param cidade Ponteiro para a estrutura do tipo "tCidade" que contém os dados atualizados de uma cidade;
 * @return tCidade Ponteiro para a estrutura (do tipo ponteiro) "tCidade" com os dados atualizados (e preenchidos) da cidade;
 */
tCidade LeEntrada(tCidade cidade);

/**
 * @brief Processa os dados dos ataques realizados na cidade;
 * 
 * @param cidade Ponteiro para a estrutura (do tipo ponteiro) "tCidade" que contém os dados atualizados de uma cidade;
 */
void ProcessaAtaques(tCidade cidade);

/**
 * @brief Imprime as informações de uma cidade;
 * 
 * @param cidade Ponteiro para a estrutura (do tipo ponteiro) "tCidade" que contém os dados atualizados de uma cidade;
 */
void ImprimeCidade(tCidade cidade);

/**
 * @brief Imprime os dados finais da cidade.
 * 
 * @param cidade Ponteiro para a estrutura (do tipo ponteiro) "tCidade" que contém os dados atualizados de uma cidade;
 */
void ImprimeDados(tCidade cidade);

/**
 * @brief Libera (desaloca a memória dinamicamente de) uma cidade;
 * 
 * @param cidade Ponteiro para a estrutura (do tipo ponteiro) "tCidade" que contém os dados atualizados de uma cidade;
 */
void LiberaCidade(tCidade cidade);

#endif