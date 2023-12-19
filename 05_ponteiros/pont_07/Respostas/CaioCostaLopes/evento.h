#ifndef EVENTOS_H
#define EVENTOS_H

#define MAX_EVENTOS 10

typedef struct {
    char nome [50]; // Nome do evento;
    int dia; // Dia do evento;
    int mes; // Mês do evento
    int ano; // Ano do evento;
}Evento;

/**
 * @brief Cadastra um novo evento no calendário e o insere na próxima posicao do array (lista);
 * 
 * @param eventos Array (lista) de eventos onde o novo evento será cadastrado;
 * @param numEventos Ponteiro para o numero atual de eventos cadastrados;
 */
void cadastrarEvento(Evento eventos[], int *numEventos);

/**
 * @brief Exibe todos os eventos cadastrados no calendário;
 * 
 * @param eventos Array (lista) de eventos a serem exibidos;
 * @param numEventos Ponteiro para o número total de eventos cadastrados que serão exibidos;
 */
void exibirEventos(Evento eventos[], int *numEventos);

/**
 * @brief Troca a data de um evento específico do calendário;
 * 
 * @param eventos Array (lista) de eventos em que o evento será modificado;
 * @param numEventos Ponteiro para o número total de eventos cadastrados;
 */
void trocarDataEvento(Evento eventos[], int *numEventos);

/**
 * @brief Troca a posicao de dois eventos, a partir do índice, dentro do array (lista) de eventos;
 * 
 * @param eventos Array (lista) de eventos onde a troca será realizada;
 * @param indiceA Ponteiro para o primeiro indice;
 * @param indiceB Ponteiro para o segundo índice;
 * @param numEventos Ponteiro para o número total de eventos cadastrados;
 */
void trocarIndicesEventos(Evento eventos[], int *indiceA, int *indiceB, int *numEventos);

#endif