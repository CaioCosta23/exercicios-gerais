#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "franquia.h"

struct franquia {
    char *nome;
    char *conferencia;
    int vitoriasCasa;
    int vitoriasFora;
    int derrotasCasa;
    int derrotasFora;
    float aproveitamento;
};

tFranquia LeFranquia() {
    tFranquia franquia = (tFranquia)malloc(sizeof(struct franquia));

    if (franquia == NULL) {
        printf("Erro na alocacao de memoria da franquia ");
        return franquia;
    }

    franquia->nome = (char*)malloc(MAX_NOME * sizeof(char));
    if ((*franquia).nome == NULL) {
        printf("Erro na alocacao de memoria para o nome da franquia ");
        LiberaFranquia(franquia);
        return franquia;
    }

    franquia->conferencia = (char*)malloc(MAX_NOME * sizeof(char));
    if ((*franquia).conferencia == NULL) {
        printf("Erro na alocacao de memoria para o nome da conferencia da franquia ");
        LiberaFranquia(franquia);
        return franquia;
    }

    franquia->vitoriasCasa = 0;
    franquia->vitoriasFora = 0;
    franquia->derrotasCasa = 0;
    franquia->derrotasFora = 0;
    franquia->aproveitamento = 0;

    scanf("%s %s\n", franquia->nome, franquia->conferencia);

    return franquia;
}

char *GetNomeFranquia(tFranquia f) {
    return (*f).nome;
}

char *GetConferenciaFranquia(tFranquia f) {
    return (*f).conferencia;
}

void AdicionaVitoriaCasaFranquia(tFranquia f) {
    f->vitoriasCasa += 1;
}

void AdicionaVitoriaForaFranquia(tFranquia f) {
    f->vitoriasFora += 1;
}

void AdicionaDerrotaCasaFranquia(tFranquia f) {
    f->derrotasCasa += 1;
}

void AdicionaDerrotaForaFranquia(tFranquia f) {
    f->derrotasFora += 1;
}

int GetVitoriaCasaFranquia(tFranquia f) {
    return (*f).vitoriasCasa;
}

int GetVitoriaForaFranquia(tFranquia f) {
    return (*f).vitoriasFora;
}

int GetDerrotaCasaFranquia(tFranquia f) {
    return (*f).derrotasCasa;
}

int GetDerrotaForaFranquia(tFranquia f) {
    return (*f).derrotasFora;
}

void ImprimeFranquia(tFranquia f) {
    if ((GetVitoriaCasaFranquia(f) + GetVitoriaForaFranquia(f) +
        GetDerrotaCasaFranquia(f) + GetDerrotaForaFranquia(f)) > 0) {
        
        f->aproveitamento = (float)((GetVitoriaCasaFranquia(f) + GetVitoriaForaFranquia(f)) * 100) /
                            (float)(GetVitoriaCasaFranquia(f) + GetVitoriaForaFranquia(f) +
                                    GetDerrotaCasaFranquia(f) + GetDerrotaForaFranquia(f));
    }

    printf("%s ", (*f).nome);

    if (strcmp(GetConferenciaFranquia(f), "OESTE") == 0) {
        printf("[CO]");
    }else {
        if (strcmp(GetConferenciaFranquia(f), "LESTE") == 0) {
            printf("[CL]");
        }
    }

    printf(" %d %d %.2f %d %d\n", (GetVitoriaCasaFranquia(f) + GetVitoriaForaFranquia(f)),
                                  (GetDerrotaCasaFranquia(f) + GetDerrotaForaFranquia(f)),
                                  (*f).aproveitamento, GetVitoriaCasaFranquia(f), GetVitoriaForaFranquia(f));
}

void LiberaFranquia(tFranquia f) {
    if (f != NULL) {
        if ((*f).nome != NULL) {
            free((*f).nome);
            f->nome = NULL;
        }
        if ((*f).conferencia != NULL) {
            free((*f).conferencia);
            f->conferencia = NULL;
        }
        free(f);
        f = NULL;
    }
}