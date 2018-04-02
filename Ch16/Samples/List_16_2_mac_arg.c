// mac_arg.c -- macros with arguments
#include <stdio.h>
#define SQUARE(X)   X * X
#define PR(X)       printf("The result is %d.\n", X)
int main(void)
{
    int x = 5;
    int z;
    printf("x = %d\n", x);
    x = SQUARE(x);
    printf("Evaluating SQUARE(x): ");
    PR(x);
    z = SQUARE(2);
    printf("Evaluating SQUARE(z): ");
    PR(z);
    printf("Evaluating SQUARE(x + 2): ");
    PR(SQUARE(x + 2));
    printf("Evaluating 100 / SQUARE(2): ");
    PR(100 / SQUARE(2));
    printf("x is %d.\n", x);
    printf("Evaluating SQUARE(++x): ");
    PR(SQUARE(++x));
    printf("After increamenting, x is %d.\n", x);
    return 0;
}