
#include <stdio.h>
#include <stdlib.h>

int SomaDigitos(int n);


int main() {
    int num;
    int soma = 0;
    
    scanf("%d", &num);
    
    soma = SomaDigitos(num);
    
    printf("%d\n", soma);

    return 0;
}


/**
 * @brief Soma os valores de cada digito que um numero possui;
 * 
 * @param n numero a ser analisado;
 * @return int valor da soma dos digitos do respectivo numero;
 */
int SomaDigitos(int n) {
    
    if (n >= 10) {
        /**
         * @brief  retorno Recursivo a soma do digito anterior  com o diigito atual;
         * resto do numero dividido por 10, (que se torna um digito do numero ) somado ao acumulo da propria funcao de somar os digitos;
         */
        return n % 10 + SomaDigitos(n / 10);
    } 
    return n;
    // Retorna o numero do digito sobrando resto(ja que nao pais naa para ser dividido), entao, esse numero e retornado;
}
