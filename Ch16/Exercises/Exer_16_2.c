#include <stdio.h>

#define HARMONIC_AVERAGE(a, b)  (1.0 / (1.0 / (a) + 1.0 / (b)))

int main()
{
    printf("%lf\n", HARMONIC_AVERAGE(1, 2));
    return 0;
}