#include <stdio.h>
#include <stdlib.h>

#define QTD_MOVIMENTOS 4
#define CIMA 'C'
#define BAIXO 'B'
#define DIREITA 'D'
#define ESQUERDA 'E'
#define ELEMENTOS_COORDENADAS 2

int RealizaMovimentos(int linhas, int colunas, int mapa[linhas][colunas], char movimentos[],
                      int xi, int yi, int xf, int yf, int trilha[linhas * colunas][ELEMENTOS_COORDENADAS]);

void ImprimeTrilha(int linhas, int colunas, int trilha[linhas * colunas][ELEMENTOS_COORDENADAS],
        int movimentos_Relizados);


// -> Função auxiliar da função "main";
// - Forma a matriz que será usada como mapa do jogo;
void FormaMapa(int linhas, int colunas, int mapa[linhas][colunas]) {
	int l, c;

	for (l = 0; l < linhas; l++) {
		for (c = 0; c < colunas; c++) {
			scanf("%d", &mapa[l][c]);
		}
	}
}

/**
 * @brief Função auxiliar de "RealizaMovimentos": Verifica se o entorno do personagem do jogador está livre, ou seja, verifica se ele pode a casa ao
 * lado, ou acim aou abaixo está livre para realizar movimento na direção desejada; 
 * @param posicao posicao (indice da matriz - mapa);
 * @return int posicao (dependendo de onde esta mesma funcao foi chamada, pode ser a linha ou a coluna);
 */
int VerificaEntorno(int posicao) {
	return posicao;
}

/**
 * @brief Função auxiliar de "RealizaMovimentos": Registra em um Vetor (Matriz, nesse caso)  as posições já percorridas pelo jogador no mapa;
 * 
 * @param linhas numero de linhas da matriz (mapa);
 * @param colunas numero de colunas da matriz (mapa);
 * @param trilha posicao (x,y) pela qual o jogador passou;
 * @param cont_Movimentos conta a quantidade de movimentos realizadas pelo jogador;
 * @param x_Atual posicao X (linha) em que o jogador atualmente esta;
 * @param y_Atual posicao Y (coluna) em que o jogador atualmente esta;
 */
void AdicionaNaTrilha(int linhas, int colunas, int trilha[linhas * colunas][ELEMENTOS_COORDENADAS],
                      int cont_Movimentos, int x_Atual, int y_Atual) {
    
	int t;

	for (t = 0; t < ELEMENTOS_COORDENADAS; t++) {
		if (t == 0) {
			trilha[cont_Movimentos][t] = x_Atual + 1;
			// A primeira rodada é resposável por coletar a coordenada X da posição do jogador;
		}else {
			trilha[cont_Movimentos][t] = y_Atual + 1;
			// A segunda rodada é resposável por coletar a coordenada Y da posição do jogador;
		}
	}
	/* OBS: Cada posição é acrescida de uma unidade para compensar a forma que é geralmente registrada as posições em uma matriz.
		* Exemplo: o índice da primeira linha (linha 1) de uma matriz é regisrada como 0 (por isso é necessária a correção - devido aos resultados dos arquivos de saída);
	*/
}

/**
 * @brief Função auxiliar de "RealizaMovimentos": Verifica se o jogador já passou pela posição ao qual irá fazer o movimentos;
 * 
 * @param linhas numero de linhas da matriz (mapa);
 * @param colunas numero de colunas da matriz (mapa);
 * @param trilha posicao (x,y) pela qual o jogador passou;
 * @param x posicao X (linha) que o jogador ocupara;
 * @param y posicao Y (coluna) que o jogador ocupara;
 * @param cont_Movimentos conta a quantidade de movimentos realizadas pelo jogador;
 * @return int retorna verdadeiro se o jogador já passou pela posição, e falso se não;
 */
