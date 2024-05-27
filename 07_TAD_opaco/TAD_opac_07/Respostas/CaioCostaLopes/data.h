#ifndef _data
#define _data

typedef struct Data tData;

/**
 * @brief Cria (aloca a memória dinamicamente para uma) data com seus parâmetros inicializados;
 * 
 * @return tData* Ponteiro para a estrutura do tipo "tData";
 */
tData *CriaData();

/**
 * @brief Lê uma data (dia, mês e ano) da entrada padrão;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" que receberá os dados lidos e terá seus campos preenchidos com os mesmos;
 */
void LeData(tData *data);

/**
 * @brief Verifica se uma data é válida;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" a ser verificada;
 * @return int 1 se a data for válida, 0 caso contrário;
 */
int VerificaDataValida(tData *data);

/**
 * @brief Verifica se um ano é bissexto;
 * 
 * @param data Ponteiro paraa estrutura do tipo "tData" que será analisada;
 * @return int 1 se o ano da data for bissexto, 0 caso contrário;
 */
int VerificaBissexto(tData *data);

/**
 * @brief Retorna o número de dias de um mês (específico);
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" que terá o número de dias do mês da data repassado ao longo do programa;
 * @return int Número de dias do mês da data;
 */
int NumeroDiasMes(tData *data);

/**
 * @brief Compara duas datas (indicando qual é a data mais à frente e qual a mais antiga);
 * 
 * @param data1 Ponteiro para a estrutura do tipo "tData" da primeira data a ser comparada;
 * @param data2 Ponteiro para a estrutura do tipo "tData" da segunda data a ser comparada;
 * @return int -1 se a data 1 for maior (estiver mais à frente) que a data 2, 1 se a data 2 for maior (estiver mais à frente da) da data 1 e 0 caso as duas datas sejam iguais; 
 */
int ComparaData(tData *data1, tData *data2);

/**
 * @brief Calcua a diferença de dias entre duas datas;
 * 
 * @param data1 Ponteiro para a estrutura do tipo "tData" da primeira data utilizada para calcular a diferença de dias até a outra data;
 * @param data2 Ponteiro para a estrutura do tipo "tData" da segunda data utilizada para calcular a diferença de dias até a outra data;
 * @return int Número de dias entre as duas datas;
 */
int CalculaDiasAteMes(tData *data);

/**
 * @brief Imprime o nome de um mês;
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" o mês que será impresso por extenso;
 */
void ImprimeMesExtenso(tData *data);

/**
 * @brief Imprime uma data;
 * 
 * @param data Ponteiro para a estrutura o tipo "tData" que será impressa;
 */
void ImprimeDataExtenso(tData *data);

/**
 * @brief Libera (a memória alocada dinamicamente de uma) data; 
 * 
 * @param data Ponteiro para a estrutura do tipo "tData" que será liberada;
 */
void LiberaData(tData *data);

#endif