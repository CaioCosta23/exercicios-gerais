#if !defined(_ALUNO_H_)
#define _ALUNO_H_

#include "vector.h"

typedef struct ALuno tAluno;

/**
 * @brief Cria (aloca a memória dinamicamente de) um aluno;
 * 
 * @return tAluno* Ponteiro para a estrutura do tipo "tAluno" que contém os campos de dados do aluno inicializados;
 */
tAluno *CriaAluno();

/**
 * @brief Lê os dados de um aluno;
 * 
 * @param aluno Ponteiro para a estrutura do tipo "tAluno" que contém os campos de dados onde serão armazenadas as informações do aluno;
 */
void LeAluno(tAluno *aluno);

/**
 * @brief Obtém o gênero do aluno;
 * 
 * @param aluno Ponteiro para a estrutura do tipo "tAluno" que contém os dados atualizados do aluno;
 * @return char Gênero do aluno;
 */
char GetGeneroAluno(tAluno *aluno);
/**
 * @brief Obtém a nota do aluno;
 * 
 * @param aluno Ponteiro para a estrutura do tipo "tAluno" que contém os dados atualizados do aluno;
 * @return float Nota do aluno;
 */
float GetNotaAluno(tAluno *aluno);

#endif