#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    printf("Please enter the filename: ");
    char filename[1024];
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Can't open the file.\n");
        exit(EXIT_FAILURE);
    }
    while (true) {
        printf("Please enter the position: ");
        long pos;
        if (scanf("%ld", &pos) != 1 || pos < 0) break;
        fseek(fp, pos, SEEK_SET);
        char character;
        while ((character = fgetc(fp)) != '\n')
            putchar(character);
        putchar('\n');
    }
    return 0;
}