/* shoes1.c -- turn shoe size into inches */
#include <stdio.h>
#define ADJUST 7.31     // character constant
int main(void)
{
    const double SCALE = 0.333; // const variable
    double shoe, foot;
    shoe = 9.0;
    foot = SCALE * shoe + ADJUST;
    printf("Shor size (men's) foot length\n");
    printf("%10.1f %15.2f inches\n", shoe, foot);
    return 0;
}