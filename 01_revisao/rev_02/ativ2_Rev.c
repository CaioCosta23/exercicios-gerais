#include <stdio.h>
#include <stdlib.h>

int main() {
	int qtd, n, c;
	int cont = 0;

	scanf("%d", &qtd);

	for (n = 1; n <= qtd; n++) {
		for (c = 1; c <= n; c++) {
				cont++;
				printf("%d ", cont);
				// A cada rodada do loop de fora, imprime na tela a quantidade de vezes que o loop de dentro rodou.
		}
		printf("\n");
	}

	return 0;
}
