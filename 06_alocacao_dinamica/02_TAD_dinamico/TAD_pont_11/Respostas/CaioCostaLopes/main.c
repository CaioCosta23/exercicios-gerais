#include <stdio.h>
#include <stdlib.h>
#include "loja.h"

void FinalizaPrograma(tLoja *lojas[], int qtdLojas) {
    int q;
    for (q = 0; q < qtdLojas; q++) {
        ApagaLoja(lojas[q]);
    }
}


int main() {
    int qtdLojas, opcao, idLoja, q;
    int l = 0;
    int encerrar = 0;
    float aluguel, salario, comissao, valorVenda;
    char nome[50];

    scanf("%d", &qtdLojas);

    tLoja *lojas[qtdLojas];

    while (1) {
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                encerrar = 1;
                break;
            case 1:
                scanf("%d %f", &idLoja, &aluguel);
                lojas[l] = AbreLoja(idLoja, aluguel);
                if (lojas[l] == NULL) {
                    printf("%d\n!", l);
                    FinalizaPrograma(lojas, l);
                    printf("%d\n!", l);
                }
                l++;
                break;
            case 2:
                scanf("%s %f %f", nome, &salario, &comissao);
                scanf("%d", &idLoja);

                for (q = 0; q < l; q++) {
                    if (VerificaIdLoja(lojas[q], idLoja)) {
                        ContrataVendedor(lojas[q], RegistraVendedor(nome, salario, comissao));
                        if (lojas[q] == NULL) {
                            printf("%d\n!", l);
                            FinalizaPrograma(lojas, l);
                            exit(1);
                        }
                    }
                }
                break;
            case 3:
                scanf("%d %s %f", &idLoja, nome, &valorVenda);
                for (q = 0; q < l; q++) {
                    if (VerificaIdLoja(lojas[q], idLoja)) {
                        RegistraVenda(lojas[q], nome, valorVenda);
                    }
                }
                break;
            case 4:
                for (q = 0; q < l; q++) {
                    CalculaLucro(lojas[q]);
                    ImprimeRelatorioLoja(lojas[q]);
                }
                break;
        }
        if (encerrar) {
            break;
        }
    }

    FinalizaPrograma(lojas, l);

    return 0;
}