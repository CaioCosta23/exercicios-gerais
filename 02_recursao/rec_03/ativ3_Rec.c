#include <stdio.h>
#include <stdlib.h>


int LeVetor(int tamanho, int num_Procurado);
void ImprimeNumeroOcorrenciasProcurado(int qtd_Ocorrencias);


/**
 * @brief Funcao que conta o quantas vezes um numero apareceu dentro de um mesmo vetor; 
 * 
 * @param vet vetor (de inteiros) que sera recebido;
 * @param num_Elementos quantidade de numeros que o vetor possui;
 * @param numero_Procurado numero que sera procurado dentrio do vetor;
 * @return int retorna, RECURSIVAMENTE, cada vez que o numero desejado e acahdo no vetor, onde ao fim do vetor, ele retorna o somatorio de vezes que o
 * numero foi achado;
 */
int ContaOcorrencias(int vet[], int num_Elementos, int numero_Procurado) {
    
    if (num_Elementos > 0) {
        return (vet[num_Elementos - 1] == numero_Procurado) + 
                ContaOcorrencias(vet, (num_Elementos - 1), numero_Procurado);
    }
    
    return 0;
}


int main() {
    int qtd, v, tamanho_Vetor, qtd_Procurado, num_Procurado;
    
    scanf("%d", &qtd);
    
    for (v = 0; v < qtd; v++) {
        scanf("%d %d", &num_Procurado, &tamanho_Vetor);
        
        qtd_Procurado = LeVetor(tamanho_Vetor, num_Procurado);
        
        ImprimeNumeroOcorrenciasProcurado(qtd_Procurado);
        
        printf("\n");
    }

    return 0;
}
/**
 * @brief Realiza a leitura de cada numero e aloca dentro do vetor;
 * 
 * @param tamanho tamanho padrao (maximo, passado via entrada pelo usuario) do vetor (de inteiros);
 * @param num_Procurado numero que sera procurado dentro do vetor;
 * @return int quantodade de vezes que o numero procurado apareceu dentro do vetor;
 */
int LeVetor(int tamanho, int num_Procurado) {
    int i, qtd_Procurado;
    int vetor[tamanho];
    
    for (i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
    qtd_Procurado = ContaOcorrencias(vetor, tamanho, num_Procurado);
    
    return qtd_Procurado;
}
/**
 * @brief funcao que vai imprimir na tela (de saida) a quantidade (numero) de vezes que o numero procurado apareceu no vetor;
 * 
 * @param qtd_Procurado quantidade de ocorrencias do numero procurado dento do vetor;
 */
void ImprimeNumeroOcorrenciasProcurado(int qtd_Procurado) {
    printf("%d", qtd_Procurado);
}

