#include <stdio.h>
void output_array2d_elements(int d1_size, int d2_size, int array2d[d1_size][d2_size]);
void double_array2d_elements(int d1_size, int d2_size, int array2d[d1_size][d2_size]);
int main()
{
    int source[3][5] = {
        {  0,  1,  2,  3,  4 },
        {  5,  6,  7,  8,  9 },
        { 10, 11, 12, 13, 14 }
    };
    output_array2d_elements(3, 5, source);
    double_array2d_elements(3, 5, source);
    output_array2d_elements(3, 5, source);
    return 0;
}
void output_array2d_elements(int d1_size, int d2_size, int array2d[d1_size][d2_size])
{
    for (int i = 0; i < d1_size; i++) {
        for (int j = 0; j < d2_size; j++)
            printf("%d ", array2d[i][j]);
        printf("\n");
    }
    printf("\n");
}
void double_array2d_elements(int d1_size, int d2_size, int array2d[d1_size][d2_size])
{
    for (int i = 0; i < d1_size; i++)
        for (int j = 0; j < d2_size; j++)
            array2d[i][j] *= 2;
}
