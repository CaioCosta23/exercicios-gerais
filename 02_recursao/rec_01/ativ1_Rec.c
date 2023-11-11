#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO 1001


void ImprimeInvertido(char string[]);


/**
 * @brief Funcao que inverte  uma palavra do texto;
 * 
 * @param string 
 * @param l indice (psoicao) de uma letra que de uma palavra do texto que sera impressa;
 */
void InvertePalavra(char string[], int l) {
	if (l >= 0) {
		printf("%c", string[l]);
		InvertePalavra(string, (l - 1));
	}
}

int main() {
	char texto[TAMANHO_MAXIMO][TAMANHO_MAXIMO];
	int p = 0;

	while(scanf("%s", texto[p]) == 1) {
		ImprimeInvertido(texto[p]);
		printf(" ");
	}

	return 0;
}


/**
 * @brief imprime cada string (palavra) de tras para frente;
 * 
 * @param string palavra lida durante a execucao do programa
 */
void ImprimeInvertido(char string[]) {
	int l;

	l = strlen(string) - 1;

	InvertePalavra(string, l);
}
