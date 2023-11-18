#include "string_utils.h"

int string_length(char str[]) {
    int s = 0, cont = 0;

    while(str[s]) {
        cont += 1;
        s++;
    }
    return cont;
}

void string_copy(char str[], char dest[]) {
    int s = 0;
    
    while(1) {
        dest[s] = str[s];
        
        if (str[s] == '\0') {
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
    int tamanho;

    tamanho = string_length(str);

    char reverse[tamanho];
    int s = 0, r = tamanho - 1;

    string_copy(str, reverse);

    while(str[s]) {
        str[s] = reverse[r];

        s++;
        r--;
    }
}