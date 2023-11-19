#include "temperature_conversor.h"
#include <stdio.h>
#include <stdlib.h>

char unit_upper(char converted) {
    return converted = converted - ('a' - 'A');
}

int main() {
    float temperature, result;
    char converted, to_convert;

    scanf("%f %c %c", &temperature, &to_convert, &converted);

    if ((to_convert == 'c') && (converted == 'k')) {
        result = convert_temperature(temperature, convert_celsius_to_kelvin);
    }
    if ((to_convert == 'c') && (converted == 'f')) {
        result = convert_temperature(temperature, convert_celsius_to_fahrenheit);
    }
    if ((to_convert == 'k') && (converted == 'c')) {
        result = convert_temperature(temperature, convert_kelvin_to_celsius);
    }
    if ((to_convert == 'k') && (converted == 'f')) {
        result = convert_temperature(temperature, convert_kelvin_to_fahrenheit);
    }
    if ((to_convert == 'f') && (converted == 'c')) {
        result = convert_temperature(temperature, convert_fahrenheit_to_celsius);
    }
    if ((to_convert == 'f') && (converted == 'k')) {
        result = convert_temperature(temperature, convert_fahrenheit_to_kelvin);
    }
    converted = unit_upper(converted);

    printf("Temperature: %.2f%c", result, converted);

    if ((converted == 'C') || (converted == 'F')) {
        printf("º");
    }

    return 0;
}