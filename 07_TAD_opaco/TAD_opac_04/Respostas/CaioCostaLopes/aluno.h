#ifndef _ALUNO_H_
#define _ALUNO_H_

typedef struct Aluno tAluno;

/**
 * @brief Cria (aloca memória dinamicamente para) um novo aluno com eus atributos inicializados;
 * 
 * @return tAluno* Ponteiro para a estrutura do tipo "tAluno" com seus atributos inicializados;
 */
tAluno *CriaAluno();

/**
 * @brief Lê os dados de um aluno da entrada padrão;
 * 
 * @param aluno Ponteiro para a estrutura do tipo "tAluno" onde serão armazenados os dados lidos do aluno;
 */
void LeAluno(tAluno *aluno);

/**
 * @brief Compara as matrículas de dois alunos;
 * 
 * @param aluno1 Ponteiro para a estrutura do tipo "tAluno" do primeiro aluno que terá sua matrícula comparada;
 * @param aluno2 Ponteiro para a estrutura do tipo "tAluno" do segundo aluno que terá sua matrícula comparada;
 * @return int 1 se a matrícula do aluno 1 for maior que a do aluno 2, -1 se a matrícula do aluno 1 for menor que a do aluno 2 e 0 csao as matrículas sejam iguais;
 */
int ComparaMatricula(tAluno *aluno1, tAluno *aluno2);

/**
 * @brief Calcula a média das notas de um aluno;
 * 
 * @param aluno Ponteiro para a estrutura do tipo "tAluno" que terá a média de suas notas calculada;
 * @return int A média das notas de um aluno;
 */
int CalculaMediaAluno(tAluno *aluno);

/**
 * @brief Verifica se um aluno foi aprovado ou reprovado;
 * 
 * @param aluno Ponteiro para a estrutura do tipo "tAluno" que será verificada sua aprovação ou não aprovação;
 * @return int 1 se o aluno for aprovado (estiver com média de notas acima ou igual a média pré-estabelecida - 7), 0 caso contrário;
 */
int VerificaAprovacao(tAluno *aluno);

/**
 * @brief Imprime os dados de um aluno;
 * 
 * @param aluno Ponteiro para a estrutura do tipo "tAluno" que terá seus dados impressos;
 */
void ImprimeAluno(tAluno *aluno);

/**
 * @brief Apaga (desaloca a memória dinamicamente de) um aluno;
 * 
 * @param aluno Ponteiro para a estrutura do tipo "tAluno" que será apagado (e terá a memória desalocada dinamicamente);
 */
void ApagaAluno(tAluno *aluno);

#endif