#include <stdio.h>
double harmonic_average(double a, double b);
int main()
{
    printf("%lf\n", harmonic_average(1.0, 2.0));
    return 0;
}
double harmonic_average(double a, double b)
{
    return 1.0 / (1.0 / a + 1.0 / b);
}