#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vendedor.h"

tVendedor *RegistraVendedor(char *nome, float salario, float prct_comissao) {
    tVendedor *vendedor = (tVendedor*)malloc(sizeof(tVendedor));

    if (vendedor == NULL) {
        printf("Erro na alocacao do vendedor ");
        return vendedor;
    }
    vendedor->nome = (char*)malloc((strlen(nome) + 1) * sizeof(char));
    if ((*vendedor).nome == NULL) {
        printf("Error na alocacao do nome do vendedor ");
        ApagaVendedor(vendedor);
    }

    strcpy((*vendedor).nome, nome);
    vendedor->salario = salario;
    vendedor->prct_comissao = prct_comissao;
    vendedor->valor_vendido = 0;

    return vendedor;
}

int VerificaNomeVendedor(tVendedor *vendedor, char nome[]) {
    if (!(strcmp((*vendedor).nome, nome))) {
        return 1;
    }
    return 0;
}

void ContabilizaVenda(tVendedor *vendedor, float valor) {
    vendedor->valor_vendido += valor;
}

float GetSalario(tVendedor *vendedor) {
    return (*vendedor).salario;
}

float GetComissao(tVendedor *vendedor) {
    return ((*vendedor).prct_comissao * (*vendedor).valor_vendido);
}

float GetTotalVendido(tVendedor *vendedor) {
    return (*vendedor).valor_vendido;
}

float GetTotalRecebido(tVendedor *vendedor) {
    return ((*vendedor).salario + GetComissao(vendedor));
}

void ImprimeRelatorioVendedor(tVendedor *vendedor) {
    printf("\t%s > Total vendido: R$%.2f\n", (*vendedor).nome, (*vendedor).valor_vendido);
    printf("\t\tTotal recebido: R$%.2f\n", GetTotalRecebido(vendedor));
}

void ApagaVendedor(tVendedor *vendedor) {
    if (vendedor != NULL) {
        if ((*vendedor).nome != NULL) {
            free((*vendedor).nome);
            vendedor->nome = NULL;
        }
        free(vendedor);
        vendedor = NULL;
    }
}