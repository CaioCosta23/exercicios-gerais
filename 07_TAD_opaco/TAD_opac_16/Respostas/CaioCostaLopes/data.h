#ifndef _data
#define _data

typedef struct Data tData;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma data;
 * 
 * @return tData Ponteiro paa a estrutura do tipo "tData" que contém os campos de dados da data inicializados;
 */
tData *CriaData();

/**
 * @brief Processa (lê - no formato 'string') o dia, o mês e o ano de uma data;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" que receberá os dados da data;
 * @param str 'String' (data) que será processada;
 */
void ProcessaDiaMesAno(tData *data, char *str);

/**
 * @brief Processa (lê - no formato 'string') o dia da semana correspondente a uma data;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" que receberá os dados da data;
 * @param str 'String' (dia da semana em que se encontra a data) que será processada;
 */
void ProcessaDiaDaSemana(tData *data, char *str);

/**
 * @brief Processa (lê - no formato 'string') o horário (hora, minuto e segundo) do dia da semana correspondente a uma data;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" que receberá os dados da data;
 * @param str 'String' (horário do dia da semana em que se encontra a data) que será processada;
 */
void ProcessaHorario(tData *data, char *str);

/**
 * @brief Verifica se uma data é válida;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" que contém os dados da data;
 * @return int 1 se a data é válida, 0 caso contrário;
 */
int VerificaDataValida(tData *data);

/**
 * @brief Verifica se o ano da data é bissexto;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" que contém os dados da data;
 * @return int 1 se o ano da data é bissexto, 0 caso contrário;
 */
int VerificaBissexto(tData *data);

/**
 * @brief Obtém o número de dias do mês da data;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" que contém os dados da data;
 * @return int Número de dias que o mês da data possui;
 */
int NumeroDiasMes(tData *data);

/**
 * @brief Compara duas datas;
 * 
 * @param data1 Ponteiro para a estrutura do tipo "tData" que contém os dados da primeira data;
 * @param data2 Ponteiro para a estrutura do tipo "tData" que contém os dados da segunda data;
 * @return int 1 primeira data for maior que a segunda, -1 se a primeira data for menor que a segunda ou 0 caso ambas as datas sejam iguais;
 */
int ComparaDiaMesAno(tData *data1, tData *data2);

/**
 * @brief Calcula o número de dias até o inicio do mês da data;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" que contém os dados da data;
 * @return int Número de dias até o início do mês da data;
 */
int CalculaDiasAteMes(tData *data);

/**
 * @brief Calcula a diferença de dias entre duas datas;
 * 
 * @param data1 Ponteiro para a estrutura do tipo "tData" que contém os dados da primeira data;
 * @param data2 Ponteiro para a estrutura do tipo "tData" que contém os dados da segunda data;
 * @return int Número de dias entre as duas datas;
 */
int CalculaDiferencaDias(tData *data1, tData *data2);

/**
 * @brief Calcula a diferença em horas entre duas datas;
 * 
 * @param data1 Ponteiro para a estrutura do tipo "tData" que contém os dados da primeira data;
 * @param data2 Ponteiro para a estrutura do tipo "tData" que contém os dados da segunda data;
 * @return int Número de horas entre as duas datas (no formato convenional - horas:minutos);
 */
int CalculaHorasEntreDatas(tData *data1, tData *data2);

/**
 * @brief Verifica se a data será correspondente a um Sábado ou Domingo;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" que contém os dados da data;
 * @return int 1 se a data for em um Sábado ou Domingo, 0 caso contrário;
 */
int DataEhSabadoOuDomingo(tData *data);

/**
 * @brief Atualiza a data para o dia seguinte;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" que contém os dados da data que será atualizada;
 */
void DataDiaSeguinte(tData *data);

/**
 * @brief Copia os dados de uma data no formato Dia/Mês/Ano para uma data 'TGT';
 * 
 * @param src Ponteiro para a estrutura do tipo "tData" que contém os dados da data;
 * @param tgt Ponteiro para a estrutura do tipo "tData" que receberá os dados de outra data;
 */
void CopiaDiaMesAno(tData *src, tData *tgt);

/**
 * @brief Destrói (desaloca a memória alocada dinamicamente de) uma data;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" que contém os dados da data;
 */
void DestroiData(tData *data);

#endif