#ifndef _data
#define _data

typedef struct data tData;

/**
 * @brief Cria (aloca dinamicamente a memória de) uma data;
 * 
 * @param dia Dia da data;
 * @param mes Mês da data;
 * @param ano Ano da data;
 * @return tData* Ponteiro para a estrutura dotipo "tData" que contém os dados da data;
 */
tData *CriaData(int dia, int mes, int ano);

/**
 * @brief Lê (da entrada padrão) os dados de uma data;
 * 
 * @return tData* Ponteiro para a estrutura do tipo "tData" com os campos de dados (informações) da data;
 */
tData *LeData();

/**
 * @brief Calcula a idade de uma pessoa com base na data de nascimento e no dia limite de registro de uma pessoa no P.A.D;
 * 
 * @param nascimento Ponteiro para a estrutura do tipo "tData" que contém a data de nascimento;
 * @param diacalc Ponteiro para a estrutura do tipo "tData" que contém o dia do registro no P.A.D;
 * @return int 
 */
int CalculaIdadeData(tData *nascimento, tData *diacalc);

/**
 * @brief Imprime uma data;
 * 
 * @param d Ponteiro para a estrutura do tipo "tData" que contém os dados da data;
 */
void ImprimeData(tData *d);

/**
 * @brief Libera (a memória alocada dinamicamente de) uma data;
 * 
 * @param d Ponteiro paraa estrutura do tipo "tData";
 */
void LiberaData(tData *d);

#endif