#include <stdio.h>
#include <stdlib.h>
#include "loja.h"

#define MAX_VENDEDORES 10

tLoja *AbreLoja(int id, float aluguel) {
    tLoja *loja = (tLoja*)malloc(sizeof(tLoja));
    
    if (loja == NULL) {
        printf("Erro na alocacao da loja ");
        return loja;
    }

    loja->id = id;
    loja->lucro = 0.00;
    loja->totalVendedores = 0;
    loja->maxVendedores = MAX_VENDEDORES;
    loja->aluguel = aluguel;

    loja->vendedores = (tVendedor**)malloc((*loja).maxVendedores * sizeof(tVendedor*));

    if (loja->vendedores == NULL) {
        printf("Erro na alocacao no vetor de vendedores da loja ");
        loja = NULL;
    }

    return loja;
}

int VerificaIdLoja(tLoja *loja, int id) {
    return ((*loja).id == id);
}

void ContrataVendedor(tLoja *loja, tVendedor *vendedor) {
    if ((*loja).totalVendedores < (*loja).maxVendedores) {
        loja->vendedores[(*loja).totalVendedores] = vendedor;
        if ((*loja).vendedores[(*loja).totalVendedores] == NULL) {
            printf("%d\n!", (*loja).totalVendedores);
            ApagaLoja(loja);
        }else {
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

    printf("Loja %d: Lucro total: R$ %.2f\n", (*loja).id, (*loja).lucro);

    for (v = 0; v < (*loja).totalVendedores; v++) {
        ImprimeRelatorioVendedor((*loja).vendedores[v]);
    }
}

void ApagaLoja(tLoja *loja) {
    int v;

    if (loja != NULL) {
        if (loja->vendedores != NULL) {
            for (v = 0; v < (*loja).totalVendedores; v++) {
                if ((*loja).vendedores[v] != NULL) {
                    ApagaVendedor((*loja).vendedores[v]);
                    loja->vendedores[v] = NULL;
                }
            }
            free((*loja).vendedores);
            loja->vendedores = NULL;
        }
        free(loja);
        loja = NULL;
    }
}