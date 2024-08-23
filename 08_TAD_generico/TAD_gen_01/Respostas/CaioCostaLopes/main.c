#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main() {
    int tipo, numeroElementos;
    tGeneric *tadGenerico;

    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos:");

    scanf("%d %d", &tipo, &numeroElementos);

    tadGenerico = CriaGenerico(tipo, numeroElementos);
    LeGenerico(tadGenerico);
    ImprimeGenerico(tadGenerico);
    DestroiGenerico(tadGenerico);

    return 0;
}