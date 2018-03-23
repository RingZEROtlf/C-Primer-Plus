#include <stdio.h>

int main()
{
    float length;

    printf("Please input the length value in inch: ");
    scanf("%f", &length);
    printf("The length value is %.2f in cm.\n", length * 2.54);

    return 0;
}