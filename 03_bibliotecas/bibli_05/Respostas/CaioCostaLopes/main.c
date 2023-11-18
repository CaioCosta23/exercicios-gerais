#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO 30

int main () {
    char str[TAMANHO_MAXIMO];
    char dest[TAMANHO_MAXIMO];
    int option;
    int finish = 0;

    scanf("%29s", str);

    while(1) {
        printf("1 - Tamanho string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar programa\n");
        printf("Opcao escolhida: ");

        scanf("%d", &option);

        printf("\n");

        switch(option) {
            case 1:
                printf("Tamanho da string: %d\n\n", string_lenght(str));
                break;
            case 2:
                string_copy(str, dest);
                printf("String copiada: %s", dest);
                break;
            case 3:
                string_upper(str);
                printf("String convertida em maiusculas: %s", str);
                break;
            case 4:
                string_lower(str);
                printf("String convertida para minusculo: %s", str);
                break;
            case 5:
                string_reverse(str);
                printf("String invertida: %s", str);
                break;
            case 6:
                finish = 1;
                break;
        }

        if (finish) {
            break;
        }
    }

    return 0;
}