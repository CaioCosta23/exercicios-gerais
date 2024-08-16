#include <stdio.h>
#include <stdlib.h>
#include "computador.h"

int main() {
    tComputador *computador;

    computador = CriaComputador();
    GerenciaJogo(computador);
    ImprimeRelatorio(computador);
    DestroiComputador(computador);

    return 0;
}