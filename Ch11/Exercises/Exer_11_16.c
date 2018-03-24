#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    char line[1024];
    if (argc == 1 || strcmp(argv[1], "-p") == 0) {
        while (gets(line))
            puts(line);
    }
    else if (strcmp(argv[1], "-u") == 0) {
        while (gets(line)) {
            for (int i = 0; i < strlen(line); i++)
                putchar(toupper(line[i]));
            putchar('\n');
        }
    }
    else if (strcmp(argv[1], "-l") == 0) {
        while (gets(line)) {
            for (int i = 0; i < strlen(line); i++)
                putchar(tolower(line[i]));
            putchar('\n');
        }
    }
    else {
        printf("Parameter(s) invalid!\n");
    }
    return 0;
}