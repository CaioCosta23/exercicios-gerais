#ifndef _HISTOGRAMA_H
#define _HISTOGRAMA_H

#include "imagem.h"

typedef struct tHistograma Histograma;

/**
 * @brief Cria (aloca a memória dinamicamente de) um histograma (que irá calcular uma imagem);
 * 
 * @param img Ponteiro para a estrutura do tipo "Imagem" que contém os dados da imagem;
 * @param nIntervalos Número de intervalos no histograma;
 * @return Ponteiro para a estrutura do tipo "Histograma" que contém os campos de dados inicializados do histograma calculado;
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos);

/**
 * @brief Imprime um histograma na tela.
 * 
 * @param histograma Ponteiro para a estrutura do tipo "Histograma" que contém os dados atualizados do histograma;
 */
void MostrarHistograma(Histograma *histograma);

/**
 * @brief Destrói (desaloca a memória alocada dinamicamente de) um histograma;
 * 
 * @param histograma Ponteiro para a estrutura do tipo "Histograma" que contém os dados atualizados do histograma (que será destruído);
 */
void DestruirHistograma(Histograma *histograma);

#endif