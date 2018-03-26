#include <stdio.h>

void get_info(int *pmode, double *pdistance, double *pfuel);
void show_info(int mode, double distance, double fuel);

void get_info(int *pmode, double *pdistance, double *pfuel)
{
    switch (*pmode)
    {
    case 0:
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", pdistance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", pfuel);
        break;
    case 1:
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", pdistance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", pfuel);
        break;
    default:
        printf("Invalid mode specified. Mode 1(US) used.\n");
        *pmode = 1;
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", pdistance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", pfuel);
        break;
    }
}
void show_info(int mode, double distance, double fuel)
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
