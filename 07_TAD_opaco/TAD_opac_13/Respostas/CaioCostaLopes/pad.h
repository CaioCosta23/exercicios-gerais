#ifndef _pad
#define _pad

#include "paciente.h"
#include "lesao.h"

#define DIA_PAD 15 // Dia limite de preenchimento do P.A.D;
#define MES_PAD 10 // Mês limite de preenchimento do P.A.D
#define ANO_PAD 2023 // Ano de preenchimento do P.A.D

typedef struct pad tPad;

/**
 * @brief Cria (aloca a memória dinamicamente de) um P.A.D;
 * 
 * @return tPad* Ponteiro para uma estrutura do tipo "tPad" que contém os campos de informação do P.A.D (já inicializados);
 */
tPad *CriaPad();

/**
 * @brief Roda o programa do P.A.D;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPad" que contém os dados (campos de informação) do P.A.D;
 */
void RodaPad(tPad *p);

/**
 * @brief Imprime o relatório final de dados do P.A.D;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPad" que contém os dados (campos de informação) finais do P.A.D;
 */
void ImprimeRelatorioPad(tPad *p);

/**
 * @brief Libera (a memória alocada dinamicamente) o P.A.D;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPad" que contém os dados (campos de informação) do P.A.D;
 */
void LiberaPad(tPad *p);

#endif