#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"

#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

tEleicao *InicializaEleicao() {
    int e, p, g;
    tEleicao *eleicao = (tEleicao *)malloc(sizeof(tEleicao));
    tCandidato *candidato = NULL;

    if (eleicao == NULL) {
        printf("Erro na alocacao da eleicao!\n");
        exit(1);
    }

    int qtdCandidatos, c;
    
    // Inicializando dados da estrutura de eleição;
    eleicao->votosBrancosGovernador = 0;
    eleicao->votosBrancosPresidente = 0;
    eleicao->votosNulosGovernador = 0;
    eleicao->votosNulosPresidente = 0;
    eleicao->totalPresidentes = 0;
    eleicao->totalGovernadores = 0;
    eleicao->totalEleitores = 0;

    // Alocando vetor de eleitores e criando (alocando) cada eleitor;
    eleicao->eleitores = (tEleitor**)malloc(MAX_ELEITORES * sizeof(tEleitor*));
    for (e = 0; e < MAX_ELEITORES; e++) {
        eleicao->eleitores[e] = CriaEleitor();
    }

    scanf("%d", &qtdCandidatos);

    // Alocando vetor de candidatos(à presidência) e criando (alocando) cada candidato - levando em conta a possibilidade máxima de preidentes;
    eleicao->presidentes = (tCandidato **)malloc(MAX_CANDIDATOS_POR_CARGO * sizeof(tCandidato*));
    if ((*eleicao).presidentes == NULL) {
        printf("Erro de alocacao no vetor dos presidentes!\n");
        exit(1);
    }
     for (p = 0; p < MAX_CANDIDATOS_POR_CARGO; p++) {
        eleicao->presidentes[p] = CriaCandidato();
    }

    // Alocando vetor de candidatos(à governador) e criando (alocando) cada candidato - levando em conta a possibilidade máxima de governadores;
    eleicao->governadores = (tCandidato **)malloc(MAX_CANDIDATOS_POR_CARGO * sizeof(tCandidato*));
    if ((*eleicao).governadores == NULL) {
        printf("Erro de alocacao no vetor dos governadores!\n");
        exit(1);
    }
     for (g = 0; g < MAX_CANDIDATOS_POR_CARGO; g++) {
        eleicao->governadores[g] = CriaCandidato();
    }
    
    for (c = 0; c < qtdCandidatos; c++) {
        candidato = CriaCandidato();
        LeCandidato(candidato);

        // Verificando para qual cargo cada candidato irá concorrer;    
        if (ObtemCargo(candidato) == 'G') {
            eleicao->governadores[(*eleicao).totalGovernadores] = candidato;
            eleicao->totalGovernadores += 1;
        }else {
            if (ObtemCargo(candidato) == 'P') {
                eleicao->presidentes[(*eleicao).totalPresidentes] = candidato;
                eleicao->totalPresidentes += 1;
            }
        }
        // Desalocando a estrutura auxiliar de candidato;
        ApagaCandidato(candidato);
        //candidato = NULL;
    }
    // Realocando o vetor de candidatos a preidência de acordo com a quantidade lida que concorreram a este cargo;
    eleicao->presidentes = (tCandidato**)realloc((*eleicao).presidentes, (*eleicao).totalPresidentes * sizeof(tCandidato*));
    if ((*eleicao).presidentes == NULL) {
        printf("Erro na realocacao do vetor dos candidatos a presidente!\n");
        exit(1);
    }
    // Realocando o vetor de candidatos a governador de acordo com a quantidade lida que concorreram a este cargo;
    eleicao->governadores = (tCandidato**)realloc((*eleicao).governadores, (*eleicao).totalGovernadores * sizeof(tCandidato*));
    if ((*eleicao).governadores == NULL) {
        printf("Erro na realocacao do vetor dos candidatos a governador!\n");
        exit(1);
    }

    // Se a quantidade de candidatos a uma vaga for excedida, aeleição é anulada (o programa se encerra imediatamente);
    if (((*eleicao).totalGovernadores > MAX_CANDIDATOS_POR_CARGO) || ((*eleicao).totalPresidentes) > MAX_CANDIDATOS_POR_CARGO) {
        //ApagaEleicao(eleicao);
        printf("ELEICAO ANULADA\n");
        exit(1);
    }

    return eleicao;
}

