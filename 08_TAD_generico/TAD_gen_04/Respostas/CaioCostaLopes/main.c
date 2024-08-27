#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "banco.h"

#define CADASTRAR_AGENCIA 'A'
#define CADASTRAR_CONTA 'C'
#define FINALIZAR 'F'

int main() {
    char acao;
    tBanco *banco;
    tAgencia *agencia;
    tConta *conta;
    int numeroAgencia;
    bool programaFinalizado = false;

    banco = CriaBanco();    
    LeBanco(banco);

    while (1) {
        scanf("%c\n", &acao);

        switch (acao) {
            case CADASTRAR_AGENCIA:
                agencia = CriaAgencia();
                LeAgencia(agencia);
                AdicionaAgencia(banco, agencia);
                break;
            case CADASTRAR_CONTA:
                conta = CriaConta();
                LeConta(conta);
                scanf("%d;", &numeroAgencia);
                InsereContaBanco(banco, numeroAgencia, conta);
                break;
            case FINALIZAR:
                programaFinalizado = true;
                break;
            default:
                break;
        }
        if (programaFinalizado == true) {
            break;
        }
    }
    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);

    return 0;
}