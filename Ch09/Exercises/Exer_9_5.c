#include <stdio.h>
void larger_of(double *ptr_a, double *ptr_b);
int main()
{
    double a = 1.0, b = 2.0;
    printf("Originally a = %.2lf and b = %.2lf.\n", a, b);
    larger_of(&a, &b);
    printf("Now a = %.2lf and b = %.2lf.\n", a, b);
    return 0;
}
void larger_of(double *ptr_a, double *ptr_b)
{
    if (*ptr_a > *ptr_b) *ptr_b = *ptr_a; else *ptr_a = *ptr_b;
}