void RealizaEleicao(tEleicao *eleicao) {
    int governadorValido = 0, presidenteValido = 0;
    int e, e1, e2, g, p;

    scanf("%d", &(*eleicao).totalEleitores);

    // Verifica se a quantidade de eleitore é menor ou igual a máxima permitida, se não a eleição é anulada (programa se encerra);
    if ((*eleicao).totalEleitores > MAX_ELEITORES) {
        ApagaEleicao(eleicao);
        printf("ELEICAO ANULADA\n");
        exit(1);
    }

    // Realoca o vetor de eleitores para o tamanho da quantidade lida que irá votar;
    eleicao->eleitores = (tEleitor**)realloc((*eleicao).eleitores, (*eleicao).totalEleitores * sizeof(tEleitor*));
    if ((*eleicao).eleitores == NULL) {
        printf("Erro na alocacao do vetor de eleitores!\n");
        exit(1);
    }

    // Lê os dados de cada eleitor;
    for (e = 0; e < (*eleicao).totalEleitores; e++) {
        LeEleitor((*eleicao).eleitores[e]);
    }

    // Verifica se um mesmo eleitor votou mais de uma vez (caso sim, a eleição é anulada - programa encerrado);
    for (e1 = 0; e1 < ((*eleicao).totalEleitores - 1); e1++) {
        for(e2 = e1 + 1; e2 < (*eleicao).totalEleitores; e2++) {
            if (EhMesmoEleitor((*eleicao).eleitores[e1], (*eleicao).eleitores[e2])) {
                ApagaEleicao(eleicao);
                printf("ELEICAO ANULADA\n");
                exit(1);
            }
        }
    }

    // Contabiliza os votos para cada cargo (votos válidos, brancos e nulos);
    for (e = 0; e < (*eleicao).totalEleitores; e++) {
        // Se  o ID do candidato digitado for igual a 0, o voto é considerado em branco;
        if (ObtemVotoGovernador((*eleicao).eleitores[e]) == 0) {
            eleicao->votosBrancosGovernador += 1;
        }else {
            governadorValido = 0;
            for (g = 0; g < (*eleicao).totalGovernadores; g++) {
                // Se o id do candidato votado não existir, o candidato é anulado;
                if (VerificaIdCandidato((*eleicao).governadores[g], ObtemVotoGovernador((*eleicao).eleitores[e]))) {
                    IncrementaVotoCandidato((*eleicao).governadores[g]);
                    governadorValido = 1;
                    break;
                }
            }
            if (!(governadorValido)) {
                eleicao->votosNulosGovernador += 1;
            }
        }
        // As mesmas condicionais acima usadas para votos a governador, também valem para a eleição a presidência...
        if (ObtemVotoPresidente((*eleicao).eleitores[e]) == 0) {
            eleicao->votosBrancosPresidente += 1;
        }else {
            presidenteValido = 0;
            for (p = 0; p < (*eleicao).totalPresidentes; p++) {
                if (VerificaIdCandidato((*eleicao).presidentes[p], ObtemVotoPresidente((*eleicao).eleitores[e]))) {
                    IncrementaVotoCandidato((*eleicao).presidentes[p]);
                    presidenteValido = 1;
                    break;
                }
            }
            if (!(presidenteValido)) {
                eleicao->votosNulosPresidente += 1;
            }
        }
    }
}

