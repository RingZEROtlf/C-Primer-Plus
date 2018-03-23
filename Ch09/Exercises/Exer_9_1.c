#include <stdio.h>
double min(double a, double b);
int main()
{
    printf("%lf\n", min(1.0, 2.0));
    return 0;
}
double min(double a, double b)
{
    return a < b ? a : b;
}