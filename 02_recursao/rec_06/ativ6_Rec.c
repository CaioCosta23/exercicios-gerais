#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int n);


int main() {
    int num, fib;
    
    scanf("%d", &num);
    
    fib = Fibonacci(num);
    
    printf("%d\n", fib);

    return 0;
}

/**
 * @brief Funcao que calcula o valor de um "n-esimo" termo da serie de FIBONACCI;
 * 
 * @param n posicao que o numero presente na serie de FIBONACCI ocupa;
 * @return int soma do valor "n-esimo" da serie;
 */
int Fibonacci(int n) {
    if (n > 1) {
        /**
         * @brief Retorno recursivo da soma dos valores anterior e do anterior a esse;
         *  recursivamente, ate o segundo termo da serie, um valor e somado/acumuulado com seu anterio, para ofrmar um terno "n-esimo" pedido;
         */
        return  Fibonacci(n - 2) + Fibonacci(n - 1);
    }else {
        if (n == 1) {
            /**
             * @brief retorna o valor de fibonacci e o valor 1, (que e o penultimo termo da serie;) 
             * 
             */
            return Fibonacci(n - 1) + n;
        }
    }
    return 0;
}


