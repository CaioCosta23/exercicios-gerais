#ifndef __aluno
#define __aluno

typedef struct aluno Aluno;

/**
 * @brief Cria (aloca a memória dinamicamente) um vetor/lista ("array") de alunos;
 * 
 * @param numeroAlunos Número de alunos que terá o vetor/lista ("array") de alunos;
 * @return Aluno** Ponteiro para um vvtor de estruturas do tipo "Aluno";
 */
Aluno **CriaVetorAlunos(int numeroAlunos);

/**
 * @brief Cria (aloca a memória dinamicamente de) um aluno;
 * 
 * @param nome Nome do aluno;
 * @param dtNasc data de nascimento do aluno;
 * @param cursoUfes Curso da UFES que o aluno está matriculado;
 * @param periodoIngresso Período de ingresso do aluno;
 * @param percConclusao Percentual de conclusão do curso;
 * @param CRA Coeficiente de Rendimento Acadêmico (CRA) do aluno;
 * @return Aluno* Ponteiro para a estrutura do tipo "Aluno" que contém os dados inicializados do aluno;
 */
Aluno *CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char *periodoIngresso, int percConclusao, float CRA);

/**
 * @brief Lê as informações de um vetor de alunos;
 * 
 * @param vetorAlunos Vetor/Lista ("Array") de alunos;
 * @param numeroAlunos Número de alunos que terá o vetor/lista ("array") de alunos;
 */
void LeAlunos(Aluno **vetorAlunos, int numeroAlunos);

/**
 * @brief Libera (desaloca a memória dinamicamente) um vetor de alunos;
 * 
 * @param alunos Vetor/Lista ("Array") de alunos;
 * @param numeroAlunos Numero de alunos que terá o vetor/lista ("array") de alunos;
 */
void LiberaAlunos(Aluno **alunos, int numeroAlunos);

/**
 * @brief Salva as informações de um vetor de alunos em um arquivo binário;
 * 
 * @param alunos Vetor/Lista ("Array") de alunos;
 * @param fileName Nome do arquivo que será salvo os alunos;
 * @param numeroAlunos Número de alunos que terá o vetor/lista ("array") de alunos;
 */
void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos);

/**
 * @brief Carrega as informações de um arquivo binário em um vetor de alunos;
 * 
 * @param alunos Vetor/Lista ("Array") de alunos;
 * @param fileName Nome do arquivo que será carregado os alunos;
 */
void CarregaAlunosBinario(Aluno **alunos, char *fileName);

/**
 * @brief Imprime as informações de um vetor de alunos;
 * 
 * @param alunos Vetor/Lista ("Array") de alunos;
 * @param numeroAlunos Número de alunos que terá o vetor/lista ("array") de alunos;
 */
void ImprimeAlunos(Aluno **alunos, int numeroAlunos);

#endif