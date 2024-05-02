#ifndef _pad
#define _pad

#include "lesao.h"
#include "paciente.h"

#define DIA_PAD 15 // Dia da data limite daté onde será analisado;
#define MES_PAD 10 // Mês da data limite daté onde será analisado;
#define ANO_PAD 2023 // Ano da data limite daté onde será analisado;

typedef struct pad {
    int qtdpacientes;
    tPaciente *listapacientes[100];
}tPad;

/**
 * @brief Cria uma estrutura do tipo "tPad" (com a memória alocada dinamicamente);
 * 
 * @return tPad* Estrutura do tipo "tPad" com seus atributos inicializados (e alocados dinamicamente);
 */
tPad *CriaPad();

/**
 * @brief Executa o programa, permitindo que o usuário realize as ações (cadastrar paciente, lesão, etc.);
 * 
 * @param p Ponteiro para a estrutura do tipo "tPad" que será usado para armazenar os dados do programa;
 */
void RodaPad(tPad *p);

/**
 * @brief Imprime o relatório com as informações dos pacientes e lesões do PAD;
 * 
 * @param p Ponteiro para a estrutura do tipo "tPad" que terá seus dados impressos;
 */
void ImprimeRelatorioPad(tPad *p);

/**
 * @brief Apaga (libera a memória alocada dinamicamente do) PAD; 
 * 
 * @param p Ponteiro para a estrutura do tipo "tPad" que (terá a memória desalocada dinamicamente e) será apagada
 */
void LiberaPad(tPad *p);

#endif