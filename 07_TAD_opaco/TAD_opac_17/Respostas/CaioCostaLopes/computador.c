#include <stdio.h>
#include <stdlib.h>
#include "computador.h"

#define MAX_PARTIDAS 5
#define MIN_INTERVALO 1
#define MAX_INTERVALO 10000
#define MAX_NATURAL 1000000000

struct Computador {
    tJogo **partidas;
    int qtdPartidas;
    int maxPartidas;
    int qtdVitorias;
    int qtdDerrotas;
};

tComputador *CriaComputador() {
    tComputador *computador = (tComputador*)malloc(sizeof(tComputador));

    if (computador == NULL) {
        printf("Erro na alocacao de memoria do computador do jogo!\n");
        exit(1);
    }

    computador->partidas = (tJogo**)malloc(MAX_PARTIDAS * sizeof(tJogo*));
    if ((*computador).partidas == NULL) {
        printf("Erro na alocacao de memoria do vetor de partidas (jogos) do computador!\n");
        DestroiComputador(computador);
        exit(1);
    }

    computador->qtdPartidas = 0;
    computador->maxPartidas = MAX_PARTIDAS;
    computador->qtdVitorias = 0;
    computador->qtdDerrotas = 0;

    return computador;
}

void GerenciaJogo(tComputador *computador) {
    tJogo *jogo;
    int n, min, max;
    char resposta;

    printf("Jogo de adivinhação");
    
    while (1) {
        jogo = CriaJogo();
        if (jogo == NULL) {
            printf("%d", ((*computador).qtdPartidas + 1));
            DestroiComputador(computador);
            exit(1);
        }
        do {
            printf("\nForneca um numero no intervalo entre 1 e 10000: ");
            scanf("%d\n", &n);
        }while((n < MIN_INTERVALO) || (n > MAX_INTERVALO));

        while(1) {
            printf("\nForneca um intervalo de numeros naturais: ");
            scanf("%d %d\n", &min, &max);

            if ((min < max) && (max < MAX_NATURAL)) {
                break;
            }else {
                if (min >= max) {
                    printf("\nO primeiro numero do intervalo deve ser inferior ao segundo");
                }
                if (max >= MAX_NATURAL) {
                    printf("\nO segundo numero do intervalo deve ser menor que 1.000.000.000");
                }
            }
        }
        DefineMinimo(jogo, min);
        DefineMaximo(jogo, max);
        CalculaNumeroTentativas(jogo);

        CalculaValorASerAdivinhado(jogo, n);
        
        computador->partidas[(*computador).qtdPartidas] = jogo;
        computador->qtdPartidas += 1;

        if (ProcessaTentativas(jogo)) {
            computador->qtdVitorias += 1;
        }else {
            computador->qtdDerrotas += 1;
        }

        while(1) {
            printf("\nDeseja continuar a jogar (s/n): ");
            scanf("\n%c\n", &resposta);

            if (resposta == 's' || (resposta == 'n')) {
                break;
            }
            printf("\nVoce deve digitar s ou n!");
        }

        if (resposta == 'n') {
            break;
        }

        if ((*computador).qtdPartidas == (*computador).maxPartidas) {
            computador->maxPartidas += MAX_PARTIDAS;
            computador->partidas = (tJogo**)realloc((*computador).partidas, (*computador).maxPartidas * sizeof(tJogo*));
            if ((*computador).partidas == NULL) {
                printf("\nErro na realocacao de memoria no vetor/lista de partidas(jogos) do computador!\n");
                DestroiComputador(computador);
                exit(1);
            }
        }
    }
}

void ImprimeRelatorio(tComputador *computador) {
    printf("\nObrigado por jogar comigo. Desta vez, voce jogou %d jogo(s), ganhou %d jogo(s) e perdeu %d jogo(s). Ate a proxima!\n",
            (*computador).qtdPartidas, (*computador).qtdVitorias, (*computador).qtdDerrotas);

}

void DestroiComputador(tComputador *computador) {
    int p;

    if (computador != NULL) {
        if ((*computador).partidas != NULL) {
            for (p = 0; p < (*computador).qtdPartidas; p++) {
                DestroiJogo((*computador).partidas[p]);
            }
            free((*computador).partidas);
            computador->partidas = NULL;
        }
        free(computador);
        computador = NULL;
    }
}