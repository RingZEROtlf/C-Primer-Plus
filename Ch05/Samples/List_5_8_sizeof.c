// sizeof.c -- using sizeof operator
// using %zd transcation added in C99 -- if compiler doesn't support %zd, please change it into %u or %lu
#include <stdio.h>
int main(void)
{
    int n = 0;
    size_t intsize;
    intsize = sizeof (int);
    printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n", n, sizeof n, intsize);
    return 0;
}