// echo.c -- repeat user's input
#include <stdio.h>
int main()
{
    char ch;
    while ((ch = getchar()) != '#')
        putchar(ch);
    return 0;
}