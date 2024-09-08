#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define MAX_CARACTERES 100

struct aluno {
    char nome[MAX_CARACTERES];
    char dataNascimento[MAX_CARACTERES];
    char cursoUfes[MAX_CARACTERES];
    char periodoIngresso[MAX_CARACTERES];
    int percentualDeConclusao;
    float cra;
    int tamanhoBytesEstrutura;
};

Aluno **CriaVetorAlunos(int numeroAlunos) {
    Aluno **alunos = (Aluno**)calloc(numeroAlunos, sizeof(Aluno*));

    if (alunos == NULL) {
        printf("Erro na alocacao de memoria do vetor de alunos!\n");
        exit(1);
    }
    return alunos;
}

Aluno *CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char *periodoIngresso, int percConclusao, float CRA) {
    Aluno *aluno = (Aluno*)calloc(1, sizeof(Aluno));

    if (aluno == NULL) {
        printf("Erro na alocacao de memoria do aluno!\n");
        exit(1);
    }

    strcpy(aluno->nome, nome);
    strcpy(aluno->dataNascimento, dtNasc);
    strcpy(aluno->cursoUfes, cursoUfes);
    strcpy(aluno->periodoIngresso, periodoIngresso);
    aluno->percentualDeConclusao = percConclusao;
    aluno->cra = CRA;

    aluno->tamanhoBytesEstrutura = (sizeof(char) * (strlen(nome) + 1)) + (sizeof(char) * (strlen(dtNasc) + 1)) + 
                                   (sizeof(char) * (strlen(cursoUfes) + 1)) + (sizeof(char) * (strlen(periodoIngresso) + 1)) +
                                    sizeof(int) + sizeof(float);

    return aluno;
}

void LeAlunos(Aluno **vetorAlunos, int numeroAlunos) {
    int a, percentualDeConclusao;
    char nome[MAX_CARACTERES] = {0}, dataNascimento[MAX_CARACTERES] = {0}, cursoUfes[MAX_CARACTERES] = {0}, 
         periodoIngresso[MAX_CARACTERES] ={0};
    float cra;
    char caractereLixo;
    
    scanf("%*c");

    for (a = 0; a < numeroAlunos; a++) {
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", dataNascimento);
        scanf("%[^\n]\n", cursoUfes);
        scanf("%[^\n]\n", periodoIngresso);
        scanf("%d\n", &percentualDeConclusao);
        scanf("%f", &cra);

        scanf("%c", &caractereLixo);

        vetorAlunos[a] = CriaAluno(nome, dataNascimento, cursoUfes, periodoIngresso, percentualDeConclusao, cra);     
    }
}

void LiberaAlunos(Aluno **alunos, int numeroAlunos) {
    int a;

    if (alunos != NULL) {
        for (a = 0; a < numeroAlunos; a++) {
            if (alunos[a] != NULL) {
                free(alunos[a]);
                alunos[a] = NULL;
            }
        }
        free(alunos);
        alunos = NULL;
    }
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos) {
    FILE *arquivo;
    int a, numeroBytes = 0;

    arquivo = fopen(fileName, "wb");

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo de escrita!\n");
        exit(1);
    }

    numeroBytes += sizeof(int);
    numeroBytes += sizeof(Aluno*) * numeroAlunos;

    fwrite(&numeroAlunos, sizeof(int), 1, arquivo);
    for (a = 0; a < numeroAlunos; a++) {
        numeroBytes += alunos[a]->tamanhoBytesEstrutura;
        fwrite(alunos[a], sizeof(Aluno), 1, arquivo);
    }
    
    numeroBytes += sizeof(Aluno**);

    printf("Numero de bytes salvos: %d\n", numeroBytes);

    fclose(arquivo);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName) {
    FILE *arquivo;
    int a, numeroAlunos;
    Aluno *aluno = NULL;

    arquivo = fopen(fileName, "rb");

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo de leitura!\n");
        exit(1);
    }

    fread(&numeroAlunos, sizeof(int), 1, arquivo);
    for (a = 0; a < numeroAlunos; a++) {
        aluno = (Aluno*)calloc(1, sizeof(Aluno));
        if (aluno == NULL) {
            printf("Erro na alocacao de memoria do aluno %d do arquivo!\n", a);
            break;
        }
        fread(aluno, sizeof(Aluno), 1, arquivo);
        alunos[a] = aluno;
    }

    fclose(arquivo);
}


void ImprimeAlunos(Aluno **alunos, int numeroAlunos) {
    int a;

    for (a = 0; a < numeroAlunos; a++) {
        printf("Aluno %d\n", a);
        printf("Nome: %s\n", alunos[a]->nome);
        printf("Data Nascimento: %s\n", alunos[a]->dataNascimento);
        printf("Curso: %s\n", alunos[a]->cursoUfes);
        printf("Periodo Ingresso: %s\n", alunos[a]->periodoIngresso);
        printf("%% Conclusao do Curso: %d\n", alunos[a]->percentualDeConclusao);
        printf("CRA: %.2f\n", alunos[a]->cra);
    }
}