int AnalisaRastro(int linhas, int colunas, int trilha[linhas * colunas][ELEMENTOS_COORDENADAS],
                  int x, int y, int cont_Movimentos) {
    
	int r, e;
	int passou_X, passou_Y;

	for (r = 0; r < cont_Movimentos; r++) {
		passou_X = 0;
		passou_Y = 0;
		
		for (e = 0; e < ELEMENTOS_COORDENADAS; e++) {
			if (e == 0) {
				if (x == (trilha[r][e] - 1)) {
					passou_X = 1;
				}
			}else {
				if (y == (trilha[r][e] - 1)) {
					passou_Y = 1;
				}
			}
		}
	
		if ((passou_X) && (passou_Y)) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int linhas, colunas, x_Inicial, y_Inicial, x_Final, y_Final, qtd_Posicoes;

	scanf("%d %d", &linhas, &colunas);

	int mapa[linhas][colunas];
	char movimentos[QTD_MOVIMENTOS + 1];

	FormaMapa(linhas, colunas, mapa);

	scanf("%d %d", &x_Inicial, &y_Inicial);
	scanf("%d %d", &x_Final, &y_Final);

	x_Inicial -= 1;
	y_Inicial -= 1;
	x_Final -= 1;
	y_Final -= 1;
	// Compensa a diferença entre os registros da matriz e como é feito o resgistro real de cada índice de posição;

	int trilha[linhas * colunas][ELEMENTOS_COORDENADAS];

	AdicionaNaTrilha(linhas, colunas, trilha, qtd_Posicoes, x_Inicial, y_Inicial);

	scanf("%s", movimentos);
	// Registra as os tipos de movimentos a serem realizados (em um vetor - por ordem de prioridade)

	qtd_Posicoes = RealizaMovimentos(linhas, colunas, mapa, movimentos, x_Inicial, y_Inicial, x_Final, y_Final, trilha);

	ImprimeTrilha(linhas, colunas, trilha, qtd_Posicoes);

	return 0;
}


/**
 * @brief realiza o movimento do jogador dentro do tabuleiro/mapa (caso as condicoes para a movimentacao sejam satisfeitas)
 * 
 * @param linhas numero de linhas da matriz (mapa); 
 * @param colunas numero de colunas da matriz (mapa);
 * @param mapa matriz que forma o tabuleiro/mapa;
 * @param movimentos tipos de movimentos que o jogador pode fazer no tabuleiro (na vertical e na horizontal - APENAS);
 * @param xi posicao X (linha) inicial do jogador;
 * @param yi posicao Y (coluna) inicial do jogador;
 * @param xf posicao X (linha) final do jogador;
 * @param yf posicao Y (coluna) final do jogador;
 * @param trilha posicao (x,y) pela qual o jogador passou;
 * @return int retorna a quantidade atual de movimentos que o jogador fez;
 */
int RealizaMovimentos(int linhas, int colunas, int mapa[linhas][colunas], char movimentos[],
                      int xi, int yi, int xf, int yf, int trilha[linhas * colunas][ELEMENTOS_COORDENADAS]) {
    
	int x_Atual = xi, y_Atual = yi;
	int v;
	int cont_Movimentos = 1;
	// Contabiliza a quantidade de movimentos (usado para formar o vetor que armazena a trilha);
	int avancou;

	while (1) {
		avancou = 0;
		
		for (v = 0; v < QTD_MOVIMENTOS; v++) {
			// Verifica em qual direção será feito o movimento;
				if (movimentos[v] == CIMA) {
					if (x_Atual != 0) {
					// Verifica se o jogador já não está na borda de cima (evitando que se caso ele tente se mover para cima, ele não saia do mapa);
					
							if (!(VerificaEntorno(mapa[x_Atual - 1][y_Atual]))) {
								if (!(AnalisaRastro(linhas, colunas, trilha, (x_Atual - 1), y_Atual, cont_Movimentos))) {
								// Analisa se o jogador já passou pela posição. Caso não, ele poderá realizar o movimento;
										x_Atual = x_Atual - 1;
										avancou = 1;
										AdicionaNaTrilha(linhas, colunas, trilha, cont_Movimentos, x_Atual, y_Atual);
										cont_Movimentos += 1;
										break;
								}else {
										continue;
								}
							}else {
								continue;
							}
					}
					//OBS: Os comentários da linha de comando acima também valem para os próximos abaixo (seguindo cada um a sua ordem de movimentação);
					
				}else {
					if (movimentos[v] == BAIXO) {
					// Verifica se o jogador já não está na borda de baixo (evitando que se caso ele tente se mover para baixo, ele não saia do mapa);
					
							if (x_Atual != (linhas - 1)) {
								if (!(VerificaEntorno(mapa[x_Atual + 1][y_Atual]))) {
										if (!(AnalisaRastro(linhas, colunas, trilha, (x_Atual + 1), y_Atual, cont_Movimentos))) {
											x_Atual = x_Atual + 1;
											avancou = 1;
											AdicionaNaTrilha(linhas, colunas, trilha, cont_Movimentos, x_Atual, y_Atual);
											cont_Movimentos += 1;
											break;
										}else {
											continue;
										}
								}else {
										continue;
								}
							}
					}else {
							if (movimentos[v] == ESQUERDA) {
								if (y_Atual != 0) {
								// Verifica se o jogador já não está na borda de esquerda (evitando que se caso ele tente se mover para esquerda, ele não saia do mapa);
								
										if (!(VerificaEntorno(mapa[x_Atual][y_Atual - 1]))) {
											if (!(AnalisaRastro(linhas, colunas, trilha, x_Atual, (y_Atual - 1), cont_Movimentos))) {
													y_Atual = y_Atual - 1;
													avancou = 1;
													AdicionaNaTrilha(linhas, colunas, trilha, cont_Movimentos, x_Atual, y_Atual);
													cont_Movimentos += 1;
													break;
											}else {
													continue;
											}
										}else {
											continue;
										}
								}
							}else {
								if (movimentos[v] == DIREITA) {
										if (y_Atual != (colunas - 1)) {
										// Verifica se o jogador já não está na borda da direita (evitando que se caso ele tente se mover para direita, ele não saia do mapa);
										
											if (!(VerificaEntorno(mapa[x_Atual][y_Atual + 1]))) {
													if (!(AnalisaRastro(linhas, colunas, trilha, x_Atual, (y_Atual + 1), cont_Movimentos))) {
														y_Atual = y_Atual + 1;
														avancou = 1;
														AdicionaNaTrilha(linhas, colunas, trilha, cont_Movimentos, x_Atual, y_Atual);
														cont_Movimentos += 1;
														break;
													}else {
														continue;
													}
											}else {
													continue;
											}
										}
								}
							}
					}
				}
		}
		if (!(avancou) || ((x_Atual == xf) && (y_Atual == yf))) {
				break;
		}
	}
	return cont_Movimentos;
}

/**
 * @brief 
 * 
 * @param linhas posicao X (linha) que o jogador ocupou;
 * @param colunas posicao Y (coluna) que o jogador ocupou;
 * @param trilha posicao (x,y) pela qual o jogador passou;
 * @param qtd_Posicoes quantidade de posicoes que o jogador passou;
 */

void ImprimeTrilha(int linhas, int colunas, int trilha[linhas * colunas][ELEMENTOS_COORDENADAS],
                   int qtd_Posicoes) {
    
	int p, c;

	for (p = 0; p < qtd_Posicoes; p++) {
		printf("(");
		
		for (c = 0; c < ELEMENTOS_COORDENADAS; c++) {
				printf("%d", trilha[p][c]);
		
				if (c == 0) {
					printf(",");
				}
				
				// A cada 2 rodadas (2 elementos - que representam um "x" e um "y" de coordenadas) é impresso a posição em que o jogador passou;
		}
		printf(") ");
	}
}
