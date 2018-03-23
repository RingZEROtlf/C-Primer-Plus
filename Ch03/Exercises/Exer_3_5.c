#include <stdio.h>

int main()
{
    int age;
    printf("Enter your age by year: ");
    scanf("%d", &age);
    printf("You've spent %e seconds by now.\n", (float)age * 24.0 * 3600.0 * 365.0);
    return 0;
}