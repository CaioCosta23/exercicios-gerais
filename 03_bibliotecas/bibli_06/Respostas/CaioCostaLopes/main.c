#include "temperature_conversor.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    float temperature, result;
    char converted, to_convert;

    scanf("%d", &temperature);

    result = convert_temperature(temperature, convert_func(temperature));

    return 0;
}