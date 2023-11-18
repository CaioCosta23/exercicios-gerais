#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO 30

int main () {
    char str[TAMANHO_MAXIMO];
    char dest[TAMANHO_MAXIMO];
    int option;
    int finish = 0;

    scanf("%[^\n]", str);

    do {

        printf("1 - Tamanho string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar programa\n");
        printf("Opcao escolhida: ");

        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nTamanho da string: %d\n\n", string_length(str));
                break;
            case 2:
                string_copy(str, dest);
                printf("\nString copiada: %s\n", dest);
                break;
            case 3:
                string_upper(str);
                printf("\nString convertida em maiusculas: %s\n", str);
                break;
            case 4:
                string_lower(str);
                printf("\nString convertida para minusculo: %s\n", str);
                break;
            case 5:
                string_reverse(str);
                printf("\nString invertida: %s\n", str);
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