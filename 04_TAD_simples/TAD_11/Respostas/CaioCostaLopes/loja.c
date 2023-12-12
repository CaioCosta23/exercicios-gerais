#include <stdio.h>
#include <stdlib.h>
#include "loja.h"
#include "vendedor.h"

tLoja AbreLoja(int id, float aluguel) {
    tLoja loja;

    loja.id = id;
    loja.lucro = 0;
    loja.totalVendedores = 0;

    return loja;
}

int VerificaIdLoja(tLoja loja, int id) {
    return (loja.id == id);
}

tLoja ContrataVendedor(tLoja loja, tVendedor vendedor) {
    loja.vendedores[loja.totalVendedores] = vendedor;
    loja.totalVendedores += 1;

    return loja;
}

tLoja RegistraVenda(tLoja loja, char nome[50], float valor) {
    int v;
    int vendedorAchado = 0;

    for (v = 0; v < loja.totalVendedores; v++) {
        if (VerificaNomeVendedor(loja.vendedores[v], nome)) {
            vendedorAchado = 1;
            break;
        }
    }
    if (vendedorAchado) {
        loja.vendedores[v] = ContabilizaVenda(loja.vendedores[v], valor);
    }
    return loja;
}

tLoja CalculaLucro(tLoja loja) {
    int v;

    for (v = 0; v < loja.totalVendedores; v++) {
        loja.lucro = loja.lucro + GetTotalvendido(loja.vendedores[v]) - GetTotalRecebido(loja.vendedores[v]) - loja.aluguel;
    }
    return loja;
}

ImpirmeRelatorioLoja(tLoja loja) {
    int v;

    printf("Lucro total: R$ %.2f\n", loja.lucro);
    
    for (v = 0;  v < loja.totalVendedores; v++) {
        ImprimeRelatorioVendedor(loja.vendedores[v]);
    }
}