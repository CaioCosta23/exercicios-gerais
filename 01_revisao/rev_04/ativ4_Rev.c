#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASE 8

int FormaNumeroOctal(int octal, int resto, int cont_Digitos) {
    
    	octal = octal + resto * (pow(10, cont_Digitos));
    	/* 
    	 * - Forma o número octal de acordo com a quantidade de digitos analisados, (ou seja, se só tiverem dois digitos que tiverem sido "achados" - ou seja, foram feitas duas divisões sucessivas -
    	 * então forma os dois digitos por enquanto achados);
    	*/
    
    	return octal;
}

int main() {
    	int num, resto;
    	int cont_Digitos = 0, octal = 0;
    
    	scanf("%d", &num);
    
    	while (num != 0) {
        	resto = num % BASE;
        	// Coleta os restos das DIVISÕES SUCESSIVAS (método de transformação de Decimal para Octal - utilizado nesse caso);
        	num = num / BASE;
        	// Atualiza o número que será dividido em toda rodada;
        
        	octal = FormaNumeroOctal(octal, resto, cont_Digitos);
        	// Forma o octal de rodada em rodada;
        
        	cont_Digitos += 1;
        	// Registra quantos digitos o número possui (de rodada em rodada);
    	}
    
    	printf("%d", octal);

    	return 0;
}
