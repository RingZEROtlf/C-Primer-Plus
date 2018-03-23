#include <stdio.h>
void copy_arr(double target[], double source[], int size);
int main()
{
    double source[6] = { 1, 2, 3, 4, 5, 6 };
    double target[3];
    copy_arr(target, source + 3, 3);
    for (int i = 0; i < 3; i++)
        printf("%.2lf ", target[i]);
    printf("\n");
    return 0;
}
void copy_arr(double target[], double source[], int size)
{
    for (int i = 0; i < size; i++) target[i] = source[i];
}
