#ifndef _depto
#define _depto

#define STRING_MAX 101

typedef struct Departamento {
    char *nome; // Nome do departamento;
    char *c1, *c2, *c3; // Nomes dos cursos do departamento;
    int m1, m2, m3; // Médias de notas dos cursos do departamento;
    char *diretor; // Nome do diretor do departamento;
    float media_geral; // Média das médias do departamento;
}tDepartamento;

/**
 * @brief Cria uma estrutura (aloca dinamicamente) que possui os dados do departamento;
 * 
 * OBS: Os dados que são do tipo ponteiro devem ser inicializados com NULL e os com tipos numéricos com -1;
 * 
 * @return tDepartamento* Ponteiro ppara uma estrutura do departamento;
 */
tDepartamento *CriaDepartamento();

/**
 * @brief Preenche os dados de uma estrutura do departamento à partir de valores pré-oferecidos como parâmetro;
 * 
 * @param depto Ponteiro para uma estrutura do tipo "tDepartamento";
 * @param c1 Nome do primeiro curso do deparatamento;
 * @param c2 Nome do segundo curso do deparatamento;
 * @param c3 Nome do terceiro curso do deparatamento;
 * @param nome Nome do departamento;
 * @param m1 Média do primeiro curso;
 * @param m2 Média do segundo curso;
 * @param m3 Média do terceiro curso;
 * @param diretor Nome do diretor do departamento;
 */
void PreencheDepartamento(tDepartamento *depto, char *c1, char *c2, char *c3, char *nome, int m1, int m2, int m3, char *diretor);

/**
 * @brief Verifica se a média é vaĺida (está entre 0 e 10);
 * 
 * @param media Valor da média a ser verificada;
 * @return int 1 se a média for válida, 0 caso contrário;
 */
int ValidaMediaDepartamento(int media);

/**
 * @brief Calcula o desvio padrão das médias de um curso de um departamento;
 * 
 * @param depto Ponteiro para a estrutura do tipo  "tDepartamento";
 * @return double Valor do cálculo de desvio padrão;
 */
double CalculaDesvioPadraoDepartamento(tDepartamento *depto);

/**
 * @brief Calcula a média simples das notas dos cursos do departamento;
 * 
 * @param depto Ponteiro para a estrutura do tipo "tDepartamento";
 * @return double Valor do cálculo da média simples;
 */
double CalculaMediaGeralDepartamento(tDepartamento *depto);

/**
 * @brief Ordena um vetor de departamentos em ordem decrescente de acordo com as médias dos departamentos;
 * 
 * @param d Vetor de departamentos a ser ordenado;
 * @param tamanho Tamanho a ser ordenado;
 */
void OrdenaPorMediaDepartamentos(tDepartamento *d[], int tamanho);

/**
 * @brief Imprime os dados do departamento (sendo eles: nome do departamento, média por curso e nome do diretor do departamento);
 * 
 * @param depto Ponteiro para a estrutura do tipo "tDepartamento" que terá seus dados impressos;
 */
void ImprimeAtributosDepartamento(tDepartamento *depto);

/**
 * @brief Destroi (libera a memória de um) departamento;
 * 
 * @param depto Ponteiro para uma estrutura do tipo "tDepartamento" que será destruido (terá sua memória desalocada/liberada);
 */
void LiberaMemoriaDepartamento(tDepartamento *depto);

#endif