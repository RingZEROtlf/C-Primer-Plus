#include <stdio.h>
int main()
{
    int replacement = 0;
    char ch;
    while ((ch = getchar()) != '#') {
        switch (ch) {
        case '.':
            putchar('!');
            replacement++;
            break;
        case '!':
            printf("!!");
            replacement++;
            break;
        default:
            putchar(ch);
        }
    }
    printf("We've done %d replacements.\n", replacement);
    return 0;
}