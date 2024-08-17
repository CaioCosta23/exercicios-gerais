#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"

int main() {
    tAgencia *agencia;

    agencia = CriaAgencia();

    LeOperacoes(agencia);

    ImprimeOperacoesSuspeitas(agencia);
    ImprimeDoisCorrentistasComMaiorSaldo(agencia);
    ImprimeSaldoTotal(agencia);

    DestroiAgencia(agencia);
    
    return 0;
}