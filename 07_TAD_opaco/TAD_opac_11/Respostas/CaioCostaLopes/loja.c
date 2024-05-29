#include <stdio.h>
#include <stdlib.h>
#include "loja.h"

struct Loja {
    tVendedor **vendedores;
    int id;
    float lucro;
    int totalVendedores;
    int maxVendedores;
    float aluguel;
};

#define MAX_VENDEDORES 10

tLoja *AbreLoja(int id, float aluguel) {
    tLoja *loja = (tLoja*)malloc(sizeof(tLoja));

    if (loja == NULL) {
        printf("Erro na alocacao da loja ");
        return loja;
    }

    loja->id = id;
    loja->lucro = 0;
    loja->totalVendedores = 0;
    loja->maxVendedores = MAX_VENDEDORES;
    loja->aluguel = aluguel;

    loja->vendedores = (tVendedor**)malloc((*loja).maxVendedores * sizeof(tVendedor*));
    if ((*loja).vendedores == NULL) {
        printf("Erro na alocacao do vetor de vendedores da loja ");
        ApagaLoja(loja);
    }
    return loja;
}

int VerificaIdLoja(tLoja *loja, int id) {
    return ((*loja).id = id);
}

void ContrataVendedor(tLoja *loja, tVendedor *vendedor) {
    if ((*loja).totalVendedores < (*loja).maxVendedores) {
        if (vendedor == NULL) {
            printf("%d na loja ");
            ApagaLoja(loja);
        }else {
            loja->vendedores[(*loja).totalVendedores] = vendedor;
            loja->totalVendedores += 1;
        }
    }
}

void RegistraVenda(tLoja *loja, char nome[], float valor) {
    int v;

    for (v = 0; v < (*loja).totalVendedores; v++) {
        if (VerificaNomeVendedor((*loja).vendedores[v], nome)) {
            ContabilizaVenda((*loja).vendedores[v], valor);
            break;
        }
    }
}

void CalculaLucro(tLoja *loja) {
    int v;

    for (v = 0; v < (*loja).totalVendedores; v++) {
        loja->lucro += (GetTotalVendido((*loja).vendedores[v]) - GetTotalRecebido((*loja).vendedores[v]));
    }
    loja->lucro -= (*loja).aluguel;
}

void ImprimeRelatorioLoja(tLoja *loja) {
    int v;

    printf("Loja %d: Lucro total: R$: %.2f\n", (*loja).id, (*loja).lucro);

    for (v = 0; v < (*loja).totalVendedores; v++) {
        ImprimeRelatorioVendedor((*loja).vendedores[v]);
    }
}

void ApagaLoja(tLoja *loja) {
    int v;

    if (loja != NULL) {
        if ((*loja).vendedores != NULL) {
            for (v = 0; v < (*loja).totalVendedores; v++) {
                ApagaVendedor((*loja).vendedores[v]);
            }
            free((*loja).vendedores);
            loja->vendedores = NULL;
        }
        free(loja);
        loja = NULL;
    }
}