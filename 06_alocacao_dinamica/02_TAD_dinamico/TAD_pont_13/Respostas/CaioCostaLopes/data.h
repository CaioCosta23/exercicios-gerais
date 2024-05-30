#ifndef _data
#define _data

typedef struct data {
    int dia;
    int mes;
    int ano;
}tData;

/**
 * @brief Cria uma estrutura (e aloca a memória dinamicamente) do tipo "tData" que receberá os dados da data;
 * 
 * @return tData* Ponteiro para uma estrutura do tipo "tData" com os sesu parâmetros inicializados;
 */
tData *CriaData();

/**
 * @brief Lê uma data da entrada padrão;
 * 
 * @return tData Ponteiro para a estrutura do tipo "tData" em que será armazenada a data;
 */
tData *LeData();

/**
 * @brief Calcula a idade de uma pessoa com base na data de nascimento e em uma data para calcular a idade;
 * 
 * @param nascimento Ponteiro para uma estrutura do tipo "tData" que contém a data de nascimento de um paciente;
 * @param diacalc Ponteiro para uma estrutura do tipo "tData" que contém uma data a ser calculada em relação a data de nascimento;
 * @return int Idade do paciente;
 */
int CalculaIdadeData(tData *nascimento, tData *diacalc);

/**
 * @brief Imprime uma data;
 * 
 * @param d Ponteiro para a estrutura do tipo "tData" que contém a data que será impressa;
 */
void ImprimeData(tData *d);

/**
 * @brief Apaga (libera a memória alocada dinamicamente da ) data;
 * 
 * @param d Ponteiro para a estrutura do tipo "tData" que (terá sua memória desalocada dinamicamente e) será apagada;
 */
void LiberaData (tData *d);

#endif