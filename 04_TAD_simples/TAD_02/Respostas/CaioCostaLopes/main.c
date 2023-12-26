#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"

int main() {
    tEleicao eleicao;

    eleicao = InicializaEleicao();
    eleicao = RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);
}