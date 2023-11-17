#include "esfera_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {
    float R;

    scanf("%f", &R);

    printf("Area: %.2f\n", calcula_area(R));
    printf("Volume: %.2f", calcula_volume(R));

    return 0;
}