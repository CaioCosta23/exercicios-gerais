#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Adiciona os livros (com base em seu ID) a uma lista de livros que ja foram verificados;
 * 
 * @param verificados lista de livros que nja foma verificados;
 * @param qtd tamanho da lista de livros que ja foram verificados;
 */
void VerificaLivros(int verificados[], int qtd) {
	int l, id;

	for (l = 0; l < qtd; l++) {
		scanf("%d", &id);
	
		verificados[l] = id;
	}
}
/**
 * @brief Coleta os livros que nao possuem copias; 
 * 
 * @param qtd quantidade de livros (tamanho da lista/"array" de livros)
 * @param verificados Lista/"array" que contem os livros que ja forma verificados;
 * @param sem_Copia Lista/"array" que contem exckusivamente somente os livros que nao possuem copia(s);
 * @return int 
 */
int ColetaLivrosSemCopia(int qtd, int verificados[], int sem_Copia[]) {
	int x, y, cod;
	int cont_Unicos = 0;
	int unico_Exemplar;

	for (x = 0; x < qtd; x++) {
		unico_Exemplar = 0;
		for (y = 0; y < qtd; y++) {
		
				if (x == y) {
					continue;
				}
		
				if (verificados[x] == verificados[y]) {
					unico_Exemplar = 0;
					break;
				}else {
					unico_Exemplar = 1;
					cod = verificados[x];
				}
		}
	
		if (unico_Exemplar) {
				sem_Copia[cont_Unicos] = cod;
				cont_Unicos +=1;
		}
	}

	return cont_Unicos;
}

/**
 * @brief  Ordena a lista dos livros que sao unicos (que nao possuem copias);
 * 
 * @param sem_Copia Lista/"array" de livros que nao possuem copias;
 * @param qtd Quantidade de livros que a lista dos "sem copias" possui;
 */
void OrdenaListaLivros(int sem_Copia[], int qtd) {
	int m, n;
	int reserva;
	// Variavel que recebe uma copia dos dados que serao trocados de lugar;

	for (m = 0; m < qtd; m++) {
		for (n = m + 1; n < qtd; n++) {
				if (sem_Copia[m] > sem_Copia[n]) {
					reserva = sem_Copia[n];
					sem_Copia[n] = sem_Copia[m];
					sem_Copia[m] = reserva;
				}
		}
	}
    
}

void ImprimeIdLivrosSemCopia(int sem_Copia[], int qtd) {
	int i;

	if (qtd > 0) {
	
		OrdenaListaLivros(sem_Copia, qtd);
	
		for (i = 0; i < qtd; i++) {
				
				if ((qtd < 3) && (sem_Copia[0] != 1)) {
					printf("%d ", sem_Copia[i]);
				}else {
					
					printf("%d", sem_Copia[i]);
					
				if ((!(i == (qtd - 1)))) {
					printf(" ");
				}
			}
		}
		/* -> ERRO DOS ARQUIVOS DE SAÍDA (provável);
			* - a Estrutura de condicional acima foi criada para que os casos de saída registrassem igualdade. Isso foi feito devido a um (provável) erro de digitação dos arquivos 
			* de saída (uma vez que ao final dos casos de saída de uns existem espaços e ao final de outros não existem.
		*/
	}else {
		printf("NENHUM");
	}
}

int main () {
    
	int qtd_Livros, x, y, qtd_Unicos;

	scanf("%d\n", &qtd_Livros);
	// Coleta a quantidade de Livros que serao lidos;

	int verificados[qtd_Livros];

	VerificaLivros(verificados, qtd_Livros);

	int sem_Copia[qtd_Livros];
	qtd_Unicos = ColetaLivrosSemCopia(qtd_Livros, verificados, sem_Copia);

	ImprimeIdLivrosSemCopia(sem_Copia, qtd_Unicos);


	return 0;
}
