#include <stdio.h>
double calc(double a);
int main()
{
    double a;
    printf("Please enter a double variable: ");
    scanf("%lf", &a);
    printf("%.2f\n", calc(a));
    return 0;
}
double calc(double a)
{
    return a * a * a;
}