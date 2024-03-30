#ifndef _ELEICAO_H_
#define _ELEICAO_H_

#include "candidato.h"
#include "eleitor.h"

// #define MAX_CANDIDATOS_POR_CARGO 3
// #define MAX_ELEITORES 10


typedef struct {
    tCandidato **presidentes;
    int totalPresidentes;
    tCandidato **governadores;
    int totalGovernadores;
    int votosBrancosPresidente;
    int votosNulosPresidente;
    int votosBrancosGovernador;
    int votosNulosGovernador;
    tEleitor **eleitores;
    int totaleleitores;
}tEleicao;

/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda Nessa função, é lido a quantidade de candidatos, os cadidatos são lidos e armazenados.
 * A memória necessária para os vetores dos "presidentes" e dos "governadores" deve ser alocada nesta função.
 * Por fim, os demais ponteiros devem ser inicializados com NULL;
 * 
 * @return tEleicao* Eleicao inicializada;
 */
tEleicao *InicializaEleicao();

/**
 * @brief Apaga e desaloca os dados da eleição;
 * 
 * @param eleicao Ponteiro para a eleição;
 */
void ApagaEleicao(tEleicao *eleicao);

/**
 * @brief Realiza uma eleição;
 * Nessa função, é lida a quantidade de eleitores, sendo que estes tem os seus dados lidos e armazenados;
 * 
 * @param eleicao Ponteiro para a eleição a ser realizada;
 */
void RealizaEleicao(tEleicao *eleicao);

/**
 * @brief Imprime o resultado da eleição na tela à partir da apuração dos votos;
 * 
 * @param eleicao Eleição a ser impressa;
 */
void ImprimeResultadoEleicao(tEleicao *eleicao);

#endif