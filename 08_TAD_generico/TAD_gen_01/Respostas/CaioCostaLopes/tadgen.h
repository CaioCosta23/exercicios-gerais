#ifndef _tadgen
#define _tadgen

typedef enum {
    FLOAT = 0, INT = 1
}Type;

typedef struct generic tGeneric;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma estrutura genérica e diâmica que pode armazenar tanto 'int's quanto 'float's;
 * 
 * @param type Tipo do vetor generico;
 * @param numElem Quantidade de elementos que serão armazenados no vetor;
 * @return tGeneric* Ponteiro para a estrutura do tipo "tGeneric" que contém o vetor de elementos de tipo genérico;
 */
tGeneric *CriaGenerico(Type type, int numElem);

/**
 * @brief Lê o conteúdo do vetor genérico;
 * 
 * @param gen Ponteiro para a estrutura do tipo "tGeneric" que contém os dados do vetor do tipo genérico;
 */
void LeGenerico(tGeneric *gen);

/**
 * @brief Imprime o vetor com os tipos de dados genéricos;
 * 
 * @param gen Ponteiro para a estrutura do tipo "tGeneric" que contém os dados do vetor do tipo genérico;
 */
void ImprimeGenerico(tGeneric *gen);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) uma estrutura do tipo "tGeneric";
 * 
 * @param gen Ponteiro para a estrutura do tipo "tGeneric" que contém os dados do vetor do tipo genérico que será destruído;
 */
void DestroiGenerico(tGeneric *gen);

#endif