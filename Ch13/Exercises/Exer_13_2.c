#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s target_filename source_filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *fp_target, *fp_source;
    if ((fp_target = fopen(argv[1], "wb")) == NULL) {
        printf("Can't open target file.\n");
        exit(EXIT_FAILURE);
    }
    if ((fp_source = fopen(argv[2], "rb")) == NULL) {
        printf("Can't open source file.\n");
        exit(EXIT_FAILURE);
    }
    char character;
    while (fscanf(fp_source, "%c", &character) == 1) {
        // fprintf(stdout, "%c", character);
        fprintf(fp_target, "%c", character);
    }
    fclose(fp_target);
    fclose(fp_source);
    return 0;
}