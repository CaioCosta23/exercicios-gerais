#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    	float x, y, raio, disp_X, disp_Y, disp_Raio;
    	float distancia = 0.00;
		
    	scanf("%f %f %f\n", &x, &y, &raio);
    	scanf("%f %f %f", &disp_X, &disp_Y, &disp_Raio);
    
    	distancia = sqrt((pow((x - disp_X), 2)) + (pow((y - disp_Y), 2)));
    	// Calcula a distância entre dois pontos (nesse caso, a distancia entre o raio do alvo e o raio do disparo);
    
    	if (distancia < 0) {
        	distancia = distancia * (-1.00);
    	}
    
    	if (distancia > (raio + disp_Raio)) {
        	printf("ERROU");
    	}else {
        	printf("ACERTOU");
    	}

    	return 0;
}
