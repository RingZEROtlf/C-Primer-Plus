#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
void show_array(const double ar[], int n);
double *new_d_array(int n, ...);
int main()
{
    double *p1;
    double *p2;
    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);
    return 0;
}
void show_array(const double ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%.4lf ", ar[i]);
    putchar('\n');
}
double *new_d_array(int n, ...)
{
    double *array = (double *) malloc(sizeof(double) * n);
    va_list iterator;
    va_start(iterator, n);
    for (int i = 0; i < n; i++)
        array[i] = va_arg(iterator, double);
    va_end(iterator);
    return array;
}
