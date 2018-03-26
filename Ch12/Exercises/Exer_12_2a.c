#include <stdio.h>

static int mode = 0;
static double distance, fuel;

void set_mode(int mode_inputed);
void get_info();
void show_info();

void set_mode(int mode_inputed)
{
    mode = mode_inputed;
}
void get_info()
{
    switch (mode)
    {
    case 0:
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel);
        break;
    case 1:
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel);
        break;
    default:
        printf("Invalid mode specified. Mode 1(US) used.\n");
        mode = 1;
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel);
        break;
    }
}
void show_info()
{
    switch (mode)
    {
    case 0:
        printf("Fuel consumption is %.2lf liters per 100 km.\n", fuel * 100.0 / distance);
        break;
    case 1:
        printf("Fuel consumption is %.1lf miles per gallon.\n", distance / fuel);
        break;
    default:
        break;
    }
}
