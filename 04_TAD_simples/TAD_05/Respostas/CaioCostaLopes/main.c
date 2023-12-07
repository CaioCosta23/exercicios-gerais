#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "conta.h"

#define TAM_NOME 50
#define TAM_CPF 15

int main () {
    int qtdContas, op, numero, r;
    int c = 0;
    float valor;
    char nome[TAM_NOME], cpf[TAM_CPF];
    tUsuario usuario;

    scanf("%d\n", &qtdContas);

    tConta conta[qtdContas];

    scanf("%d\n", &op);

    while(1) {
        valor = 0.00;

        switch (op) {
            case 1:
                scanf("%f\n", &valor);
                conta[c] = SaqueConta(conta[c], valor);
                break;
            case 2:
                scanf("%f\n", &valor);
                conta[c] = SaqueConta(conta[c], valor);
                break;
            case 3:
                scanf("%s %s %d", nome, cpf, &numero);
                usuario = CriaUsuario(nome, cpf);
                conta[c] = CriaConta(numero, usuario);
                c++;
                break;
            case 4:
                for (r = 0; r < qtdContas; r++) {
                    ImprimeConta(conta[r]);
                    printf("\n");
                }
                break;
            default:
                exit(1);
        }
    }

    return 0;
}