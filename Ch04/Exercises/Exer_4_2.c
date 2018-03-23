#include <stdio.h>
#include <string.h>
int main()
{
    char first_name[40], last_name[40];
    printf("Please enter your full name: ");
    scanf("%s%s", first_name, last_name);
    printf("\"%s %s\"\n", first_name, last_name);
    int width = strlen(first_name) + strlen(last_name) + 3;
    printf("%*s\"%s %s\"\n", 20 - width, "", first_name, last_name);
    printf("\"%s %s\"%*s\n", first_name, last_name, 20 - width, "");
    printf("%*s\"%s %s\"\n", 3, "", first_name, last_name);
    return 0;
}

