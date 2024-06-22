#include <stdio.h>
#include <stdlib.h>
#include "carta.h"

tCarta LeCarta() {
    tCarta carta = (tCarta)malloc(sizeof(struct carta));

    if (carta == NULL) {
        printf("Erro na alocacao de memoria da carta ");
        return carta;
    }

    carta->id = -1;
    carta->nome = (char*)malloc(MAX_NOME * sizeof(char));
    if ((*carta).nome == NULL) {
        printf("Erro na alocacao do nome da carta ");
        LiberaCarta(carta);
        return carta;
    }

    carta->magia = 0;
    carta->ataque = 0;
    carta->fogo = 0;
    carta->num_vit = 0;
    carta->num_duelos = 0;

    scanf("%d\n", &carta->id);
    scanf("%[^\n]\n", carta->nome);
    scanf("%d %d %d\n", &carta->magia, &carta->ataque, &carta->fogo);

    return carta;
}

int GetIdCarta(tCarta c) {
    return (*c).id;
}

char *GetNomeCarta(tCarta c) {
    return (*c).nome;
}

int GetNumVitCarta(tCarta c) {
    return (*c).num_vit;
}

int GetMagiaCarta(tCarta c) {
    return (*c).magia;
}

int GetAtaqueCarta(tCarta c) {
    return (*c).ataque;
}

int GetFogoCarta(tCarta c) {
    return (*c).fogo;
}

bool EhCartaValida(tCarta c) {
    if ((((GetMagiaCarta(c)>= 0) && (GetMagiaCarta(c) <= 30)) && ((GetAtaqueCarta(c) >= 0) && (GetAtaqueCarta(c) <= 30)) &&
        ((GetFogoCarta(c) >= 0) && (GetFogoCarta(c) <= 30))) && ((GetMagiaCarta(c) + GetAtaqueCarta(c) + GetFogoCarta(c)) <= 80)) {
        return true;
    }
    return false;
}

bool EhMesmoIdCarta(tCarta c1, tCarta c2) {
    if (GetIdCarta(c1) == GetIdCarta(c2)) {
        return true;
    }
    return false;
}

int ComparaIdCarta(tCarta c1, tCarta c2) {
    return (GetIdCarta(c1) - GetIdCarta(c2));
}

int ComparaMagiaCarta(tCarta c1, tCarta c2) {
    return (GetMagiaCarta(c1) - GetMagiaCarta(c2));
}

int ComparaAtaqueCarta(tCarta c1, tCarta c2) {
    return (GetAtaqueCarta(c1) - GetAtaqueCarta(c2));
}

int ComparaFogoCarta(tCarta c1, tCarta c2) {
    return (GetFogoCarta(c1) - GetFogoCarta(c2));
}

int AdicionaVitoriaCarta(tCarta c) {
    c->num_vit = GetNumVitCarta(c) + 1;
    return (*c).num_vit;
}

void ImprimeCarta(tCarta c) {
    // Função Inútil (Útil somente para testes);
}

void LiberaCarta(tCarta c) {
    if (c != NULL) {
        if ((*c).nome != NULL) {
            free((*c).nome);
            c->nome = NULL;
        }
        free(c);
        c = NULL;
    }
}