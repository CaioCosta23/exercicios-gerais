#include <stdio.h>
#include <stdlib.h>
#include "sistema.h"

int main() {
    tSistema *sistema;

    sistema = CriaSistema();
    
    LeSistema(sistema);
    ImprimeFatuamentoSistema(sistema);
    DestroiSistema(sistema);

    return  0;
}