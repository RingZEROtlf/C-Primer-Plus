/* while1.c -- take care the usage of curly braces */
/* terrible code lead to an infinite loop */
#include <stdio.h>
int main(void)
{
    int n = 0;
    while(n < 3)
        printf("n is %d\n", n);
        n++;
    printf("That's all this program does\n");
    return 0;
}