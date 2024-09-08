#if !defined(_BASE_ALUNOS_H_)
#define _BASE_ALUNOS_H_

typedef struct BaseAlunos tBaseAlunos;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma base de alunos.
 * 
 * @return Ponteiro para a estrutura do tipo "tBaseAlunos" que contém os campos de dados inicializados da base de alunos.
 */
tBaseAlunos *CriarBaseAlunos();

/**
 * @brief Lê uma base de dados de alunos de um arquivo;
 * 
 * @param baseAlunos Ponteiro para a estrutura do tipo "tBaseAlunos" que contém os dados atualizados da base de alunos;
 * @param nomeArquivo O nome do arquivo a ser lido;
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo);

/**
 * @brief Obtém o coeficiente de rendimento médio da base de alunos;
 * 
 * @param baseAlunos Ponteiro para a estrutura do tipo "tBaseAlunos" que contém os dados atualizados da base de alunos;
 * @return O coeficiente de rendimento médio da base de alunos;
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) uma base de alunos;
 * 
 * @param baseAlunos Ponteiro para a estrutura do tipo "tBaseAlunos" que contém os dados atualizados da base de alunos que sera destruída;
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos);

#endif