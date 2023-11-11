#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO 50


int Palindromo(char string[], int tamanho);


int main() {
    char palavra[TAMANHO_MAXIMO];
    int tamanho;
    
    while(scanf("%s", palavra) == 1) {
    
	tamanho = strlen(palavra);
	    
	if (Palindromo(palavra, tamanho)) {
            printf("SIM\n");
	}else {
	    printf("NAO\n");
	}
    }

    return 0;
}


/**
 * @brief  Verifica se uma palavra e ou nao um "Palindromo" (palavra que reescrita de tras para frente e a mesma que a sua form a original);
 * 
 * @param string  palavra lida durante a execucao do programa;
 * @param tamanho tamanho da palavra;
 * @return int verdadeito ou falso;
 */
int Palindromo(char string[], int tamanho) {
    /**
     * @brief Ferifica se a srring chegou ao fim;
     * A cada rodada (recursiva) da funcao, o valor da variavel "tamanho" e decrementada. com isso, se o "tamanho" chega a 0, siginifica que a 
     * string terminou;
     */
    if (tamanho > 0) {
        /**
         * @brief Comparacao entre as letras (caracteres) da palavra original e da palavra de tras para frente;
         * Uma das palavras sera lida ao contrario, e a mesma palavra tambem sera lida, mas da forma original. Caso as letras continuem coincidindo
         * (ou seja, forem iguais), entra-se dentro da condicional para execitar os comandos abaixo;
         */
        if ((string[tamanho - 1] == string[strlen(string) - tamanho])) {
            /**
             * @brief retorno recursivo dizendo se as letras continuam iguais ou nao;
             * A cada rodada recursiva da funcao, (onde o tamanho e decrementado), e retornado se e verdadeiro que as letras sao iguais.
             */
            return Palindromo(string, (tamanho) - 1);
        }else {
            return 0;
        }
    }
    return 1;
}
