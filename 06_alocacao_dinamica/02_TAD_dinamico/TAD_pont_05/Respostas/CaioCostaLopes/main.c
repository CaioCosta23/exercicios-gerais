#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

int main() {
    tBanco *banco;
    char opcao;
    int finalizar = 0;

    banco = CriaBanco();

    while(1) {
        scanf("%c");
        
        switch(opcao) {
            case 'A':
                AbreContaBanco(banco);
                if (banco == NULL) {
                    exit(1);
                }
                break;
            case 'D':
                DepositoContaBanco(banco);
                break;
            case 'S':
                SaqueContaBanco(banco);
                break;
            case 'T':
                TransferenciaContaBanco(banco);
                break;
            case 'R':
                ImprimeRelatorioBanco(banco);
                break;
            case 'F':
                finalizar = 1;
                break;
        }
        scanf("%*c");

        if (finalizar) {
            break;
        }
    }

    DestroiBanco(banco);

    return 0;
}