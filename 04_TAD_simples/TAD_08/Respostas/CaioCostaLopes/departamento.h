#ifndef _depto
#define _depto

#define STRING_MAX 101 // Número máximo de caracteres por string;

typedef struct Departamento {
    char nome [STRING_MAX]; // Nome do departamento;
    char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX]; // Nomes dos cursos do departamento;
    int m1, m2, m3; // Médias de notas dos cursos do departamento;
    char diretor[STRING_MAX]; // Nome do diretor do apartamento;
    float media_geral;
}tDepartamento;

/**
 * @brief Cria um departamento a partir de valores dos nomes dos cursos, nome do departamento, 
 * média por curso e nome do diretor;
 * 
 * @param c1 Nome do curso 1 do departamento;
 * @param c2 Nome do curso 2 do departamento;
 * @param c3 Nome do curso 3 do departamento;
 * @param nome Nome do departamento;
 * @param m1 Média do curso 1 (c1);
 * @param m2 Média do cursoi 2 (c2);
 * @param m3 Média do curso 3 (c3);
 * @param diretor Nome do diretor do deparatanmento;
 * @return tDepartamento Departamento criado à partir dos valores (nomes dos cursos, nome do departamento, média por curso e nome do diretor);
 */
tDepartamento criaDepartamaneto(char c1 [], char c2[], char c3[], char nome[],
int m1, int m2, int m3, char diretor[]);

/**
 * @brief Imprime os atributos do departamento (curos, nome do departamento, médias dos cursos e nome do diretor);
 * 
 * @param departamento Departamento cujos os atributos serão impressos;
 */
void imprimeAtributosDepartamento(tDepartamento departamento);

/**
 * @brief Verifica se a média inserida é válida (ou seja, se está no intervalo de 0 à 10);
 * 
 * @param media valor da media a ser verificada;
 * @return int 1 se a média for válida e 0 caso contrário;
 */
int validaMediaDepartamento(int media);
/**
 * @brief Calcula o desvio padrão das médias dos (por curso) do departamento;
 * 
 * @param depto Departamento cujo o Desvio Padrão (por curso) das médiaas deve ser calculado;
 * @return double Valor do cálculo do Desvio Padrão obtido;
 */
double calculaDesvioPadraoDepartamento(tDepartamento depto);

/**
 * @brief Calcula a média simples das notas dos cursos do departamento;
 * 
 * @param depto Departamento cuja a média deve ser calculada;
 * @return double Valor dao cálculo da média obtido;
 */
double calculaMediaGeralDepartamento(tDepartamento depto);

/**
 * @brief Ordena vetor de departamentos em ordem decrescente de acordo com as médias dos departamentos;
 * 
 * @param d Vetor de departamentos a ser ordenado;
 * @param tamanho tamanho do vetor de departamentos a ser ordenado;
 */
void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho);

#endif