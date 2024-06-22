#include <stdio.h>
#include <stdlib.h>
#include "duelo.h"

tDuelo LeDuelo() {
    tDuelo duelo = (tDuelo)malloc(sizeof(struct duelo));

    if (duelo == NULL) {
        printf("Erro na alocacao de memoria do duelo ");
        return duelo;
    }
    
    duelo->id = -1;
    duelo->c1 = -1;
    duelo->c2 = -1;
    duelo->atributo = '\0';
    duelo->desempate = false;
    duelo->vencedor = -1;
    duelo->diferenca = 0;

    scanf("%d\n", &duelo->id);
    scanf("%d %d %c\n", &duelo->c1, &duelo->c2, &duelo->atributo);

    return duelo;
}

void RealizaDuelo(tDuelo d, tCarta c1, tCarta c2) {
    c1->num_duelos += 1;
    c2->num_duelos += 1;

    if ((*d).atributo == MAGIA) {
        if (ComparaMagiaCarta(c1, c2) > 0) {
            d->vencedor = GetC1Duelo(d);
            c1->num_vit = AdicionaVitoriaCarta(c1);
            d->diferenca = ComparaMagiaCarta(c1, c2);
        }else {
            if (ComparaMagiaCarta(c1, c2) < 0) {
                d->vencedor = GetC2Duelo(d);
                d->diferenca = (ComparaMagiaCarta(c1, c2) * (-1));
                c2->num_vit = AdicionaVitoriaCarta(c2);
            }else {
                d->desempate = true;
                d->diferenca = 0;
                if (ComparaIdCarta(c1, c2) < 0) {
                    d->vencedor = GetC1Duelo(d);
                    c1->num_vit = AdicionaVitoriaCarta(c1);
                }else {
                    if (ComparaIdCarta(c1, c2) > 0) {
                        d->vencedor = GetC2Duelo(d);
                        c2->num_vit = AdicionaVitoriaCarta(c2);
                    }
                }
            }
        }
    }else {
        if ((*d).atributo == FORCA) {
            if (ComparaAtaqueCarta(c1, c2) > 0) {
                d->vencedor = GetC1Duelo(d);
                d->diferenca = ComparaAtaqueCarta(c1, c2);
                c1->num_vit = AdicionaVitoriaCarta(c1);
            }else {
                if (ComparaAtaqueCarta(c1, c2) < 0) {
                    d->vencedor = GetC2Duelo(d);
                    d->diferenca = (ComparaAtaqueCarta(c1, c2) * (-1));
                    c2->num_vit = AdicionaVitoriaCarta(c2);
                }else {
                    d->desempate = true;
                    d->diferenca = 0;
                    if (ComparaIdCarta(c1, c2) < 0) {
                        d->vencedor = GetC1Duelo(d);
                        c1->num_vit = AdicionaVitoriaCarta(c1);
                    }else {
                        if (ComparaIdCarta(c1, c2) > 0) {
                            d->vencedor = GetC2Duelo(d);
                            c2->num_vit = AdicionaVitoriaCarta(c2);
                        }
                    }
                }
            }
        }else {
            if ((*d).atributo == FOGO) {
                if (ComparaFogoCarta(c1, c2) > 0) {
                    d->vencedor = GetC1Duelo(d);
                    d->diferenca = ComparaFogoCarta(c1, c2);
                    c1->num_vit = AdicionaVitoriaCarta(c1);
                }else {
                    if (ComparaFogoCarta < 0) {
                        d->vencedor = GetC2Duelo(d);
                        d->diferenca = (ComparaFogoCarta(c1, c2) * (-1));
                        c2->num_vit = AdicionaVitoriaCarta(c2);
                    }else {
                        d->desempate = true;
                        d->diferenca = 0;
                        if (ComparaIdCarta(c1, c2) < 0) {
                            d->vencedor = GetC1Duelo(d);
                            c1->num_vit = AdicionaVitoriaCarta(c1);
                        }else {
                            if (ComparaIdCarta(c1, c2) > 0) {
                                d->vencedor = GetC2Duelo(d);
                                c2->num_vit = AdicionaVitoriaCarta(c2);
                            }
                        }
                    }
                }
            }
        }
    }
}

int GetC1Duelo(tDuelo d) {
    return (*d).c1;
}

int GetC2Duelo(tDuelo d) {
    return (*d).c2;
}

bool GetDesempateDuelo (tDuelo d) {
    return (*d).desempate;
}

int GetDiferencaDuelo(tDuelo d) {
    return (*d).diferenca;
}

int GetIdDuelo(tDuelo d) {
    return (*d).id;
}

void ImprimeDuelo(tDuelo d) {
    // Função inútil (Apenas para testes);
    
    /*
    printf("\nID da Luta: %d\n", (*d).id);
    printf("ID da Carta 1: %d\n", (*d).c1);
    printf("ID da Carta 2: %d\n", (*d).c2);
    printf("ID do vencedor: %d\n", (*d).vencedor);
    printf("Diferenca da Luta: %d\n", (*d).diferenca);
    printf("Atributo da luta: %c\n\n", (*d).atributo);
    */
}

void LiberaDuelo(tDuelo d) {
    if (d != NULL) {
        free(d);
        d = NULL;
    }
}