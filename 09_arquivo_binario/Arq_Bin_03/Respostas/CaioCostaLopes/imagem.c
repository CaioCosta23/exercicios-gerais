#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

struct tImagem{
    int linhas;
    int colunas;
    int bytes;
    Tipo tipo;
    void *dados;
};

Imagem *LerImagem(const char *caminho) {
    Imagem *imagem = (Imagem*)malloc(sizeof(Imagem));

    if (imagem == NULL) {
        printf("Erro na alocacao de memoria da imagem!\n");
        exit(1);
    }

    imagem->bytes = 0;

    FILE *arquivo;

    arquivo = fopen(caminho, "rb");
    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo que contém os dados da imagem");
        DestruirImagem(imagem);
        exit(1);
    }

    int tipo, bytesTipo, d;

    imagem->bytes += fread(&imagem->linhas, sizeof(int), 1, arquivo) * sizeof(int);
    imagem->bytes += fread(&imagem->colunas, sizeof(int), 1, arquivo) * sizeof(int);

    fread(&tipo, sizeof(int), 1, arquivo);

    if (tipo == INT) {
        imagem->tipo = INT;
        bytesTipo = sizeof(int);
        imagem->bytes += sizeof(int);
    }else {
        if (tipo == FLOAT) {
            imagem->tipo = FLOAT;
            bytesTipo = sizeof(float);
            imagem->bytes += sizeof(float);
        }
    }

    imagem->dados = (void*)calloc(((*imagem).linhas * (*imagem).colunas), bytesTipo);
    if ((*imagem).dados == NULL) {
        printf("Erro na alocacao de memoria dos dados da imagem!\n");
        DestruirImagem(imagem);
        fclose(arquivo);
        exit(1);
    }
    
    for (d = 0; d < ((*imagem).linhas * (*imagem).colunas); d++) {
        if ((*imagem).tipo == INT) {
            fread(&((int*)imagem->dados)[d], bytesTipo, 1, arquivo);
        }else {
            if ((*imagem).tipo == FLOAT) {
                fread(&((float*)imagem->dados)[d], bytesTipo, 1, arquivo);
            }
        }
    }
    fclose(arquivo);

    return imagem;
}

int ObterNumeroBytesLidos(Imagem *img) {
    return (*img).bytes;
}

void ImprimirImagem(Imagem *img) {
    int d;
    int quebraLinha = 0;

    for (d = 0; d < ((*img).linhas * (*img).colunas); d++) {
        if ((*img).tipo == INT) {
            printf("%d ", ((int*)(*img).dados)[d]);
        }else {
            if ((*img).tipo == FLOAT) {
                printf("%.2f ", ((float*)(*img).dados)[d]);
            }
        }
        if (quebraLinha == ((*img).linhas - 1)) {
            printf("\n");
            quebraLinha = 0;
        }else {
            quebraLinha += 1;
        }
    }
}

void DestruirImagem(Imagem *img) {
    if (img != NULL) {
        if ((*img).dados != NULL) {
            free((*img).dados);
            img->dados = NULL;
        }
        free(img);
        img = NULL;
    }
}