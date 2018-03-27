#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s string filename\n");
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Can't open the file.\n");
        exit(EXIT_FAILURE);
    }
    char line[1024];
    int count = 0;
    while (fgets(line, 1024, fp) != EOF) {
        count++;
        if (strstr(line, argv[1]) != NULL) printf("Line %d\n", count);
    }
    return 0;
}