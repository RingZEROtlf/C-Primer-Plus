#include <stdio.h>
int main()
{
    char ch;
    int count = 0;
    while ((ch = getchar()) != '#') {
        count = (count + 1) % 8;
        printf("%c%3d ", ch, ch);
        if (count == 0) printf("\n");
    }
    return 0;
}