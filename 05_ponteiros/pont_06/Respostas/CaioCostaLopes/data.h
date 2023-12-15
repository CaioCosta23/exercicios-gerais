#ifndef DATA_H
#define DATA_H

typedef struct Data {
    int dia;
    int mes;
    int ano;
}tData;

/**
 * @brief Inicializa uma data com os valores pasaados como parâmetro;
 * 
 * @param dia Dia da data;
 * @param Mes Mês da data;
 * @param ano Ano da data;
 * @param data Ponteiro para a estrutura do tipo tData que será inicializada;
 */
void InicializaDataParam(int dia, int Mes, int ano, tData *data);

/**
 * @brief Lê uma data do usuário;
 * 
 * @param data Ponteiro para estrutura do tipo tData que será preenchida com seus respectivos valores;
 */
void LeData(tData *data);

/**
 * @brief Imprime uma data na tela;
 * 
 * @param data Ponteiro para a estrutura do tipo tData que terá seus dados impressos na tela;
 */
void ImprimeData(tData *data);

/**
 * @brief Verifica se um ano é bissexto;
 * 
 * @param data Estrutura do tipo tData que será verificada;
 * @return int 1 caso o ano da data seja bissexto e 0 caso contrário;
 */
int EhBissexto(tData *data);

/**
 * @brief Informa a quantidade de dias que possui o mês da data;
 * 
 * @param data Ponteiro para uma estrutura do tipo tData que terá os dias do mês definidos;
 * @return int Quantidade de dias que possui o mês da data;
 */
int InformaQtdDiasNoMes(tData *data);

/**
 * @brief Avanca uma data para o dia seguinte;
 * 
 * @param data Ponteiro para a estrutura do tipo tData que terá sua data avançada;
 */
void AvancaParaDiaSeguinte(tData *data);

/**
 * @brief Verifica se duas datas são iguais;
 * 
 * @param data1 Ponteiro para uma estrutura do tipo tData que contém os dados da primeira data a ser comparada;
 * @param data2 Ponteiro para uma estrutura do tipo tData que contém os dados da segunda data a ser comparada;
 * @return int 1 se as datas forem iguais e 0 caso contrário;
 */
int EhIgual(tData *data1, tData *data2);

#endif