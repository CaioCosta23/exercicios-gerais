#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "conta.h"

#define TAM_NOME 50
#define TAM_CPF 15

int main () {
    int qtdContas, op, numero, r, v;
    int c = 0;
    float valor;
    char nome[TAM_NOME], cpf[TAM_CPF];

    scanf("%d", &qtdContas);

    tUsuario usuario[qtdContas];
    tConta conta[qtdContas];

    while(1) {
        valor = 0.00;

        scanf("%d", &op);

        if (op == 0) {
            break;
        }else {

            switch (op) {
                case 1:
                    scanf("%d%f", &numero, &valor);
                    for (v = 0; v < c; v ++) {
                        if (VerificaConta(conta[v], numero)) {
                            conta[v] = SaqueConta(conta[v], valor);
                            break;
                        }
                    }
                    break;
                case 2:
                    scanf("%d%f", &numero, &valor);
                    for (v = 0; v < c; v ++) {
                        if (VerificaConta(conta[v], numero)) {
                            conta[v] = DepositoConta(conta[v], valor);
                            break;
                        }
                    }
                    break;
                case 3:
                    if (c <= 5) {
                        scanf("%s %s %d", nome, cpf, &numero);
                        usuario[c] = CriaUsuario(nome, cpf);
                        conta[c] = CriaConta(numero, usuario[c]);
                        c++;
                    }
                    break;
                case 4:
                    printf("===| Imprimindo Relatorio |===\n");
                    for (r = 0; r < c; r++) {
                        ImprimeConta(conta[r]);
                        printf("\n");
                    }
                    break;
            }
        }
    }

    return 0;
}