#ifndef _data
#define _data

/**
 * @brief Verifica se uma data é válida; 
 * 
 * @param dia Dia da data;
 * @param mes Mês da data;
 * @param ano Ano da data;
 * @return int 1 se a data é válida e 0, caso contrário;
 */
int verificaDataValida(int dia, int mes, int ano);

/**
 * @brief Imprime uma data no formato DD/MM/AAAA 
 * 
 * @param dia Dia da data;
 * @param mes Mês da data;
 * @param ano Ano da data;
 */
void ImprimeData(int dia, int mes, int ano);

/**
 * @brief Imprime o nome do mês por extenso;
 * 
 * @param mes Mês da data;
 */
void imprimeMesextenso(int mes);

/**
 * @brief Imprime uma data por extenso no  formato "DD de NOME_DO_MES AAAA"
 * 
 * @param dia Dia da data;
 * @param mes Mês da data;
 * @param ano Ano da data;
 */
void imprimeExetenso(int dia, int mes, int ano);

/**
 * @brief Verifica se um ano é bissexto;
 * 
 * @param ano Ano da data
 * @return int 1 se o ano é bissexto e 0, caso contrário;
 */
int verificaBissexto(int ano);

/**
 * @brief Retorna o numero de dias de um determinado mês;
 * 
 * @param mes Mês da data
 * @param ano Ano da data;
 * @return int Retorna o numero de dias do mês;
 */
int numeroDiasMes(int mes, int ano);

/**
 * @brief Compara duas datas;
 * 
 * @param dia1 Dia da primeira data;
 * @param mes1 Mês da primeira data;
 * @param ano1 Ano da primeira data;
 * @param dia2 Dia da segunda data;
 * @param mes2 Mês da segunda data;
 * @param ano2 ano da segunda data;
 * @return int 1 se a primeira data for maior que a segunda, - 1 se asegunada data for maior que a primeira e 0 se as datas forem iguais;
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2);

/**
 * @brief Calcula o numero de dias ate o inicio de um determinado mês;
 * 
 * @param mes Mês da data;
 * @param ano Ano da data;
 * @return int Numero de dias ate o inicio do mês;
 */
int calculaDiasAteMes(int mes, int ano);

/**
 * @brief Calcula a diferença em dias entre duas datas;
 * 
 * @param dia1 Dia da primeira data;
 * @param mes1 Mês da primeira data;
 * @param ano1 Ano da primeira data
 * @param dia2 Dia da segunda data;
 * @param mes2 Mês da segunda data;
 * @param ano2 Ano da segunda data;
 * @return int Retorna o número de dias de diferença entre as datas;
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2);

/**
 * @brief Imprime a próxima data no formato DD/MM/AAAA;
 * 
 * @param dia Dia da data;
 * @param mes Mês da data;
 * @param ano Ano da data;
 */
void imprimeProximaData(int dia, int mes, int ano);

#endif