#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int div_and_round(int a, int b);

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
        for (int j = 0; j < 30; j++) {
            bool necessary = true;
            int count = 0, total = 0;
            if (necessary && i > 0 && abs(numbers[i][j] - numbers[i - 1][j]) > 1) necessary = false;
            else {
                count++;
                total += numbers[i - 1][j];
            }
            if (necessary && i < 20 - 1 && abs(numbers[i][j] - numbers[i + 1][j]) > 1) necessary = false;
            else {
                count++;
                total += numbers[i + 1][j];
            }
            if (necessary && j > 0 && abs(numbers[i][j] - numbers[i][j - 1]) > 1) necessary = false;
            else {
                count++;
                total += numbers[i][j - 1];
            }
            if (necessary && j < 30 - 1 && abs(numbers[i][j] - numbers[i][j + 1]) > 1) necessary = false;
            else {
                count++;
                total += numbers[i][j + 1];
            }
            if (necessary) digits[i][j] = map[div_and_round(total, count)]; else digits[i][j] = map[numbers[i][j]];
        }
        digits[i][30] = '\0';
    }
    for (int i = 0; i < 20; i++)
        fprintf(foutput, "%s\n", digits[i]);
    fclose(finput);
    fclose(foutput);
    return 0;
}

int div_and_round(int a, int b)
{
    int p = a / b;
    return a - b * p < b * (p + 1) - a ? p : p + 1;
}

