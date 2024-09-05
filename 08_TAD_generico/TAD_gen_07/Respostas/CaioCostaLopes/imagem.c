#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

struct tImagem {
    int altura;
    int largura;
    Tipo tipo;
    void *dados;
};

Imagem *CriarImagem(int altura, int largura, Tipo tipo) {
    Imagem *imagem = (Imagem*)malloc(sizeof(Imagem));
    int numeroBytesTipo;

    if (imagem == NULL) {
        printf("Erro na alocacao de memoria da imagem!\n");
        exit(1);
    }

    imagem->altura = altura;
    imagem->largura = largura;
    imagem->tipo = tipo;

    if (tipo == INT) {
        numeroBytesTipo = sizeof(int);
    }else {
        if (tipo == FLOAT) {
            numeroBytesTipo = sizeof(float);
        }
    }

    imagem->dados = (void*)malloc(((*imagem).altura * (*imagem).largura) * numeroBytesTipo);
    if ((*imagem).dados == NULL) {
        printf("Erro na alocacao de memoria dos dados da imagem!\n");
        DestruirImagem(imagem);
        exit(1);
    }

    return imagem;
}

Imagem *LerImagem() {
    Imagem *imagem;
    int altura, largura, tipo, p;

    scanf("%d %d %d\n", &altura, &largura, &tipo);

    if (tipo == INT) {
        imagem = CriarImagem(altura, largura, INT);
        for (p = 0; p < (altura * largura); p++) {
            scanf("%d", &((int*)imagem->dados)[p]);
        }
    }else {
        if (tipo == FLOAT) {
            imagem = CriarImagem(altura, largura, FLOAT);
            for (p = 0; p < (altura * largura); p++) {
                scanf("%f", &((float*)imagem->dados)[p]);
            }
        }
    }
    return imagem;
}

int ObterAltura(Imagem *img) {
    return (*img).altura;
}

int ObterLargura(Imagem *img) {
    return (*img).largura;
}


Tipo ObterTipoImagem(Imagem *img) {
    return (*img).tipo;
}


void *ObterDadosImagem(Imagem *img) {
    return (*img).dados;
}

void ImprimirImagem(Imagem *img) {
    // Função "inútil";
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