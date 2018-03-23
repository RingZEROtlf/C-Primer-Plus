/* badcount.c -- the situation of wrong parameters */
#include <stdio.h>
int main(void)
{
    int n = 4;
    int m = 5;
    float f = 7.0f;
    float g = 8.0f;
    printf("%d\n", n, m);   /* Too many parameters */
    printf("%d %d %d\n", n);    /* Too little parameters */
    printf("%d %d\n", f, g);    /* The type of parameters don't match */
    return 0;
}