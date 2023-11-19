#include "temperature_conversor.h"
#include <stdio.h>
#include <stdlib.h>

float convert_celsius_to_kelvin(float temperature) {
    return temperature + 273.0;
}

float convert_celsius_fahrenheit(float temperature) {
    return (temperature * 1.8) + 32.0;
}

float convert_kelvin_to_celsius(float temperature) {
    return temperature - 273.0;
}

float convert_kelvin_to_fahrenheit(float temperature) {
    int c;

    c = convert_kelvin_to_celsius(temperature);

    return convert_celsius_to_fahrenheit(c);
}

float convert_fahrenheit_to_celsius(float temperature) {
    return (temperature - 32.0) / 1.8;
}

float convert_fahrenheit_to_kelvin(float temperature) {
    int c;

    c = convert_fahrenheit_to_celsius(temperature);

    return convert_celsius_to_kelvin(c);
}

float convert_func(temperature) {
    char to_convert, converted;
    
    scanf("%c %c\n", &to_convert, &converted);

    if ((to_convert == 'c') && (converted == 'k')) {
        return convert_celsius_to_kelvin(temperature);
    }
    if ((to_convert == 'c') && (converted == 'f')) {
        return convert_celsius_to_fahrenheit(temperature);
    }
    if ((to_convert == 'k') && (converted == 'c')) {
        return convert_kelvin_to_celsius(temperature);
    }
    if ((to_convert == 'k') && (converted == 'f')) {
        return convert_kelvin_to_fahrenheit(temperature);
    }
    if ((to_convert == 'f') && (converted == 'c')) {
        return convert_fahrenheit_to_celsius(temperature);
    }
    if ((to_convert == 'f') && (converted == 'k')) {
        return convert_fahrenheit_to_kelvin(temperature);
    }
}

float convert_temperature(float temperature, float convert_func(float temperature)) {
    return convert_func(temperature);
}