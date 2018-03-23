// put1.c -- print strings without adding \n
#include <stdio.h>
void put1(const char *string)   // do not change string
{
    while (*string != '\0')
        putchar(*string++);
}