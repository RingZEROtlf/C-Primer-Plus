#include <stdio.h>
void reorder(double *ptr_a, double *ptr_b, double *ptr_c);
int main()
{
    double a = 3.0, b = 1.0, c = 2.0;
    printf("Originally a = %.2lf, b = %.2lf and c = %.2lf.\n", a, b, c);
    reorder(&a, &b, &c);
    printf("Now a = %.2lf, b = %.2lf and c = %.2lf.\n", a, b, c);
    return 0;
}
void reorder(double *ptr_a, double *ptr_b, double *ptr_c)
{
    double tmp;
    if (*ptr_a > *ptr_b) {
        tmp = *ptr_a;
        *ptr_a = *ptr_b;
        *ptr_b = tmp;
    }
    if (*ptr_a > *ptr_c) {
        tmp = *ptr_a;
        *ptr_a = *ptr_c;
        *ptr_c = tmp;
    }
    if (*ptr_b > *ptr_c) {
        tmp = *ptr_b;
        *ptr_b = *ptr_c;
        *ptr_c = tmp;
    }
}