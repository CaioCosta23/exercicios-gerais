#ifndef _PESSOA_H_
#define _PESSOA_H_

typedef struct Pessoa tPessoa;

struct Pessoa{
    char nome[100];
    tPessoa *pai;
    tPessoa *mae;
    tPessoa *irmao;
};

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros pai, mae e irmão com 'NULL';
 * 
 * @return tPessoa Nova pessoa sem pais e irmãos associados;
 */
tPessoa CriaPessoa();

/**
 * @brief Lê os dados de uma pessoa;
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida;
 */
void LePessoa(tPessoa *pessoa);

/**
 * @brief Verifica se uma pessoa possui pai e/ou mãe associados (ou seja, verifica se os ponteiros pai e/ou mãe é/são diferentes de 'NULL');
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada;
 * @return int 1 se a pessoa possuir pai e/ou mãe associados e 0 caso contrário;
 */
int VerificaSeTePaisPessoa(tPessoa *pessoa);

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mãe associados;
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa;
 * OBS: Use a função 'VerificaSeTemPais()' para verificar se a pessoa possui pai e/ou mãe associados. Também imprimir o nome do irmão (caso ele exista);
 */
void ImprimePessoa(tPessoa *pessoa);

/**
 * @brief Verifica se duas pessoas são irmaos, ou seja, se o pai e mãe de ambos forem iguais (ponteiros forem iguais/apontarem para mesmo pai e mãe);
 * 
 * @param pessoa1 Ponteiro para a primeira pessoa;
 * @param pessoa2 Ponteiro para a segunda pessoa;
 * @return int 1 se as pessoas forem irmã(o)s e 0 caso contrário;
 */
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2);

/**
 * @brief Lê as pessoas associadas da entrada padrão e altera as pessoas de forma a representar as associações lidas (também verificar se há irmãos a se associar);
 * 
 * @param pessoas Vetor (lista/"array") de pessoas a serem associadas;
 * @param numPessoas Número de pessoas a serem associadas (tamanho do vetor);
 */
void AssociaFamiliasGruposPessoas(tPessoa pessoas[], int numPessoas);

#endif