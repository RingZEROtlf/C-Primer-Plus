#include <stdio.h>
int main()
{
    printf("Please enter your height (in feet) and full name: ");
    float height;
    char first_name[40];
    scanf("%f%s", &height, first_name);
    printf("%s, you are %.3f feet tall.\n", first_name, height);
    return 0;
}

