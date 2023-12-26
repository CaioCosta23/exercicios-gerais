#ifndef _ELEICAO_H_
#define _ELEICAO_H_

#include "candidato.h"
#include "eleitor.h"

#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

typedef struct {
    tCandidato presidentes[MAX_CANDIDATOS_POR_CARGO];
    tCandidato governadores[MAX_CANDIDATOS_POR_CARGO];
    int totalPresidentes;
    int totalGovernadores;
    int votosBrancosPresidente;
    int votosBrancosGovernador;
    int votosNulosPresidente;
    int votosNulosGovernador;
    tEleitor eleitores[MAX_ELEITORES];
}tEleicao;

/**
 * @brief Inicializa a eleição com valores padronizados (zerando os votos inváidos). É nessa função que é contabilizado
 * a quantidade de candidatos e são lidos e armazenados os seus dados;
 * 
 * @return tEleicao Eleição inicializada;
 */
tEleicao InicializaEleicao();

/**
 * @brief Realiza a eleição. Nessa função são lidos a quantidade de eleitores e a suas informações, nas quais também são armazenadas;
 * 
 * @param eleicao Eleição a ser realizada (já iniciada);
 * @return tEleicao eleição concluida;
 */
tEleicao RealizaEleicao(tEleicao eleicao);

/**
 * @brief Imprime a eleição (seus resultados finais);
 * 
 * @param eleicao Eleicao (dados, informações e resultados) à ser impressa;
 */
void ImprimeResultadosEleicao(tEleicao eleicao);
#endif