#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        printf("%03d: ", i);
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("Can't open this file.\n");
            continue;
        }
        printf("The content of file %s is:\n");
        char character;
        while (fscanf(fp, "%c", &character) == 1)
            putchar(character);
        putchar('\n');
        fclose(fp);
    }
    return 0;
}