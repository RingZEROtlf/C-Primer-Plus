#include <stdio.h>

int main()
{
    float quart;
    printf("Enter the mass of water by quart: ");
    scanf("%f", &quart);
    printf("The number of water molecule is about %e.\n", quart * 950.0 / 3.0e-23);
    return 0;
}