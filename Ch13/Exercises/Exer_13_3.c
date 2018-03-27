#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(argv[1], "r+");
    if (fp == NULL) {
        printf("Can't open file.\n");
        exit(EXIT_FAILURE);
    }
    char character;
    fseek(fp, 0L, SEEK_END);
    long file_length = ftell(fp);
    printf("%ld\n", file_length);
    fseek(fp, 0L, SEEK_SET);
    for (long i = 0L; i < file_length; i++) {
        fseek(fp, i, SEEK_SET);
        character = fgetc(fp);
        fseek(fp, i, SEEK_SET);
        fputc(toupper(character), fp);
    }
    fclose(fp);
    return 0;
}