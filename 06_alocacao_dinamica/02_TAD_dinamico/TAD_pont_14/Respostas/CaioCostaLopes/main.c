#include <stdio.h>
#include <stdlib.h>
#include "nba.h"

int main() {
    tNBA nba;

    nba = CriaNBA();

    if (nba != NULL) {
        nba = RodaNBA(nba);
        ImprimeRelatorioNBA(nba);
    }

    LiberaNBA(nba);
}