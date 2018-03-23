// swap3.c -- solve problems in swap function using pointer
#include <stdio.h>
void interchange(int *u, int *v);
int main(void)
{
    int x = 5, y = 10;
    printf("Originally x = %d and y = %d.\n", x, y);
    interchange(&x, &y);    // pass addresses to function
    printf("Now x = %d and y = %d.\n", x, y);
    return 0;
}
void interchange(int *u, int *v)
{
    int temp;
    temp = *u;      // temp is assigned the value which u is pointing to
    *u = *v;
    *v = temp;
}