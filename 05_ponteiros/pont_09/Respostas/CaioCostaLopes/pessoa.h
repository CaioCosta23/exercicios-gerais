#ifndef _PESSOA_H_
#define _PESSOA_H_

typedef struct Pessoa tPessoa;

struct Pessoa {
    char nome[100];
    tPessoa *pai;
    tPessoa *mae;
};

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual ao '\0') e inicializa os ponteiros para pai e mãe com 'NULL';
 * 
 * @return tPessoa uma nova pessoa e sem pais;
 */
tPessoa CriaPessoa();

/**
 * @brief Lê os dados de uma pessoa;
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida;
 */
void LePessoa(tPessoa *pessoa);

/**
 * @brief Verifica se uma pessoa possui pai e/ou mãe (verifica se pelo menos um dos ponteiros que aponta para pai e/ou mãe é diferente de NULL);
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada;
 * @return int 1 se a pessoa possuir pai e/ou mãe, e 0 caso contrário;
 */
int VerificaSeTemPaisPessoa(tPessoa *pessoa);

/**
 * @brief Imprime os dados de uma pessoa (caso a mesma tenha pai e/ou mae);
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa;
 * OBS: Use a funcao 'VerificaSeTemPaisPessoa()' para verificar se a pessoa possui pai e/ou mãe. Também imprima o nome do irmão caso ele exista;
 */
void ImprimePessoa(tPessoa *pessoa);

/**
 * @brief Le as associações da entrada padrão e altera as pessoas de forma a representar as associações lidas;
 * 
 * @param pessoa Vetor (lista/array) de pesoas a serem associadas;
 */
void AssociaFamiliasGruposPessoas(tPessoa pessoa[]);
