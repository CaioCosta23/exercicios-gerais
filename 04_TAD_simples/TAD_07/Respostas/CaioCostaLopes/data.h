#ifndef _data
#define _data

typedef struct Data {
    int dia;
    int mes;
    int ano;
}tData;

/**
 * @brief Cria uma data a partir de valores de dia, mês e ano;
 * 
 * @param dia Dia da data a ser criada;
 * @param mes Mês da dara a ser criada;
 * @param ano Ano da data a ser criada;
 * @return tData Data a ser criada a partir dos valores, dia, mês ano;
 */
tData CriaData(int dia, int mes, int ano);

/**
 * @brief Verifica se uma data é válida;
 * 
 * @param data Data a ser verificada;
 * @return int 1 se a data é válida e 0, caso contrário;
 */
int VerificaDataValida(tData data);

/**
 * @brief Imprime o mês de uma data em formato extenso;
 * 
 * @param data Data cujo o mês será impresso em formato em extenso;
 */
void ImprimeMesExtenso(tData data);

/**
 * @brief Imprime a data em formato extenso;
 * 
 * @param data Data a ser impressa em formato extenso;
 */
void ImprimeDataExtenso(tData data);

/**
 * @brief Verifica se um ano é bissexto;
 * 
 * @param data Data cujo o ano será verificado;
 * @return int 1 se o ano é bissexto, 0 caso contrário;
 */
int VerificaBissexto(tData data);

/**
 * @brief Retorna o numero de dias de um determinado mês;
 * 
 * @param data Data cujo o mês terpa o número de dias retornado;
 * @return int Número de dias do mês da data;
 */
int NumeroDiasMes(tData data);

/**
 * @brief Compara duas datas;
 * 
 * @param data1 Primeira data a ser comparada;
 * @param data2 Segunda data a ser comparada;
 * @return int 1 se a data 1 for maior que a tada 2, - 1 se a data 2 for maior que a data 1
 * e 0 se as datas forem iguais;
 */
int ComparaData(tData data1, tData data2);

/**
 * @brief Calcula o número de dias até o inicio do mês de uma determinada data;
 * 
 * @param data Calcula a diferenca em dias entre duas datas;
 * @return int Número de dias até o início do mês da data;
 */
int CalculaDiasAteMes(tData data);

/**
 * @brief Calcula a diferenca em dias entre duas datas;
 * 
 * @param data1 Primeira data a ser comparada;
 * @param data2 Segunda data a ser comparada;
 * @return int Número de dias entre as duas datas;
 */
int  CalculaDiferencaDias(tData data1, tData data2);

#endif