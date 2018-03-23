/* proud.c -- define a function with parameters */
#include <stdio.h>
void proud(int n);  // ANSI function prototype declaration
int main(void)
{
    int times = 5;
    char ch = '!';  // ASCII code is 33
    float f = 6.0f;
    proud(times);   // int parameter
    proud(ch);      // similar with proud((int)ch)
    proud(f);       // similar with proud((int)f)
    return 0;
}
void proud(int n)   // ANSI style function head
{                   // clasify that this function accept 1 int parameter
    while(n-- > 0)
        printf("#");
    printf("\n");
}