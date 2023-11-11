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
        	}
        	printf("\n");
    	}

    	return 0;
}
