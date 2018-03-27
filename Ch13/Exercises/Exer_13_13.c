// I can't understand what this problem wants me to do.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char map[10] = { 
        ' ', '.', '\'', ':', '~',
        '*', '=', ' ', '%', '#'
    };
    FILE *finput = fopen("Exer_13_12_input.txt", "r"), *foutput = fopen("Exer_13_12_output.txt", "w");
    if (finput == NULL || foutput == NULL) {
        printf("Can't open file.\n");
        exit(EXIT_FAILURE);
    }
    int numbers[20][30];
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 30; j++)
            fscanf(finput, "%d", &numbers[i][j]);
    char digits[20][31];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++)
            digits[i][j] = map[numbers[i][j]];
        digits[i][30] = '\0';
    }
    for (int i = 0; i < 20; i++)
        fprintf(foutput, "%s\n", digits[i]);
    fclose(finput);
    fclose(foutput);
    return 0;
}