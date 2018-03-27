#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s filename_a, filename_b\n");
        exit(EXIT_FAILURE);
    }
    FILE *fa = fopen(argv[1], "r"), *fb = fopen(argv[2], "r");
    if (fa == NULL) {
        printf("Can't open the first file.\n");
        exit(EXIT_FAILURE);
    }
    if (fb == NULL) {
        printf("Can't open the second file.\n");
        exit(EXIT_FAILURE);
    }
    char la[1024], lb[1024];
    while (true) {
        if (fgets(la, 1024, fa)) printf("%s", la);
        // putchar('\n');
        if (fgets(lb, 1024, fb)) printf("%s\n", lb);
    }
    fclose(fa);
    fclose(fb);
    return 0;
}