// stillbad.c -- the program which fixed the grammer mistakes
#include <stdio.h>

int main(void)
{
    int n, n2, n3;
    /* This program have several mistakes */
    n = 5;
    n2 = n * n;
    n3 = n2 * n2;
    printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3);
    return 0;
}