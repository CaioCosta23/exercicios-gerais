#ifndef _dracomania
#define _dracomania

#include "carta.h"
#include "duelo.h"

#define TAM_LISTA 1 // Tamanho da lista de cartas;
#define CADASTRAR 'C' // Opção para cadastrar uma nova carta;
#define LUTAR 'L' // Opcao para iniciar uma luta (duelo) entre duas cartas;
#define FINALIZAR 'F' // Opção para finalizar o programa;

typedef struct dracomania *tDracomania;

struct dracomania {
    tCarta *listacartas;
    int qtdcartas;
    int maxcartas;
    tDuelo *listaduelos;
    int qtdduelos;
    int maxduelos;
    int descartes;
};

/**
 * @brief Cria (aloca a memória dinamicamente) uma estrutura (do tipo ponteiro) do tipo "tDracomania" com seus dados incializados;
 * 
 * @return tDracomania Estrutura (do tipo ponteiro) do tipo "tDracomania";
 */
tDracomania CriaDracomania();

/**
 * @brief Roda o joo da Dracomania;
 * 
 * @param d Estrutura (do tipo ponteiro) do tipo "tDracomania" que contém os dados do jogo que será rodado;
 * @return tDracomania Estrurtura (do tipo ponteiro) do tipo "tDracomania" com os dados atualizados;
 */
tDracomania RodaDracomania(tDracomania d);

/**
 * @brief Imprime os dados do relatório final do jogo;
 * 
 * @param d Estrutura (do tipo ponteiro) do tipo "tDracomaia" com os dados/estatísticas finais do jogo;
 */
void ImprimeRelatorioDracomania(tDracomania d);

/**
 * @brief Libera (desaloca a memoria alocada dinamicamente) o jogo da Dracomania; 
 * 
 * @param d Estrutura (do tipo ponteiro) do tipo "tDracomainia" que será liberado;
 */
void LiberaDracomania(tDracomania d);

#endif