#include <stdio.h>
void copy_arr(double target[], double source[], int size);
int main()
{
    double source[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
    double target[2][3];
    for (int i = 0; i < sizeof source / sizeof *source; i++)
        copy_arr(target[i], source[i], sizeof source[i] / sizeof *(source[i]));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            printf("%.2lf ", target[i][j]);
        printf("\n");
    }
    return 0;
}
void copy_arr(double target[], double source[], int size)
{
    for (int i = 0; i < size; i++) target[i] = source[i];
}
