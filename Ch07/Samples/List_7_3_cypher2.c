// cypher2.c -- repalce characters read, do nothing to non-alphabetic characters
#include <stdio.h>
#include <ctype.h>      // include isalpha() function prototype
int main(void)
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))        // if it is an alphabet, 
            putchar(ch + 1);    // output the next character of it
        else                    // otherwise, 
            putchar(ch);        // do nothing
    }
    putchar(ch);                // output new line
    return 0;
}