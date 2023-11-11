#include <stdio.h>
#include <stdlib.h>

int Fatorial(int num);


int main() {
    int num, fat;
    
    scanf("%d", &num);
    
    fat = Fatorial(num);
    
    printf("%d\n", fat);

    return 0;
}


/**
 * @brief Funcao que calcula o fatorial de um numero recebido da entrada padrao;
 * 
 * @param num numero lido na entrada, o qual se deseja calcular o fatorial
 * @return int retorno recursivo das multipicacoes de cada termo presente nao fatorial;
 */
int Fatorial(int num) {
    if (num <= 1) {
        return 1;
    }else {
        return num * Fatorial(num - 1);
    }
}
