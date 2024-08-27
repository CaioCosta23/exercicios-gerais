#include <stdio.h>
#include <stdlib.h>
#include "banco.h"
#include "vector.h"

int main() {
    tBanco *banco;

    banco = CriaBanco();
    
    LeBanco(banco);
    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);

    return 0;
}