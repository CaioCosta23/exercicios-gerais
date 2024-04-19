#ifndef _data
#define _data

typedef struct Data {
    int data;
    int mes;
    int ano;
}tData;

/**
 * @brief Cria (aloca dinamicamente) uma estrutura do tipo "tData";
 * 
 * @return tData* Estrutura do tipo "tData" com seus dados inicializados (com o valor - 1);
 */
tData *CriaData();

/**
 * @brief Lê o dia, o mês e o ano e armazena em uma estrutura do tipo "tData";
 * 
 * @param data Ponteiro para a data;
 */
void LeData(tData *data);

/**
 * @brief Verifica e uma data é válida;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData";
 * @return int 1 se a data é válida, 0 caso contrário;
 */
int VerificaDataValida(tData *data);

/**
 * @brief Verifica se um ano é bissexto;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData";
 * @return int 1 se o ano for bissexto, 0 caso contrário;
 */
int VerificaBissexto(tData *data);

/**
 * @brief Obtém o número de dias de um determinado mês;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData";
 * @return int Número de dias do mês da data;
 */
int NumeroDiasMes(tData *data);

/**
 * @brief Compata duas datas;
 * 
 * @param data1 Ponteiro para a primeira estrutura do tipo "tData" a ser comparada;
 * @param data2 Ponteiro para a segunda estrutura do tipo "tData" a ser comparada;
 * @return int 1 se a 'data1' for maior que a 'data2', -1 se a 'data1' for menor que a 'data2' e 0 caso as duas datas sejam iguais;
 */
int ComparaData(tData *data1, tData *data2);

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData";
 * @return int Número de dias até o início do Mês da data;
 */
int CalculaDiasAteMes(tData *data);

/**
 * @brief Calcula a diferença de dias entre duas datas;
 * 
 * @param data1 Primeira data a ser comparada;
 * @param data2 int Número de dias entre as duas datas;
 * @return int Número de dias entre as duas datas;
 */
int CalculaDiferencaDias(tData *data1, tData *data2);

/**
 * @brief Imprime uma data no formato extenso;
 * 
 * @param data Ponteiro para a estutura do tipo "tData" que será impresso;
 */
void ImprimeDataextenso(tData *data);

/**
 * @brief Imprime o mês de uma data por extenso;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" que terá o mês impresso por extenso
 */
void ImprimeMesExtenso(tData *data);

/**
 * @brief Destrói (libera a memória) da estrutura do tipo "tData";
 * 
 * @param data Ponteiro para estrutura do tipo "tData" a ser destruida (liberada);
 */
void LiberaData(tData *data);

#endif