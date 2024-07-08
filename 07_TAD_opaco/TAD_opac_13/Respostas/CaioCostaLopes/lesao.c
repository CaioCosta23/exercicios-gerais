#include <stdio.h>
#include <stdlib.h>
#include "lesao.h"

struct lesao {
    char *id;
    char *diagnostico;
    char *regiaoCorpo;
    int chanceMalignidade;
};

tLesao *CriaLesao() {
    tLesao *lesao = (tLesao*)malloc(sizeof(tLesao));

    if (lesao == NULL) {
        printf("Erro na alocacao de memoria da lesao!\n");
        return lesao;
    }

    lesao->id = (char*)malloc(TAM_ID * sizeof(char));
    if ((*lesao).id == NULL) {
        printf("Erro na alocacao de memoria no ID (Idenficador) da lesao!\n");
        LiberaLesao(lesao);
        return lesao;
    }

    lesao->diagnostico = (char*)malloc(TAM_DIAG * sizeof(char));
    if ((*lesao).diagnostico == NULL) {
        printf("Erro na alocacao de memoria no diagnostico da lesao!\n");
        LiberaLesao(lesao);
        return lesao;
    }

    lesao->regiaoCorpo = (char*)malloc(TAM_REG * sizeof(char));
    if ((*lesao).regiaoCorpo == NULL) {
        printf("Erro na alocacao de memoria no nome da regiao da lesao!\n");
        LiberaLesao(lesao);
        return lesao;
    }

    lesao->chanceMalignidade = -1;

    return lesao;
}

void LeLesao(tLesao *l) {
    scanf("%[^\n]\n", l->id);
    scanf("%[^\n]\n", l->diagnostico);
    scanf("%[^\n]\n", l->regiaoCorpo);
    scanf("%d", &l->chanceMalignidade);
}

char *GetIdLesao(tLesao *l) {
    return (*l).id;
}

int PrecisaCirurgiaLesao(tLesao *l) {
    return ((*l).chanceMalignidade > 50);
}

void LiberaLesao(tLesao *l) {
    if (l != NULL) {
        if ((*l).id != NULL) {
            if ((*l).diagnostico != NULL) {
                if ((*l).regiaoCorpo != NULL) {
                    free((*l).regiaoCorpo);
                    l->regiaoCorpo = NULL;
                }
                free((*l).diagnostico);
                l->diagnostico = NULL;
            }
            free((*l).id);
            l->id = NULL;
        }
        free(l);
        l = NULL;
    }
}