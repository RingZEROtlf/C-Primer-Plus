/* post_pre.c -- prefix and suffix */
#include <stdio.h>
int main(void)
{
    int a = 1, b = 1;
    int a_post, pre_b;
    a_post = a++;   // suffix increasement
    pre_b = ++b;    // prefix increasement
    printf("a a_post b pre_b \n");
    printf("%1d %5d %5d %5d\n", a, a_post, b, pre_b);
    return 0;
}