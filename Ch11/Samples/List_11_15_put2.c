// put2.c -- print a string and count characters printed
#include <stdio.h>
int put2(const char *string)
{
    int count = 0;
    while (*string)     // regular usage
    {
        putchar(*string++);
        count++;
    }
    putchar('\n');
    return count;
}