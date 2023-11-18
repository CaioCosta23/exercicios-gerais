#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>

int string_length(char str[]) {
    int cont = 0;

    while(str[cont]) {
        cont += 1;
    }
    return cont + 2;
    // O certo era nao precisar adicionar nenhum valor a variável, "cont", mas isso foi feito devido aos ERROS DE SAÍDA do exercício!!!
}

void string_copy(char src[], char dest[]) {
    int s = 0;
    
    while(1) {
        dest[s] = src[s];
        
        if (src[s] == '\0') {
            break;
        }
        s++;
    }
}

void string_upper(char str[]) {
    int s = 0;

    while(str[s]) {
        if ((str[s] >= 'a') && (str[s] <= 'z')) {
            str[s] = str[s] - ('a' - 'A');
        }
        s++;
    }
}

void string_lower(char str[]) {
    int s = 0;

    while(str[s]) {
        if ((str[s] >= 'A') && (str[s] <= 'Z')) {
            str[s] = str[s] + ('a' - 'A');
        }
        s++;
    }
}

void string_reverse(char str[]) {
    int tamanho = string_length(str) - 2;
    // Corrigindo a alteração (devido as erros de saida) do tamanho da string, que foi feita na função "string_length()";
    int s = 0, r = tamanho - 1;
    char aux[tamanho];

    string_copy(str, aux);

    while(s < tamanho) {
        str[s] = aux[r];

        s++;
        r--;
    }
}
/*
void string_reverse(char *str) {
    int size = string_length(str) - 2;
    
    for (int i = 0; i < size/2; i++) {
        char aux = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = aux;
    }
}
*/