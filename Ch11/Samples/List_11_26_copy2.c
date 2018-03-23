// copy2.c -- using strcpy()
#include <stdio.h>
#include <string.h>     // providing function prototype of strcpy()
#define WORDS       "beast"
#define SIZE        40
int main(void)
{
    const char *orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char *ps;
    puts(orig);
    puts(copy);
    ps = strcpy(copy + 7, orig);
    puts(copy);
    puts(ps);
    return 0;
}