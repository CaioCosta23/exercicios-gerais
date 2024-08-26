#if !defined(_RELATORIO_H_)
#define _RELATORO_H_

#include "vector.h"

/**
 * @brief Imprime o relatório da lista de alunos;
 * 
 * @param alunos Ponteiro para a estrutura do tipo "Vector" que contém a lista de alunos os seus dados atualizados;
 * OBS: O relatório deve possuir a média das notas, porcentagem de alunos aprovados e a porcentagem de alunos aprovados em cada gênero
 */
void ImprimeRelatorio(Vector *alunos);

#endif