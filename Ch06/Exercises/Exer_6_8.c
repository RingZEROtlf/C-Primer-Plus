#include <stdio.h>
#include <math.h>
int main()
{
    double a, b;
    while(scanf("%lf%lf", &a, &b) == 2) {
        printf("%.4f\n", fabs((a - b) / (a * b)));
    }
    return 0;
}