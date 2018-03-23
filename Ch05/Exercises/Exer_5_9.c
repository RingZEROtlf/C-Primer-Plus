#include <stdio.h>
void Temperature(double fahrenheit_temperature);
int main()
{
    double fahrenheit_temperature;
    while(1) {
        printf("Please enter Fahrenheit temperature: ");
        if(scanf("%lf", &fahrenheit_temperature) != 1) break;
        Temperature(fahrenheit_temperature);
    }
    return 0;
}
void Temperature(double fahrenheit_temperature)
{
    const double converter = 5. / 9.;
    const double difference = 32.0, difference2 = 273.16;
    double celcius_temperature = converter * (fahrenheit_temperature - difference);
    double kelvin_temperature = celcius_temperature + difference2;
    printf("Fahrenheit temperature: %.2f\n", fahrenheit_temperature);
    printf("Celcius temperature: %.2f\n", celcius_temperature);
    printf("Kelvin temperature: %.2f\n", kelvin_temperature);
}
