// pnt_add.c -- address of pointer
#include <stdio.h>
#define SIZE    4
int main(void)
{
    short dates[SIZE];
    short *pti;
    short index;
    double bills[SIZE];
    double *ptf;
    pti = dates;    // assign address of array to a pointer
    ptf = bills;
    printf("%11s %15s\n", "short", "double");
    for (index = 0; index < SIZE; index++)
        printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
    return 0;
}