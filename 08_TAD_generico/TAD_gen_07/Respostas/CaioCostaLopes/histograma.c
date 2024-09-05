#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "histograma.h"

#define INICIO_INTERVALO_INT 0
#define FIM_INTERVALO_INT 255
#define INICIO_INTERVALO_FLOAT 0.0
#define FIM_INTERVALO_FLOAT 1.0

struct tHistograma {
    int *numeroPixels;
    int numeroIntervalos;
    int tamanhoIntervalos;
};

Histograma *CalcularHistograma(Imagem *img, int numIntervalos) {
    Histograma *histograma = (Histograma*)malloc(sizeof(Histograma));
    int i, p, somaPixels, inicioIntervalo, fimIntervalo;
    
    if (histograma == NULL) {
        printf("Erro na alocacao de memoria do histograma!\n");
        exit(1);
    }
    histograma->numeroIntervalos = numIntervalos;

    histograma->numeroPixels = (int*)calloc((*histograma).numeroIntervalos, sizeof(int));

    if ((*histograma).numeroPixels == NULL) {
        printf("Erro na alocacao de memoria no número de pixels do histograma!\n");
        DestruirHistograma(histograma);
        exit(1);
    }

    histograma->tamanhoIntervalos = (int)ceil((double)(FIM_INTERVALO_INT + 1) / (double)(*histograma).numeroIntervalos);

    inicioIntervalo = INICIO_INTERVALO_INT;
    fimIntervalo = (*histograma).tamanhoIntervalos;

    for (i = 0; i < (*histograma).numeroIntervalos; i++) {
        somaPixels = 0;
        for (p = 0; p < (ObterAltura(img) * ObterLargura(img)); p++) {
            if (ObterTipoImagem(img) == INT) {
                int *dados = (int*)ObterDadosImagem(img);
                if ((dados[p] >= inicioIntervalo) && (dados[p] < fimIntervalo)) {
                    somaPixels++;
                }
            }else {
                if (ObterTipoImagem(img) == FLOAT) {
                    float *dados = (float*)ObterDadosImagem(img);
                    if (((int)(dados[p] * FIM_INTERVALO_INT) >= inicioIntervalo) && ((int)(dados[p] * FIM_INTERVALO_INT) < fimIntervalo)) {
                        somaPixels++;
                    }
                }
            }
        }
        histograma->numeroPixels[i] = somaPixels;
        inicioIntervalo += (*histograma).tamanhoIntervalos;
        fimIntervalo += (*histograma).tamanhoIntervalos;
    }

    return histograma;
}

void MostrarHistograma(Histograma *histograma) {
    int i;
    int intervalo = 0;

    for (i = 0; i < (*histograma).numeroIntervalos; i++) {
        printf("[%d, %d): %d\n", intervalo, intervalo + (*histograma).tamanhoIntervalos, (*histograma).numeroPixels[i]);
        intervalo += (histograma->tamanhoIntervalos);
    }

}

void DestruirHistograma(Histograma *histograma) {
    if (histograma != NULL) {
        if ((*histograma).numeroPixels != NULL) {
            free((*histograma).numeroPixels);
            histograma->numeroPixels = NULL;
        }
        free(histograma);
        histograma = NULL;
    }
}