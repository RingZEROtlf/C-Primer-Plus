/* charcode.c -- show the ASCII value of a character */
#include <stdio.h>
int main(void)
{
    char ch;
    printf("Please enter a character.\n");
    scanf("%c", &ch);       /* User input a character */
    printf("The code for %c is %d\n", ch, ch);
    return 0;
    return 0;
}