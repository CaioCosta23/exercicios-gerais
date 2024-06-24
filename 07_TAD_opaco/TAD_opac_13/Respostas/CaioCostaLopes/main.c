#include <stdio.h>
#include <stdlib.h>
#include "pad.h"

int main() {
    tPad *PAD;

    PAD = CriaPad();

    RodaPad(PAD);
    ImprimeRelatorioPad(PAD);
    LiberaPad(PAD);

    return 0;
}