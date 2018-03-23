#include <stdio.h>
double power(double n, int p);
int main(void)
{
    double x, xpow;
    int exp;
    printf("Enter a number and the integer power to which\nthe number will be raised. Enter q to quit.\n");
    while (scanf("%lf%d", &x, &exp) == 2)
    {
        if (x == 0.0 && exp == 0.0)
            printf("The 0 times power of 0 is not defined.\n");
        else {
            xpow = power(x, exp);
            printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        }
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");
    return 0;
}
double power(double n, int p)
{
    double pow = 1;
    if (p > 0) pow = n * power(n, p - 1);
    else if (p < 0) pow = power(n, p + 1) / n;
    return pow;
}