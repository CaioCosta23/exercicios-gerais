#include <stdio.h>
#include <stdlib.h>

int LeVetor(int tamanho_Vetor);
void ImprimeSomaElementosPares(int soma);


/**
 * @brief Funcao que vai somar os elementos pares de cada vetor de numeros inteiros recebidos;
 * 
 * @param vet vetor de numeros inteiros;
 * @param num_Elementos quantidade de numeros do vetor;
 * @return int retorna RECURSIVAMENTE (enquanto houver elementos a serem analisados), a soma de todos os elementos pares do vetor;
 */
int SomaElementosPares(int vet[], int num_Elementos) {
    
    if (num_Elementos > 0) {
        if (vet[num_Elementos - 1] % 2 == 0) {
            return vet[num_Elementos - 1] + SomaElementosPares(vet, (num_Elementos - 1));
        }
        return SomaElementosPares(vet, (num_Elementos - 1));
    }
    return 0;
}


int main() {
    int qtd, v, tamanho_Vetor;
    int soma = 0;
    
    // Valor que determina a quantidade de vetores que serao lidos;
    scanf("%d", &qtd);
    
    for (v = 0; v < qtd; v++) {
        scanf("%d", &tamanho_Vetor);
        
        soma = LeVetor(tamanho_Vetor);
        
        ImprimeSomaElementosPares(soma);
  
    	printf("\n");
    }

    return 0;
}


/**
 * @brief Leitura de cada todos os vetores de números inteiros;
 * 
 * @param tamanho_Vetor quantidadade de numeros inteiros de cada vetor;
 * @return int retorna a soma propriamente dita dos valores pares do vetor;
 */
int LeVetor(int tamanho_Vetor) {
    int vetor[tamanho_Vetor];
    int i, soma;
    
    for(i = 0; i < tamanho_Vetor; i++) {
        scanf("%d", &vetor[i]);
    }
    soma = SomaElementosPares(vetor, tamanho_Vetor);
    
    return soma;
}

/**
 * @brief  Imprime na tela a soma obtida;
 * 
 * @param soma somatorio dos numeris pares de cada vetor;
 */
void ImprimeSomaElementosPares(int soma) {
    printf("%d", soma);
}
