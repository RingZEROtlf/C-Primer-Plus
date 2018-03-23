#include <stdio.h>
#include <math.h>
double func(double a, double b);
int main()
{
    double a, b;
    while(scanf("%lf%lf", &a, &b) == 2) {
        printf("%.4f\n", func(a, b));
    }
    return 0;
}
double func(double a, double b)
{
    return fabs((a - b) / (a * b));
}