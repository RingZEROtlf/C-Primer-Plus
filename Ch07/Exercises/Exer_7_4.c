#include <stdio.h>
int main()
{
    int replacement = 0;
    char ch;
    while ((ch = getchar()) != '#') {
        if (ch == '.') {
            putchar('!');
            replacement++;
        }
        else if (ch == '!') {
            printf("!!");
            replacement++;
        }
        else putchar(ch);
    }
    printf("We've done %d replacements.\n", replacement);
    return 0;
}