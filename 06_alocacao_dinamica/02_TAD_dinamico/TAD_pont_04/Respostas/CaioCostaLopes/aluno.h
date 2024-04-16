#ifndef _ALUNO_H_
#define _ALUNO_H_

typedef struct Aluno {
     char *nome;
     int matricula;
     int n1, n2, n3;
}tAluno;

/**
 * @brief Cria um aluno com os dados vazios;
 * 
 * OBS: Atributos do tipo inteiro devem receber o valor -1 e o ponteiro para o nome do aluno deve apontar para NULL;
 * 
 * @return tAluno* Estrutura do tipo "tAluno" com os dados criados;
 */
tAluno * CriaAluno();

/**
 * @brief Lê os dados de uma aluno;
 * 
 * @param aluno Ponteiro para o aluno (alocado dinâmicamente), cujos dados serão preenchidos nesta função;
 */
void LeAluno(tAluno *aluno);

/**
 * @brief Compara as matrículas de dois alunos;
 * 
 * @param aluno1 Ponteiro para o primeiro aluno a ser comparado;
 * @param aluno2 Ponteiro para o segunda aluno a ser comparado;
 * @return int 1 se a matrícula do "aluno1" q for maior que a do "aluno2", -1 se a matrícula do "aluno1" for menor que a do "aluno2" e 0 caso as matrículas sejam iguais;
 */
int ComparaMatricula(tAluno *aluno1, tAluno aluno2);

/**
 * @brief Calcula a média das notas de um aluno;
 * 
 * @param aluno Ponteiro para o aluno que terá a média de suas notas calculada;
 * @return int Média das notas do aluno;
 */
int CalculaMediaAluno(tAluno *aluno);

/**
 * @brief Verifica se um aluno foi aprovado ou reprovado;
 * 
 * @param aluno Ponteiro para o aluno a ser verificado;
 * @return int 1 se o aluno foi aprovado e 0, se foi reprovado;
 */
int VerificaAprovacao(tAluno *aluno);

/**
 * @brief Imprime os dados de um aluno;
 * 
 * @param aluno Ponteiro para o aluno a ser impresso;
 */
void ImprimeAluno(tAluno *aluno);

/**
 * @brief Apaga (libera a memória alocada dinamicamente do) aluno
 * 
 * @param aluno Ponteiro para o aluno a ser apagado;
 */
void ApagaAluno(tAluno *aluno);

#endif