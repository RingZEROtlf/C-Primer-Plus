/* wheat.c -- exponential increasement */
#include <stdio.h>
#define SQUARES 64  // squares in a chess board
int main(void)
{
    const double CROP = 2e16;   // coarse grain production worldwide
    double current, total;
    int count = 1;
    printf("square grains total ");
    printf("fraction of \n");
    printf(" added grains");
    printf(" world total\n");
    total = current = 1.0;      // count from 1
    printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
    while(count < SQUARES)
    {
        count = count + 1;
        current = 2.0 * current;    // next square has double coarse grains
        total = total + current;    // update total amount
        printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
    }
    printf("That's all.\n");
    return 0;
}