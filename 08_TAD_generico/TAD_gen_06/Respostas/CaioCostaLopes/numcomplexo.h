#ifndef _NUMCOMPLEXO
#define _NUMCOMPLEXO

typedef struct complexo tNumComplexo;

/**
 * @brief Cria (aloca a memória dinâmicamente de) um número complexo;
 *
 * @param real Parte real do número complexo;
 * @param imag Parte Imaginária do número complexo;
 *
 * @return Ponteiro para a estrutura do tipo "tNumeroComplexo" que contém os campos de dados do número complexo inicializados;
 */
tNumComplexo *CriaNumComplexo(float real, float imag);

/**
 * @brief Obtém a parte imaginária do número complexo;
 *
 * @param cplx Ponteiro para a estrutura do tipo "tNumeroComplexo" que contém os dados da atualizados de um número complexo;
 *
 * @return Parte imáginária (número em notação de ponto flutuante) do número complexo;
 */
float PegaParteImagComplexo(tNumComplexo *cplx);

/**
 * @brief Obtém a parte real do número complexo;
 *
 * @param cplx Ponteiro para a estrutura do tipo "tNumeroComplexo" que contém os dados da atualizados de um número complexo;
 *
 * @return Parte real (número em notação de ponto flutuante) do número complexo;
 */
float PegaParteRealComplexo(tNumComplexo *cplx);

/**
 * @brief Obtém o número de bytes do número complexo;
 *
 * @return Número de bytes do número comlexo;
 */
int RetornaNumBytesComplexo();

/**
 * @brief Soma dois números complexos;
 *
 * @param n1 Ponteiro para a estrutura do tipo "tNumeroComplexo" para o primeiro número complexo a ser somado com outro;; 
 * @param n2 Ponteiro para a estrutura do tipo "tNumeroComplexo" para o segundo número complexo a ser somado com outro;
 *
 * @return Ponteiro para a estrutura do tipo "tNumeroComplexo" resultado da soma entre dois um números complexos;
 */
tNumComplexo *SomaComplexos(tNumComplexo* n1, tNumComplexo *n2);

/**
 * @brief Multiplica dois números complexos;
 *
 * @param n1 Ponteiro para a estrutura do tipo "tNumeroComplexo" para o primeiro número complexo a ser multiplicado com outro;; 
 * @param n2 Ponteiro para a estrutura do tipo "tNumeroComplexo" para o segundo número complexo a ser multiplicado com outro;
 *
 * @return Ponteiro para a estrutura do tipo "tNumeroComplexo" resultado da multiplicação entre dois um números complexos;
 */
tNumComplexo *MultComplexos(tNumComplexo* n1, tNumComplexo* n2);

/**
 * @brief Imprime um número complexo;
 *
 * @param cplx Ponteiro para a estrutura do tipo "tNumeroComplexo" que contém os dados da atualizados de um número complexo;
 */
void ImprimeNumeroComplexo(tNumComplexo *cplx);

/**
 * @brief Destrói (desaloca a memória dinâmicamente de) um número comlexo;
 *
 * @param cplx Ponteiro para a estrutura do tipo "tNumeroComplexo" que contém os dados da atualizados de um número complexo;
 */
void DestroiNumeroComplexo(tNumComplexo *cplx);

#endif
