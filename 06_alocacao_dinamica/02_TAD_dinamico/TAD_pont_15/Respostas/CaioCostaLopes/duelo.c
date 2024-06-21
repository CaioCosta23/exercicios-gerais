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
            c1->num_vit = AdicionaVitoriaCarta(c1);
            d->vencedor = GetIdCarta(c1);
        }else {
            if (ComparaMagiaCarta(c1, c2) < 0) {
                c2->num_vit = AdicionaVitoriaCarta(c2);
                d->vencedor = GetIdCarta(c2);
            }else {
                if (ComparaMagiaCarta(c1, c2) == 0) {
                    d->desempate = true;
                    if (ComparaIdCarta(c1, c2) < 0) {
                        c1->num_vit = AdicionaVitoriaCarta(c1);
                        d->vencedor = GetIdCarta(c1);
                    }else {
                        if (ComparaIdCarta(c1, c2) > 0) {
                            c2->num_vit = AdicionaVitoriaCarta(c2);
                            d->vencedor = GetIdCarta(c2);
                        }
                    }
                }
            }
        }
        d->diferenca = ComparaMagiaCarta(c1, c2);
        if ((*d).diferenca < 0) {
            d->diferenca = (*d).diferenca * (-1);
        }
    }else {
        if ((*d).atributo == FORCA) {
            if (ComparaAtaqueCarta(c1, c2) > 0) {
                c1->num_vit = AdicionaVitoriaCarta(c1);
                d->vencedor = GetIdCarta(c1);
            }else {
                if (ComparaAtaqueCarta(c1, c2) < 0) {
                    c2->num_vit = AdicionaVitoriaCarta(c2);
                    d->vencedor = GetIdCarta(c2);
                }else {
                    if (ComparaAtaqueCarta(c1, c2) == 0) {
                        d->desempate = true;
                        if (ComparaIdCarta(c1, c2) < 0) {
                            c1->num_vit = AdicionaVitoriaCarta(c1);
                            d->vencedor = GetIdCarta(c1);
                        }else {
                            if (ComparaIdCarta(c1, c2) > 0) {
                                c2->num_vit = AdicionaVitoriaCarta(c2);
                                d->vencedor = GetIdCarta(c1);
                            }
                        }
                    }
                }
            }
            d->diferenca = ComparaAtaqueCarta(c1, c2);
            if ((*d).diferenca < 0) {
                d->diferenca = (*d).diferenca * (-1);
            }
        }else {
            if ((*d).atributo == FOGO) {
                if (ComparaFogoCarta(c1, c2) < 0) {
                    c1->num_vit = AdicionaVitoriaCarta(c1);
                    d->vencedor = GetIdCarta(c1);
                }else {
                    if (ComparaFogoCarta(c1, c2) < 0) {
                        c2->num_vit = AdicionaVitoriaCarta(c2);
                        d->vencedor = GetIdCarta(c2);
                    }else {
                        if (ComparaFogoCarta(c1, c2) == 0) {
                            d->desempate = true;
                            if (ComparaIdCarta(c1, c2) < 0) {
                                c1->num_vit = AdicionaVitoriaCarta(c1);
                                d->vencedor = GetIdCarta(c1);
                            }else {
                                if (ComparaIdCarta(c1, c2) > 0) {
                                    c2->num_vit = AdicionaVitoriaCarta(c2);
                                    d->vencedor = GetIdCarta(c2);
                                }
                            }
                        }
                    }
                }
                d->diferenca = ComparaFogoCarta(c1, c2);
                if ((*d).diferenca < 0) {
                    d->diferenca = (*d).diferenca * (-1);
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
    return  (*d).id;
}

void ImprimeDuelo(tDuelo d) {
// Função inútil;
}

void LiberaDuelo(tDuelo d) {
    if (d != NULL) {
        free(d);
        d = NULL;
    }
}