void ImprimeResultadoEleicao(tEleicao *eleicao) {
    int v, totalVotosGov, totalVotosPres;
    int votosValidosGov = 0, votosValidosPres = 0;
    int empateGovernadores = 0, empatePresidentes = 0;
    tCandidato *liderPresidente, *liderGovernador;
    
    // Contabiliza a quantidade de votos válidos para presidência (não brancos e não nulos);
    for (v = 0; v < (*eleicao).totalPresidentes; v++) {
        votosValidosPres += ObtemVotos((*eleicao).presidentes[v]);
    }
    // Contabiliza o total de votos da eleição para presidência;
    totalVotosPres = (*eleicao).votosBrancosPresidente + (*eleicao).votosNulosPresidente + votosValidosPres;
    for (v = 0; v < (*eleicao).totalPresidentes; v++) {
        if (v == 0) {
            // Inicializa o primeiro presidente como na frente;
            liderPresidente = (*eleicao).presidentes[v];
        }else {
            // Verifica se o candidato analizado na vez, recebeu mais votos que o líder da eleição para o cargo;
            if ((ObtemVotos((*eleicao).presidentes[v]) > (*liderPresidente).votos)) {
                liderPresidente = (*eleicao).presidentes[v];
                empatePresidentes = 0;
            }else {
                // Verifica se o candidato analizado na vez, recebeu a mesma quantidade de votos que o líder da eleição para o cargo;
                if (ObtemVotos((*eleicao).presidentes[v]) == (*liderPresidente).votos) {
                    empatePresidentes = 1;
                }
            }
        }
    }
    printf("- PRESIDENTE ELEITO: ");
    // Se o candidato (a presidência) tiver menos votos válidos do que inválidos (brancos e nulos somados), a eleição fica sem decisão;
    if(ObtemVotos(liderPresidente) < ((*eleicao).votosBrancosPresidente + (*eleicao).votosNulosPresidente)) {
        printf("SEM DECISAO\n");
    }else {
        if (empatePresidentes) {
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }else {
            ImprimeCandidato(liderPresidente, CalculaPercentualVotos(liderPresidente, totalVotosPres));
        }
    }

    // Contabiliza a quantidade de votos válidos para governador (não brancos e não nulos);
    for (v = 0; v < (*eleicao).totalGovernadores; v++) {
        votosValidosGov += ObtemVotos((*eleicao).governadores[v]);
    }
    // Contabiliza o total de votos da eleição para governador;
    totalVotosGov = (*eleicao).votosBrancosGovernador + (*eleicao).votosNulosGovernador + votosValidosGov;
    for (v = 0; v < (*eleicao).totalGovernadores; v++) {
        if (v == 0) {
            // Inicializa o primeiro governador como na frente;
            liderGovernador = (*eleicao).governadores[v];
        }else {
            // Verifica se o candidato analizado na vez, recebeu mais votos que o líder da eleição para o cargo;
            if ((ObtemVotos((*eleicao).governadores[v]) > (*liderGovernador).votos)) {
                liderGovernador = (*eleicao).governadores[v];
                empateGovernadores = 0;
            }else {
                // Verifica se o candidato analizado na vez, recebeu a mesma quantidade de votos que o líder da eleição para o cargo;
                if (ObtemVotos((*eleicao).governadores[v]) == (*liderGovernador).votos) {
                    empateGovernadores = 1;
                }
            }
        }
    }
    printf("- GOVERNADOR ELEITO: ");
    // Se o candidato (a governador) tiver menos votos válidos do que inválidos (brancos e nulos somados), a eleição fica sem decisão;
    if(ObtemVotos(liderGovernador) < ((*eleicao).votosBrancosGovernador + (*eleicao).votosNulosGovernador)) {
        printf("SEM DECISAO\n");
    }else {
        if (empateGovernadores) {
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }else {
            ImprimeCandidato(liderGovernador, CalculaPercentualVotos(liderGovernador, totalVotosGov));
        }
    }
    printf("- NULOS E BRANCOS: %d, %d", ((*eleicao).votosNulosGovernador + (*eleicao).votosNulosPresidente), ((*eleicao).votosBrancosGovernador + (*eleicao).votosBrancosPresidente));
}

void ApagaEleicao(tEleicao *eleicao) {
    int g, p, e;
    
    // Apaga (desaloca a memória) de cada candidato a governador;
    for (g = 0; g < (*eleicao).totalGovernadores; g++) {
        ApagaCandidato((*eleicao).governadores[g]);
    }
    // Apaga (desaloca a memória) de cada candidato a presidente;
    for (p = 0; p < (*eleicao).totalPresidentes; p++) {
        ApagaCandidato((*eleicao).presidentes[p]);
    }
    // Apaga (desaloca a memória) de cada eleitor;
    for (e = 0; e < (*eleicao).totalEleitores; e++) {
        ApagaEleitor((*eleicao).eleitores[e]);
    }
    //desaloca o veror de governadores;
    free((*eleicao).governadores);
    //desaloca o veror de presidentes;
    free((*eleicao).presidentes);
    //desaloca o veror de eleitores;
    free((*eleicao).eleitores);
    //desaloca a eleição;
    free(eleicao);
}