#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char line[300];
    scanf("%s", line);
    for (int i = strlen(line) - 1; i >= 0; i--) {
        printf("%c", line[i]);
    }
    printf("\n");
    return 0;
}