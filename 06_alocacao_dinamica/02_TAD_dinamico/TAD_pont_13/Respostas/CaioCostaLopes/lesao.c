#include <stdio.h>
#include <stdlib.h>
#include "lesao.h"

tLesao *CriaLesao() {
    tLesao *lesao = (tLesao*)malloc(sizeof(tLesao));

    if (lesao == NULL) {
        printf("Erro na alocacao de memoria da lesao!\n");
        return lesao;
    }

    lesao->id = (char*)malloc(TAM_ID * sizeof(char));
    if ((*lesao).id == NULL) {
        printf("Erro na alocacao de memoria do ID da lesao!\n");
        LiberaLesao(lesao);
        return lesao;
    }

    lesao->diagnostico = (char*)malloc(TAM_DIAG * sizeof(char));
    if ((*lesao).diagnostico == NULL) {
        printf("Erro na alocacao de memoria no nome do diagnostico da lesao!\n");
        LiberaLesao(lesao);
        return lesao;
    }

    lesao->regiao_corpo = (char*)malloc(TAM_REG * sizeof(char));
    if ((*lesao).regiao_corpo == NULL) {
        printf("Erro na alocacao de memoria do nome da regiao do corpo onde foi constatada a lesao");
        LiberaLesao(lesao);
        return lesao;
    }

    lesao->chance_malignidade = -1;

    return lesao;
}

void LeLesao(tLesao *l) {
    scanf("%s", l->id);
    scanf("%s", l->diagnostico);
    scanf("%s", l->regiao_corpo);
    scanf("%d\n", &l->chance_malignidade);
}

char *GetIdLesao(tLesao *l) {
    return (*l).id;
}

int PrecisaCirurgiaLesao(tLesao *l) {
    return ((*l).chance_malignidade > 50);
}

void LiberaLesao(tLesao *l) {
    if (l != NULL) {
        if ((*l).id != NULL) {
            if ((*l).diagnostico != NULL) {
                if ((*l).regiao_corpo != NULL) {
                    free((*l).regiao_corpo);
                    l->regiao_corpo = NULL;
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