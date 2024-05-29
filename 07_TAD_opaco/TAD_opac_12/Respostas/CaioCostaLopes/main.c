#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main() {
    Array *lista;
    int elementoBuscado, posicaoElemento;

    lista = CriarArray();
    LerArray(lista);
    OrdenarArray(lista);

    scanf("%d", &elementoBuscado);
    posicaoElemento = BuscaBinariaArray(lista, elementoBuscado);

    if (posicaoElemento >= 0) {
        printf("Elemento %d encontrado no índice %d.\n", elementoBuscado, posicaoElemento);
    }else {
        printf("Elemento %d não encontrado no array (%d).\n", elementoBuscado, posicaoElemento);
    }

    DestruirArray(lista);
}