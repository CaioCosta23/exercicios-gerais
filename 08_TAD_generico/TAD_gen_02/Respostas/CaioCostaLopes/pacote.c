#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

struct pacote {
    void *vetor;
    int tamanhoVetor;
    int valor;
    Type tipoVetor;
};

tPacote *CriaPacote(Type type, int numElem) {
    tPacote *pacote = (tPacote*)malloc(sizeof(tPacote));

    if (pacote == NULL) {
        printf("Erro na alocacao de memoria do pacote! ");
        return pacote;
    }

    pacote->valor = 0;
    pacote->tamanhoVetor = numElem;

    if (type == CHAR) {
        pacote->tipoVetor = CHAR;
        pacote->vetor = (char*)malloc(((*pacote).tamanhoVetor + 1) * sizeof(char));
        if ((*pacote).vetor == NULL) {
            printf("Erro na alocacao de memoria do vetor (de caracteres) do pacote ");
            DestroiPacote(pacote);
        }
        // Inicializa o vetor com caractere nulo em caso de segurança (caso o vetor ao longo do programa não receba dados);
        for (int i = 0; i < (*pacote).tamanhoVetor; i++) {
            ((char*)pacote->vetor)[i] = '\0';
        }
    }else {
        if (type == INT) {
            pacote->tipoVetor = INT;
            pacote->vetor = (int*)malloc((*pacote).tamanhoVetor * sizeof(int));
            if ((*pacote).vetor == NULL) {
                printf("Erro na alocacao de memoria do vetor (de inteiros) do pacote ");
                DestroiPacote(pacote);
            }
            // Inicializa o vetor com caractere nulo em caso de segurança (caso o vetor ao longo do programa não receba dados);
            for (int i = 0; i < (*pacote).tamanhoVetor; i++) {
                ((int*)pacote->vetor)[i] = 0;
            }
        }
    }
    return pacote;
}

void LePacote(tPacote *pac) {
    int v;
    printf("\nDigite o conteúdo do vetor/mensagem: ");
    if ((*pac).tipoVetor == CHAR) {
        scanf("%[^\n]\n", ((char*)pac->vetor));
    }else {
        if ((*pac).tipoVetor == INT) {
            for (v = 0; v < (*pac).tamanhoVetor; v++) {
                scanf("%d", &((int*)pac->vetor)[v]);
            }
        }
    }
}

void CalculaSomaVerificacaoPacote(tPacote *pac) {
    int v;

    if ((*pac).tipoVetor == CHAR){
        for (v = 0; v < (*pac).tamanhoVetor; v++){
            pac->valor += (int)((char*)(*pac).vetor)[v];
        }
    }else {
        if ((*pac).tipoVetor == INT){
            for (v = 0; v < (*pac).tamanhoVetor; v++){
                pac->valor += ((int*)(*pac).vetor)[v];
            }    
        }
    }
}

void ImprimePacote(tPacote *pac) {
    int v;

    CalculaSomaVerificacaoPacote(pac);

    if ((*pac).valor > 0) {
        printf("%d", (*pac).valor);
        if ((*pac).tipoVetor == CHAR) {
            printf(" %s", ((char*)(*pac).vetor));
        }else {
            if ((*pac).tipoVetor == INT) {
                for (v = 0; v < (*pac).tamanhoVetor; v++) {
                    printf(" %d", ((int*)pac->vetor)[v]);
                }
            }
        }
        printf("\n");
    }
}

void DestroiPacote(tPacote *pac) {
    if (pac != NULL) {
        if ((*pac).vetor != NULL) {
            free((*pac).vetor);
            pac->vetor = NULL;
        }
        free(pac);
        pac = NULL;
    }
}