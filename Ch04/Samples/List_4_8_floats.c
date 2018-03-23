// floats.c -- some combination of float type decorators
#include <stdio.h>
int main(void)
{
    const double RENT = 3852.99;    // constant variable
    printf("*%f*\n", RENT);
    printf("*%e*\n", RENT);
    printf("*%4.2f*\n", RENT);
    printf("*%3.1f*\n", RENT);
    printf("*%10.3f*\n", RENT);
    printf("*%10.3E*\n", RENT);
    printf("*%+4.2f*\n", RENT);
    printf("*%+4.2f*\n", RENT);
    printf("*%10.2f*\n", RENT);
    return 0;
}

