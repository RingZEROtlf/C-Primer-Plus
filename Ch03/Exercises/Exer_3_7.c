#include <stdio.h>

int main()
{
    float inches;
    printf("Enter your height by inches: ");
    scanf("%f", &inches);
    printf("Your height is about %.2f in centimeters.\n", inches * 2.54);
    return 0;
}