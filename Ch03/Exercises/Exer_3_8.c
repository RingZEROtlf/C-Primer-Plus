#include <stdio.h>

int main()
{
    float pint, cup, ounce, tablespoon, teaspoon;
    printf("Enter the volume by cup: ");
    scanf("%f", &cup);
    pint = cup / 2.0;
    ounce = cup * 8.0;
    tablespoon = ounce * 2.0;
    teaspoon = tablespoon * 3.0;
    printf("The volume is %.2f by pint.\n", pint);
    printf("The volume is %.2f by ounce.\n", ounce);
    printf("The volume is %.2f by tablespoon.\n", tablespoon);
    printf("The volume is %.2f by teaspoon.\n", teaspoon);
    return 0;
}