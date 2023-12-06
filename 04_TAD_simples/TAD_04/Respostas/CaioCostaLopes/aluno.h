#ifndef _ALUNO_H_
#define _ALUNO_H_

typedef struct Aluno {
    char nome[50]; // Nome do Aluno;
    int matricula; // Matrícula do aluno;
    int n1, n2, n3; // Notas das avaliacoes;
}tAluno;

/**
 * @brief Cria um novo aluno com os dados informados;
 * 
 * @param nome Nome d aluno;
 * @param matricula Matrícula;
 * @param n1 Nota da primeira avaliação;
 * @param n2 Nota da segunda avaliação;
 * @param n3 Nota da terceira avaliação;
 * @return tAluno Estrutura do aluno com os dados criados;
 */
tAluno CriaAluno(char nome[], int matricula, int n1, int n2, int n3);

/**
 * @brief Lê os dados de um aluno;
 * 
 * @return tAluno Retorna uma estrutura "tAluno" com os dados do aluno;
 */
tAluno LeAluno();

/**
 * @brief Compara as matrículas de dois alunos;
 * 
 * @param aluno1 Primeiro aluno a ser comparado;
 * @param aluno2 Segundo aluno a ser comparado;
 * @return int 1 sse a matrícula do aluno 1 é maior que a do aluno 2, -1 se a matrícula do aluno 2
 * for maior que a do aluno 1, e 0 se as matrículas forem iguais;
 */
int ComparaMatricula(tAluno aluno1, tAluno aluno2);

/**
 * @brief Calcula a média das notas de um aluno;
 * 
 * @param aluno Aluno a ter a média calculada;
 * @return int Média das notas dos alunos;
 */
int CalculaMediaAluno(tAluno aluno);

/**
 * @brief Verifica se um aluno foi aprovado ou reprovado;
 * 
 * @param aluno Aluno a ser verificado;
 * @return int 1 se o aluno foi aprovado, e 0, caso ele tenha sido reprovado;
 */
int VerificaAprovacao(tAluno aluno);

/**
 * @brief Imprime os dados de um aluno;
 * 
 * @param aluno Aluno a ser impresso;
 */
void ImprimeAluno(tAluno aluno);

#endif