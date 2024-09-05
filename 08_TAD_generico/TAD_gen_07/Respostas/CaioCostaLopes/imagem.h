#ifndef _IMAGE_H
#define _IMAGE_H

typedef enum {
    FLOAT = 0, 
    INT = 1    
} Tipo;

typedef struct tImagem Imagem;

/**
 * @brief Função para criar uma imagem.
 * 
 * @param altura Altura da imagem;
 * @param largura Largura da imagem;
 * @param tipo Tipo de dados que a imagem receberá;
 * 
 * @return Ponteiro para a estrutura do tipo "Imagem" que contém os campos de dados inicializados da imagem;
 */
Imagem *CriarImagem(int altura, int largura, Tipo tipo);

/**
 * @brief Lê uma imagem (altura, largura e tipo de dados e em seguida, dados da imagem);
 * 
 * @return Ponteiro para a estrutura do tipo "Imagem" que contém os dados atualizados da imagem;
 */
Imagem *LerImagem();

/**
 * @brief Obtém a altura de uma imagem;
 * 
 * @param img Ponteiro para a estrutura do tipo "Imagem" que contém os dados atualizados da imagem;
 * 
 * @return Altura da imagem;
 */
int ObterAltura(Imagem *img);

/**
 * @brief Obtém a largura de uma imagem;
 * 
 * @param img Ponteiro para a estrutura do tipo "Imagem" que contém os dados atualizados da imagem;
 * @return Largura da imagem;
 */
int ObterLargura(Imagem *img);

/**
 * @brief Obtém o tipo de dados de uma imagem;
 * 
 * @param img Ponteiro para a estrutura do tipo "Imagem" que contém os dados atualizados da imagem;
 * 
 * @return Tipo de dados da imagem;
 */
Tipo ObterTipoImagem(Imagem *img);

/**
 * @brief Obtém os dados de uma imagem;
 * 
 * @param img Ponteiro para a estrutura do tipo "Imagem" que contém os dados atualizados da imagem;
 * 
 * OBS: Note que a imagem é uma matriz, mas os dados podem ser armazenados de forma linear (vetor);
 * @return Ponteiro para a estrutura do tipo "void" (vazio) que contém os dados atualizados da imagem;
 */
void *ObterDadosImagem(Imagem *img);

/**
 * @brief Imprimer uma imagem.
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