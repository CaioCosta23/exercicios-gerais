#include <stdio.h>
#include <stdlib.h>
#include "franquia.h"

tFranquia LeFranquia() {
    tFranquia franquia = (tFranquia)malloc(sizeof(struct franquia));

    if (franquia == NULL) {
        printf("Erro na alocacao de memoria da franquia ");
        return franquia;
    }

    franquia->nome = (char*)malloc(MAX_NOME * sizeof(char));
    if ((*franquia).nome == NULL) {
        printf("Erro na alocacao de memoria do nome da franquia ");
        LiberaFranquia(franquia);
        return franquia;
    }

    franquia->conferencia = (char*)malloc(MAX_NOME * sizeof(char));
    if ((*franquia).conferencia == NULL) {
        printf("Erro na alocacao de memoria do nome da conferencia da franquia ");
        LiberaFranquia(franquia);
        return franquia;
    }

    franquia->vit_casa = 0;
    franquia->vit_fora = 0;
    franquia->der_casa = 0;
    franquia->der_fora = 0;
    franquia->aproveitamento = 0;

    scanf("%s %s\n", &franquia->nome, &franquia->conferencia);

    return franquia;
}

char *GetNomeFranquia(tFranquia f) {
    return (*f).nome;
}

char *GetNomeConferencia(tFranquia f) {
    return (*f).conferencia;
}

void AdicionaVitoriaCasaFranquia(tFranquia f) {
    f->vit_casa += 1;
}

void AdicionaVitoriaForaFranquia(tFranquia f) {
    f->vit_fora += 1;
}

void AdicionaDerrotaCasaFranquia(tFranquia f) {
    f->der_casa += 1;
}

void AdicionaDerrotaForaaFranquia(tFranquia f) {
    f->der_fora += 1;
}

int GetVitoriaCasaFranquia(tFranquia f) {
    return (*f).vit_casa;
}

int GetVitoriaForaFranquia(tFranquia f) {
    return (*f).vit_fora;
}

int GetDerrotaCasaFranquia(tFranquia f) {
    return (*f).der_casa;
}

int GetDerrotaForaFranquia(tFranquia f) {
    return (*f).der_fora;
}

void ImprimeFranquia(tFranquia f) {
    f->aproveitamento = (float)((GetVitoriaCasaFranquia(f) + GetVitoriaForaFranquia(f)) * 100) / 
                        (float)(GetVitoriaCasaFranquia(f) + (GetVitoriaForaFranquia(f) +
                         GetDerrotaCasaFranquia(f) + GetDerrotaForaFranquia(f)));

    printf("%s ", (*f).nome);

    if (strcmp(GetConferenciaFranquia(f), "OESTE") == 0) {
        printf("[CO]");
    }else {
        if (strcmp(GetConferenciaFranquia(f), "OESTE") == 0) {
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
            if ((*f).conferencia != NULL) {
                free((*f).conferencia);
                f->conferencia = NULL;
            }
            free((*f).nome);
            f->nome = NULL;
        }
        free(f);
        f = NULL;
    }
}