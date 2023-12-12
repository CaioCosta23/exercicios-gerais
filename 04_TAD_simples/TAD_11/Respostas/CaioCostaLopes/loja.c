#include <stdio.h>
#include <stdlib.h>
#include "loja.h"
#include "vendedor.h"

tLoja AbreLoja(int id, float aluguel) {
    tLoja loja;

    loja.id = id;
    loja.lucro = 0.00;
    loja.totalVendedores = 0;
    loja.aluguel = aluguel;

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
        loja.lucro += (GetTotalVendido(loja.vendedores[v]) - GetTotalRecebido(loja.vendedores[v]));
    }
    loja.lucro -= loja.aluguel;

    return loja;
}

void ImprimeRelatorioLoja(tLoja loja) {
    int v;

    printf("Loja %d: Lucro total: R$ %.2f\n", loja.id, loja.lucro);
    
    for (v = 0;  v < loja.totalVendedores; v++) {
        ImprimeRelatorioVendedor(loja.vendedores[v]);
    }
}