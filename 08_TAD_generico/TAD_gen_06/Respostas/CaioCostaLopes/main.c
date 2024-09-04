#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrizgenerica.h"
#include "numcomplexo.h"

#define INTEIRO 0
#define FLOAT 1
#define DOUBLE 2
#define CHAR 3
#define NUMERO_COMPLEXO 4

#define IMPRIMIR 1
#define IMPRIMIR_COMPLEXO 2
#define IMPRIMIR_MULTIPLICACAO_TRANSPOSTA 3

#define CADASTRAR_MATRIZ 1
#define ENCERRAR 2

int main() {
    int numeroLinhas, numeroColunas, tipoMatriz, numeroBytesTipoElemento, operacao, andamentoPrograma;
    tMatrizGenerica *matrizGenerica, *matrizTransposta;
    tMatrizGenerica *novaMatriz = NULL;
    bool dadoAceitavel;

    while(1) {
        while (1) {
            dadoAceitavel = true;

            printf("Digite o número de linhas, colunas e o tipo da matriz (0 - inteiro, 1- float, 2 - double, 3 - char, 4 - número complexo): ");
            scanf("%d %d %d\n", &numeroLinhas, &numeroColunas, &tipoMatriz);

            switch(tipoMatriz) {
                case INTEIRO:
                    numeroBytesTipoElemento = sizeof(int);
                    matrizGenerica = CriaMatrizGenerica(numeroLinhas, numeroColunas, numeroBytesTipoElemento);
                    break;
                case FLOAT:
                    numeroBytesTipoElemento = sizeof(float);
                    matrizGenerica = CriaMatrizGenerica(numeroLinhas, numeroColunas, numeroBytesTipoElemento);
                    break;
                case DOUBLE:
                    numeroBytesTipoElemento = sizeof(double);
                    matrizGenerica = CriaMatrizGenerica(numeroLinhas, numeroColunas, numeroBytesTipoElemento);
                    break;
                case CHAR:
                    numeroBytesTipoElemento = sizeof(char);
                    matrizGenerica = CriaMatrizGenerica(numeroLinhas, numeroColunas, numeroBytesTipoElemento);
                    break;
                case NUMERO_COMPLEXO:
                    numeroBytesTipoElemento = RetornaNumBytesComplexo();
                    matrizGenerica = CriaMatrizGenerica(numeroLinhas, numeroColunas, numeroBytesTipoElemento);
                    break;
                default:
                    dadoAceitavel = false;
                    break;
            }
            if (dadoAceitavel == true) {
                break;
            }
        }
        ObtemElementoMatrizGenerica(matrizGenerica, numeroLinhas, numeroColunas);

        while (1) {
            dadoAceitavel = true;
            printf("\nDigite a operação desejada");
            printf("\n\t1 - Apenas imprimir a matriz");
            printf("\n\t2 - Converter para o tipo complexo e imprimir");
            printf("\n\t3 - Calcular e imprimir a multiplicacao da matriz pela sua transposta.");

            scanf("%d\n", &operacao);

            switch (operacao) {
                case IMPRIMIR:
                    ImprimirMatrizGenerica(matrizGenerica, ImprimeNumeroComplexo);
                    DestroiMatrizGenerica(matrizGenerica);
                    break;
                case IMPRIMIR_COMPLEXO:
                    //novaMatriz = ConverteTipoMatriz(matrizGenerica, RetornaNumBytesComplexo(), ConverteMatrizGenerica);
                    //ImprimirMatrizGenerica(novaMatriz, ImprimeNumeroComplexo);
                    ImprimirMatrizGenerica(matrizGenerica, ImprimeNumeroComplexo);
                    DestroiMatrizGenerica(matrizGenerica);
                    DestroiMatrizGenerica(novaMatriz);
                    break;
                case IMPRIMIR_MULTIPLICACAO_TRANSPOSTA:
                    matrizTransposta = MatrizTransposta(matrizGenerica);
                    novaMatriz = MultiplicaMatrizes(matrizGenerica, matrizTransposta, numeroBytesTipoElemento, MultComplexos, SomaComplexos);
                    ImprimirMatrizGenerica(novaMatriz, ImprimeNumeroComplexo);
                    DestroiMatrizGenerica(matrizGenerica);
                    DestroiMatrizGenerica(matrizTransposta);
                    DestroiMatrizGenerica(novaMatriz);
                    break;
                default:
                    dadoAceitavel = false;
                    break;
            }
            if (dadoAceitavel == true) {
                break;
            }
        }
        
        do {
            printf("\nDigite a operação desejada");
            printf("\n\t1 - Entrar com uma nova matriz");
            printf("\n\t2 - Encerrar o Programa");

            scanf("%d\n", &andamentoPrograma);
        }while((andamentoPrograma != CADASTRAR_MATRIZ) && (andamentoPrograma != ENCERRAR));

        if (andamentoPrograma == CADASTRAR_MATRIZ) {
            continue;
        }else {
            if (andamentoPrograma == ENCERRAR) {
                break;
            }
        }
    }
    return 0;
}