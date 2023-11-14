#ifndef _data
#define _data

/**
 * @brief Verifica se uuma data e valida;
 * 
 * @param dia Dia da data;
 * @param mes Mes da data;
 * @param ano Ano da data;
 * @return int 1 se a data for valida e 0, caso contrario; 
 */
int verificaDataValida(int dia, int mes, int ano);

/**
 * @brief Imprime o nome do mes por extenso;
 * 
 * @param mes Mes a ser impresso;
 */
void imprimeMesExtenso(int mes);

/**
 * @brief Imprime a data por extenso
 * 
 * @param dia Dia da data;
 * @param mes Mes da data;
 * @param ano Ano da data;
 */
void imprimeDataExetenso(int dia, int mes, int ano);

/**
 * @brief Verifica se o ano e bissexto
 * 
 * @param ano Ano a ser verificado;
 * @return int 1 se o ano for bissexto e 0, caos contrario;
 */
int verificaBissexto(int ano);

/**
 * @brief Calcula o numero de dias de um mes;
 * 
 * @param mes mes a ser verificado;
 * @param ano Ano da data;
 * @return int retorna o numero de dias;
 */
int numeroDiasMes(int mes, int ano);

/**
 * @brief Compara duas datas;
 * 
 * @param dia1 Dia da primeira data;
 * @param mes1 Mes da primeira data data;
 * @param ano1 Ano da primeira data
 * @param dia2 Dia da segunda data;
 * @param mes2 mes da segunda data;
 * @param ano2 Ano da segunda data;
 * @return int retorna 1 se a primeira data for maior que a segunda, - 1 se a segunda
 * data e maior que a primeira e 0 caso as duas forem iguais;
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2);

/**
 * @brief Calcula o numero de dias ate o mes;
 * 
 * @param mes Mes da data;
 * @param ano Ano da data;
 * @return int retorna o numero de dias ate o mes;
 */
int calulaDiasAteMes (int mes, int ano);

/**
 * @brief Calcula a diferenca em dias entre duas datas;
 * 
 * @param dia1 Dia da primeira data;
 * @param mes1 Mes da primeira data;
 * @param ano1 Ano da primeira data;
 * @param dia2 Dia da segunda data;
 * @param mes2 Mes da segunda data;
 * @param ano2 Ano da segunda data;
 * @return int Retorna o numero de dias de diferenca entre as datas;
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2);