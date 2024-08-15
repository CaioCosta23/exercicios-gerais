#include <stdio.h>
#include <stdlib.h>
#include "computador.h"

int main() {
    tComputador *computador;

    computador = CriaComputador(computador);
    GerenciaJogo(computador);
    ImprimeRelatorio(computador);
    DestroiComputador(computador);

    return 0;
}