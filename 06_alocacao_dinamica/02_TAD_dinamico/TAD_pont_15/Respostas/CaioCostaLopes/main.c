#include <stdio.h>
#include <stdlib.h>
#include "dracomania.h"

int main() {
    tDracomania dracomania;

    dracomania = CriaDracomania();
    dracomania = RodaDracomania(dracomania);
    IMprimeRelatorioDracomania(dracomania);
    LiberaDracomania(dracomania);

    return 0;
}