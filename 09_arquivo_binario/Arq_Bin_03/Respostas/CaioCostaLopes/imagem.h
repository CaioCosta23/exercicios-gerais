#ifndef _IMAGEM_H
#define _IMAGEM_H

typedef enum {
    FLOAT = 0, 
    INT = 1    
} Tipo;

typedef struct tImagem Imagem;

/**
 * @brief Cria (aloca a memória dinamicamente) e lê uma imagem (altura, largura e tipo de dados e em seguida, dados da imagem) de um arquivo binário;
 * 
 * @param caminho Caminho (diretório) para a imagem procurada;
 * @return Ponteiro para a estrutura do tipo "Imagem" que contém os dados atualizados da imagem;
 */
Imagem *LerImagem(const char *caminho);

/**
 * @brief Obtém o número de bytes de uma imagem;
 * 
 * @param img Ponteiro para a estrutura do tipo "Imagem" que contém os dados atualizados da imagem;
 * @return Número de bytes lidos do arquivo binário que contém os dados da imagem;
 */
int ObterNumeroBytesLidos(Imagem *img);

/**
 * @brief Imprime uma imagem.
 * 
 * @param img Ponteiro para a estrutura do tipo "Imagem" que contém os dados atualizados da imagem;
 */
void ImprimirImagem(Imagem *img);

/**
 * @brief Destrói (desaloca a memória alocada dinamicamente de) uma imagem;
 * 
 * @param img Ponteiro para a estrutura do tipo "Imagem" que contém os dados atualizados da imagem (que será destruída);
 */
void DestruirImagem(Imagem *img);

#endif