#include <stdio.h>
void swap(double *a, double *b);
void reverse_array(double numbers[], int size);
void output_array(double numbers[], int size);
int main()
{
    double numbers[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    reverse_array(numbers, sizeof numbers / sizeof *numbers);
    output_array(numbers, sizeof numbers / sizeof *numbers);
    return 0;
}
void swap(double *a, double *b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}
void reverse_array(double numbers[], int size)
{
    int l = 0, r = size - 1;
    while (l < r) {
        swap(&numbers[l], &numbers[r]);
        l++, r--;
    }
}
void output_array(double numbers[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%.2lf ", numbers[i]);
    printf("\n");
}