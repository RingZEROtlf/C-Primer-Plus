#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Too few arguements.\n");
        exit(EXIT_FAILURE);
    }
    if (strlen(argv[1]) != 1) {
        printf("The first parameter is required to be a character.\n");
        exit(EXIT_FAILURE);
    }
    char pattern = argv[1][0];
    for (int i = 1; i < argc; i++) {
        printf("%03d: ", i - 1);
        int count = 0;
        for (int j = 0; j < strlen(argv[i]); j++)
            if (argv[i][j] == pattern) count++;
        if (i != 1) {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("Can't open this file.\n");
                continue;
            }
            char character;
            while (fscanf(fp, "%c", &character) == 1)
                if (character == pattern) count++;
            fclose(fp);
        }
        printf("%c has appeared %d time(s).\n", pattern, count);
    }
    return 0;
}