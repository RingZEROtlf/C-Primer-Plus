#include <stdio.h>
#include <float.h>
int main()
{
    double a = 1.0 / 3.0;
    float b = 1.0 / 3.0;
    printf("%20.6f %20.6f\n", a, b);
    printf("%20.12f %20.12f\n", a, b);
    printf("%20.16f %20.16f\n", a, b);
    printf("float precision = %d digits\n", FLT_DIG);
    printf("double precision = %d digits\n", DBL_DIG);
    return 0;
}

