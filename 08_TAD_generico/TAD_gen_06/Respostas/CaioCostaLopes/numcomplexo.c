#include <stdio.h>
#include <stdlib.h>
#include "numcomplexo.h"

struct complexo {
    float parteReal;
    float parteImaginaria;
};

tNumComplexo *CriaNumComplexo(float real, float imag) {
    tNumComplexo *numeroComplexo = (tNumComplexo*)malloc(sizeof(tNumComplexo));
    if (numeroComplexo == NULL) {
        printf("Erro na alocacao de memoria do numero complexo!\n");
        exit(1);
    }

    numeroComplexo->parteReal = real;
    numeroComplexo->parteImaginaria = imag;

    return numeroComplexo;
}

float PegaParteImagComplexo(tNumComplexo *cplx) {
    return (*cplx).parteImaginaria;
}

float PegaParteRealComplexo(tNumComplexo *cplx) {
    return (*cplx).parteReal;
}

int RetornaNumBytesComplexo() {
    return sizeof(tNumComplexo);
}

tNumComplexo *SomaComplexos(tNumComplexo* n1, tNumComplexo *n2) {
    return (CriaNumComplexo((PegaParteRealComplexo(n1) + PegaParteRealComplexo(n2)), (PegaParteImagComplexo(n1) + PegaParteImagComplexo(n2))));
}

tNumComplexo *MultComplexos(tNumComplexo* n1, tNumComplexo* n2) {
    return (CriaNumComplexo(((PegaParteRealComplexo(n1) * PegaParteRealComplexo(n2)) - (PegaParteImagComplexo(n1) * PegaParteImagComplexo(n2))), 
                            ((PegaParteRealComplexo(n1) * PegaParteImagComplexo(n2)) + (PegaParteRealComplexo(n2) *PegaParteImagComplexo(n1)))));
}

void ImprimeNumeroComplexo(tNumComplexo *cplx) {
    printf ("%.2f + i%.2f", PegaParteRealComplexo(cplx), PegaParteImagComplexo(cplx));
}

void DestroiNumeroComplexo(tNumComplexo *cplx) {
    if (cplx != NULL) {
        free(cplx);
        cplx = NULL;
    }
}