#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO 1000

int main () {
    char str[TAMANHO_MAXIMO], dest[TAMANHO_MAXIMO];;
    int option;
    int finish = 0;

    scanf("%999[^\n]\n", str);

    do {

        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: ");

        scanf("%d", &option);

        printf("\n");

        switch(option) {
            case 1:
                printf("Tamanho da string: %d\n\n", string_length(str));
                break;
            case 2:
                string_copy(str, dest);
                printf("String copiada: %s\n\n", dest);
                break;
            case 3:
                string_upper(str);
                printf("String convertida para maiusculas: %s\n\n", str);
                break;
            case 4:
                string_lower(str);
                printf("String convertida para minusculas: %s\n\n", str);
                break;
            case 5:
                string_reverse(str);
                printf("String invertida: %s\n\n", str);
                break;
            case 6:
                finish = 1;
                break;
        }

        if (finish) {
            break;
        }
    }while(1);

    return 0;
}