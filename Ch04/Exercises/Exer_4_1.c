#include <stdio.h>
int main()
{
    char first_name[40], last_name[40];
    printf("Please enter your full name: ");
    scanf("%s%s", first_name, last_name);
    printf("%s,%s\n", last_name, first_name);
    return 0;
}

