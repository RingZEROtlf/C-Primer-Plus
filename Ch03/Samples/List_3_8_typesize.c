/* typesize.c -- print the size of a type */
#include <stdio.h>
int main(void)
{
    /* C99 gives the %d transfer info for size of types */
    printf("Type int has a size of %zd bytes.\n", sizeof(int));
    printf("Type char has a size of %zd byptes.\n", sizeof(char));
    printf("Type long has a size of %zd byptes.\n", sizeof(long));
    printf("Type long long has a size of %zd byptes.\n", sizeof(long long));
    printf("Type float has a size of %zd bytes.\n", sizeof(float));
    printf("Type double has a size of %zd byptes.\n", sizeof(double));
    printf("Type long double has a size of %zd byptes.\n", sizeof(long double));
    return 0;
}