#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

#define TAM_MAX_NOME 50

struct Conta{
    char *nomeCliente;
    int id;
    float saldo;
    int maxTamanhoNome;
};

tConta *CriaConta() {
    tConta *conta = (tConta*)malloc(sizeof(tConta));

    if (conta == NULL) {
        printf("Erro na alocacao de memoria da conta ");
        return conta;
    }

    conta->nomeCliente = (char*)malloc(TAM_MAX_NOME * sizeof(char));
    if ((*conta).nomeCliente == NULL) {
        printf("Erro na alocacao de memoria do nome do usuário da conta ");
        DestroiConta(conta);
        return conta;
    }

    conta->id = -1;
    conta->saldo = 0;
    conta->maxTamanhoNome = TAM_MAX_NOME;

    return conta;
}

void LeConta(tConta *conta) {
    char letra;
    int l = 0;

    scanf("%d;", &conta->id);
    
    while(1){
        scanf("%c", &letra);
        
        if (letra != ';') {
            if (l == TAM_MAX_NOME) {
                conta->maxTamanhoNome += TAM_MAX_NOME;
                conta->nomeCliente = (char*)realloc((*conta).nomeCliente, (*conta).maxTamanhoNome * sizeof(char));
                if ((*conta).nomeCliente == NULL) {
                    printf("Erro na realocacao de memoria do nome do usuário da conta ");
                    DestroiConta(conta);
                    break;
                }
            }
            conta->nomeCliente[l] = letra;
            l++;
        }else {
            conta->nomeCliente[l] = '\0';
            break;
        }
    }

    scanf("%f\n", &conta->saldo);
}

float GetSaldoConta(tConta *conta) {
    return (*conta).saldo;
}

void DestroiConta(DataType conta) {
    tConta *con = (tConta*)conta;

    if (con != NULL) {
        if ((*con).nomeCliente != NULL) {
            free((*con).nomeCliente);
            con->nomeCliente = NULL;
        }
        free(con);
        con = NULL;
    }
}
