#ifndef _FILME_H
#define _FILME_H

#define MAX_CARACTERES 20

typedef struct Filme tFilme;

/**
 * @brief Cria (aloca a memória dinâmicamente de) um filme; 
 * 
 * @return tFilme* Ponteiro para a estrutura do tipo "tFilme" com seus parâmetros inicializados;
 */
tFilme *CriaFilme();

/**
 * @brief Lê um filme da entrada padrão e define o código do filme;
 * 
 * @param filme Ponteiro para a estrutura do tipo "tFilme" que terá seus dados lidos e armazenados dentro da mesma;
 * @param codigo Código do filme que será lido e armazenado;
 */
void LeFilme(tFilme *filme, int codigo);

/**
 * @brief Obtém o código de um filme;
 * 
 * @param filme Ponteiro para a estrutura do tipo "tFilme" que terá seu código obtido;
 * @return int Código do filme;
 */
int ObterCodigoFilme(tFilme *filme);

/**
 * @brief Obtém o valor do filme;
 * 
 * @param filme Ponteiro para a estrutura do tipo "tFilme" que terá o seu valor (preço) obtido;
 * @return int Valor (preço) do filme;
 */
int ObterValorFilme(tFilme *filme);

/**
 * @brief Obtém a quantidade em estoque do filme;
 * 
 * @param filme ponteiro para a estrutura do tipo "tFilme" que terá sua quantidade em estoque obtida;
 * @return int Quantidade em estoque do filme;
 */
int ObterQtdEstoqueFilme(tFilme *filme);

/**
 * @brief Obtém a quantidade de unidades que foi alugada do filme;
 * 
 * @param filme Ponteiro para a estrutura do tipo "tFilme" que terá a quantidade alugada do filme obtida;
 * @return int Quantidade de unidades que foi alugada do filme;
 */
int ObterQtdAlugadaFilme(tFilme *filme);

/**
 * @brief Verifica se um código passado é igual ao código do filme;
 * 
 * @param filme Ponteiro para a estrutura do tipo "tFilme" que terá seu código comparado;
 * @param codigo Código que será comparado ao código do filme;
 * @return int 1 se os códigos forem iguais, 0 caso contrário;
 */
int EhMesmoCodigoFilme(tFilme *filme, int codigo);

/**
 * @brief Aluga um filme (incrementa a quantidade alugada do filme e consequentemente decrementa sua quantidade em estoque) - caso ainda haja unidades em estoque;
 * 
 * @param filme Ponteiro para a estrutura do tipo "tFilme" que será alugado;
 */
void AlugarFilme (tFilme *filme);

/**
 * @brief Devolve um filme (decrementa a quantidade alugada do filme e consequentemente incrementa sua quantidade em estoque) - caso haja alguma unidade alugada;
 * 
 * @param filme Ponteiro para a estrutura do tipo "tFilme" que será devolvido;
 */
void DevolverFilme(tFilme *filme);

/**
 * @brief Compara os nomes de dois filmes;
 * 
 * @param filme1 Ponteiro para  estrutura do tipo "tfilme" do primeiro filme que terá sesu nome comparado;
 * @param filme2 Ponteiro para  estrutura do tipo "tfilme" do segundo filme que terá sesu nome comparado;
 * @return int 1 se o nome do primeiro filme for maior (ou em ordem alfabética vier depois) do segundo filme,
 * -1 se o nome do primeiro fime for menor (ou em ordem alfabética vier antes) do segundo filme, 0 caso os nomes dos dois fimes forem iguais;
 */
int CompararNomesFilmes(tFilme *filme1, tFilme *filme2);

/**
 * @brief Imprime o nome do filme;
 * 
 * @param filme Ponteiro para  estrutura do tipo "tfilme" que terá seu nome impresso;
 */
void ImprimirNomeFilme(tFilme *filme);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) um filme;
 * 
 * @param filme Ponteiro para  estrutura do tipo "tfilme" que será destruído (terá sua memória desalocada);
 */
void DestruirFilme(tFilme *filme);

#endif