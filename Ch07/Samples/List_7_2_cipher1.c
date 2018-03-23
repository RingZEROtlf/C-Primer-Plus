// cypher1.c -- update input, but do nothing to spaces
#include <stdio.h>
#define SPACE ' '           // SPACE represents single quote - space - single quote
int main(void)
{
    char ch;
    ch = getchar();         // read a character
    while (ch != '\n')      // when a line ends
    {
        if (ch == SPACE)    // reserve the space
            putchar(ch);    // do nothing to that character
        else
            putchar(ch + 1);    // change other characters
        ch = getchar();     // read next character
    }
    putchar(ch);            // output new line
    return 0;
}