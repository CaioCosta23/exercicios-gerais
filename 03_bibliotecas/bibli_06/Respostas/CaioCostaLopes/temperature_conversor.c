#include "temperature_conversor.h"
#include <stdio.h>
#include <stdlib.h>

float convert_celsius_to_kelvin(float temperature) {

    return temperature + 273.15;
}

float convert_celsius_to_fahrenheit(float temperature) {
    return (temperature * 1.80) + 32.00;
}

float convert_kelvin_to_celsius(float temperature) {
    return temperature - 273.15;
}

float convert_kelvin_to_fahrenheit(float temperature) {
    float c;

    c = convert_kelvin_to_celsius(temperature);

    return convert_celsius_to_fahrenheit(c);
}

float convert_fahrenheit_to_celsius(float temperature) {
    return (temperature - 32.00) / 1.80;
}

float convert_fahrenheit_to_kelvin(float temperature) {
    float c;

    c = convert_fahrenheit_to_celsius(temperature);

    return convert_celsius_to_kelvin(c);
}

float convert_temperature(float temperature, float convert_func(float temperature)) {
    return convert_func(temperature);
}