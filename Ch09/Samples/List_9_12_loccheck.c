// loccheck.c -- find out where variable is stored
#include <stdio.h>
void mikado(int);               // function prototype
int main(void)
{
    int pooh = 2, bah = 5;      // local variables of main()
    printf("In main(), pooh = %d and &pooh = %p\n", pooh, &pooh);
    printf("In main(), bah = %d and &bah = %p\n", bah, &bah);
    mikado(pooh);
    return 0;
}
void mikado(int bah)            // function defination
{
    int pooh = 10;              // local variable of mikado()
    printf("In mikado(), pooh = %d and &pooh = %p\n", pooh, &pooh);
    printf("In mikado(), bah = %d and &bah = %p\n", bah, &bah);
}