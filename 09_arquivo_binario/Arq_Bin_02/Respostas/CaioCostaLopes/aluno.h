
#if !defined(_ALUNO_H_)
#define _ALUNO_H_

#include <stdio.h>

typedef struct Aluno tAluno;

/**
 * @brief Cria (aloca a memória dinamicamente de) um aluno;
 * 
 * @param nome Nome do aluno;
 * @param dataNascimento Data de nascimento do aluno;
 * @param curso Curso em que o aluno está matriculado;
 * @param periodo Período do curso em que o aluno está;
 * @param coeficienteRendimento Coeficiente de rendimento do aluno;
 * @return Ponteiro para a estrutura do tipo "tAluno" que contém os campos de dados inicializados do aluno;
 */
tAluno *CriarAluno(char *nome, char *dataNascimento, char *curso, int periodo, float coeficienteRendimento);

/**
 * @brief Lê as informações de uma aluno de um arquivo binário;
 * 
 * @param arquivo_binario Ponteiro para o arquivo binário de onde serão lidas as informações do aluno;
 * @return Ponteiro para a estrutura do tipo "tAluno" que contém as informações de um aluno, obtidas do arquivo binário lido;
 */
tAluno *LeAluno(FILE *arquivo_binario);

/**
 * @brief Obtém o coeficiente de rendimento de um aluno;
 * 
 * @param aluno Ponteiro para a estrutura do tipo "tAluno" que contém os dados atualizados do aluno;
 * @return O coeficiente de rendimento do aluno;
 */
float GetCoeficienteRendimentoAluno(tAluno *aluno);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) um aluno;
 * 
 * @param aluno Ponteiro para a estrutura do tipo "tAluno" que contém os dados atualizados do aluno que sera destruído;
 */
void DestruirAluno(tAluno *aluno);

#endif
