#include <stdio.h>
#include <stdlib.h>
#include "agendatarefas.h"
#include "tarefasoma.h"
#include "tarefamultiplica.h"
#include "tarefaimprime.h"

#define SOMA 'S'
#define MULTIPLICACAO 'M'
#define IMPRESSAO 'I'

#define TAM_MAX_MSG 1001

int main() {
    int numTarefas, t, prioridadeTarefa, c;
    tAgendaTarefas *agendaTarefas;
    char tipoTarefa;
    float numero1, numero2;
    int m = 0;
    char mensagem[TAM_MAX_MSG];

    printf("Digite o numero de tarefas: ");
    scanf("%d\n", &numTarefas);

    agendaTarefas = CriaAgendaDeTarefas(numTarefas);

    for (t = 0; t < numTarefas; t++) {
        scanf("%d %c ", &prioridadeTarefa, &tipoTarefa);
        
        switch(tipoTarefa) {
            case SOMA:
                scanf("%f %f\n", &numero1, &numero2);
                CadastraTarefaNaAgenda(agendaTarefas, prioridadeTarefa, CriaTarefaSoma(numero1, numero2), ExecutaTarefaSoma, DestroiTarefaSoma);
                break;
            case MULTIPLICACAO:
                scanf("%f %f\n", &numero1, &numero2);
                CadastraTarefaNaAgenda(agendaTarefas, prioridadeTarefa, CriaTarefaMultiplicar(numero1, numero2), ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
                break; 
            case IMPRESSAO:
                scanf("%[^\n]\n", mensagem);
                CadastraTarefaNaAgenda(agendaTarefas, prioridadeTarefa, CriaTarefaImprimir(mensagem), ExecutaTarefaImprimir, DestroiTarefaImprimir);
                break;
            default:
                printf("\nDigite um tipo de tarefa suportado (I/S/M))");
                scanf("%[^\n]\n", mensagem);
                t--;
                break;
        }
    }

    ExecutarTarefasDaAgenda(agendaTarefas);
    DestroiAgendaDeTarefas(agendaTarefas);

    return 0;
}