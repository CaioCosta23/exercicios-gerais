#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrizgenerica.h"
#include "numcomplexo.h"

struct matrizgenerica {
    int linhas;
    int colunas;
    int numeroBytes;
    void *elementos;
};

tMatrizGenerica *CriaMatrizGenerica(int linhas, int colunas, int numByteElem) {
    tMatrizGenerica *matrizGenerica = (tMatrizGenerica*)malloc(sizeof(tMatrizGenerica));

    if (matrizGenerica == NULL) {
        printf("Erro na alocacao de memoria da matriz generica!\n");
        exit(1);
    }

    matrizGenerica->linhas = linhas;
    matrizGenerica->colunas = colunas;
    matrizGenerica->numeroBytes = numByteElem;

    matrizGenerica->elementos = (void*)malloc(((*matrizGenerica).linhas * (*matrizGenerica).colunas) * numByteElem);
    if ((*matrizGenerica).elementos == NULL) {
        printf("Erro na alocacao de memória das linhas (vetor de vetores) da matriz generica!\n");
        DestroiMatrizGenerica(matrizGenerica);
        exit(1);
    }
    return matrizGenerica;
}

int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica *mat) {
    return (*mat).linhas;
}

int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica *mat) {
    return (*mat).colunas;
}

void *ObtemElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna) {
    // Cácula a posição correta de um elemento na matriz genérica usando "aritimética de ponteiros";
    return ((*mat).elementos + (linha * ((*mat).colunas * (*mat).numeroBytes)) + coluna * (*mat).numeroBytes);
}

void AtribuiElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna, void *elem) {
    void *elementoMatriz;

    elementoMatriz = ObtemElementoMatrizGenerica(mat, linha, coluna);
    // Esta função é usada para copiar uma quantidade específica de bytes de uma área de memória para outra;
    memcpy(elementoMatriz, elem, (*mat).numeroBytes);
}

tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat) {
    tMatrizGenerica *matrizTransposta;
    int l, c;

    matrizTransposta = CriaMatrizGenerica((*mat).colunas, (*mat).linhas, (*mat).numeroBytes);
    
    for (l = 0; l < ObtemNumeroLinhasMatrizGenerica(mat); l++) {
        for (c = 0; c < ObtemNumeroColunasMatrizGenerica(mat); c++) {
            AtribuiElementoMatrizGenerica(matrizTransposta, c, l, ObtemElementoMatrizGenerica(mat, l, c));
        }
    }
    return matrizTransposta;
}

tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1, tMatrizGenerica *mat2, int numByteTarget, void* (*multi_elem)(void*, void*), void* (*soma_elem)(void*,void*)) {
    if (ObtemNumeroColunasMatrizGenerica(mat1) != ObtemNumeroLinhasMatrizGenerica(mat2)) {
        return NULL;
    }
    tMatrizGenerica *matrizResultante;
    int l = 0;
    int c1, c2;
    void *elementoResultante, *produto, *soma;
    
    matrizResultante = CriaMatrizGenerica(ObtemNumeroLinhasMatrizGenerica(mat1), ObtemNumeroColunasMatrizGenerica(mat2), numByteTarget);
    
    while (l < ObtemNumeroLinhasMatrizGenerica(mat1)) {
        c2 = 0;

        while(c2 < ObtemNumeroColunasMatrizGenerica(mat2)) {
            c1 = 0;

            /* Por ser um matriz de elementos genéricos, faz diferença alocar com "calloc" 
             * para que o elemento resultante seja inicializado com 0;
            */
            elementoResultante = (void*)calloc(1, numByteTarget);
            if (elementoResultante == NULL) {
                printf("Erro na alocacao de memoria do elemento resultante da multiplicacao de matrizaes\n");
                DestroiMatrizGenerica(matrizResultante);
                return NULL;
            }

            while (c1 < ObtemNumeroColunasMatrizGenerica(mat1)) {
                produto = multi_elem(ObtemElementoMatrizGenerica(mat1, l, c1), ObtemElementoMatrizGenerica(mat2, c1, c2));
                soma = soma_elem(elementoResultante, produto);

                memcpy(elementoResultante, soma, numByteTarget);

                free(produto);
                free(soma);

                c1++;
            }
            AtribuiElementoMatrizGenerica(matrizResultante, l, c2, elementoResultante);

            free(elementoResultante);

            c2++;
        }
        l++;
    }
    return matrizResultante;
}

tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem, void* (*converte_elem)(void*)) {
    tMatrizGenerica *matrizConvertida;
    int l, c;
    void *copiaElemento;
    
    matrizConvertida = CriaMatrizGenerica(ObtemNumeroLinhasMatrizGenerica(mat2), ObtemNumeroColunasMatrizGenerica(mat2), novoNumByteElem);

    for (l = 0; l < ObtemNumeroLinhasMatrizGenerica(mat2); l++) {
        for (c = 0; c < ObtemNumeroColunasMatrizGenerica(mat2); c++) {
            copiaElemento = converte_elem(ObtemElementoMatrizGenerica(mat2, l, c));
            AtribuiElementoMatrizGenerica(matrizConvertida, l, c, copiaElemento);
            free(copiaElemento);
        }
    }
    return matrizConvertida;
}

void ImprimirMatrizGenerica(tMatrizGenerica *mat, void (imprime_elemento(void*))) {
    int l, c;

    for (l = 0; l < ObtemNumeroLinhasMatrizGenerica(mat); l++) {
        for (c = 0; c < ObtemNumeroColunasMatrizGenerica(mat); c++) {
            imprime_elemento(ObtemElementoMatrizGenerica(mat, l, c));

            if (c < ObtemNumeroColunasMatrizGenerica(mat) - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void DestroiMatrizGenerica(tMatrizGenerica *mat) {
    if (mat != NULL) {
        if ((*mat).elementos != NULL) {
            free((*mat).elementos);
            mat->elementos = NULL;
        }
        free(mat);
        mat = NULL;
    }
}