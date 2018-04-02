// generic.c -- define generic macros
#include <stdio.h>
#include <math.h>
#define RAD_TO_DEG  (180 / (4 * atanl(1)))
// generic sqrt function
#define SQRT(X)     _Generic((X), \
                             long double: sqrtl, \
                             default: sqrt, \
                             float: sqrtf)(X)
// generic sin function, the unit of angle is degree
#define SIN(X)      _Generic((X), \
                             long double: sinl((X) / RAD_TO_DEG), \
                             default: sin((X) / RAD_TO_DEG), \
                             float: sinf((X) / RAD_TO_DEG) \
                            )
int main(void)
{
    float x = 45.0f;
    double xx = 45.0;
    long double xxx = 45.0L;
    long double y = SQRT(x);
    long double yy = SQRT(xx);
    long double yyy = SQRT(xxx);
    printf("%.17lf\n", y);      // match float
    printf("%.17lf\n", yy);     // match default
    printf("%.17lf\n", yyy);    // match long double
    int i = 45;
    yy = SQRT(i);               // match default
    printf("%.17lf\n", yy);
    yyy = SIN(xxx);             // match long double
    printf("%.17lf\n", yyy);
    return 0;
}