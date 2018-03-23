#include <stdio.h>
int main()
{
    char curr, prev = ' ';
    int count = 0;
    while ((curr = getchar()) != '#') {
        if (prev == 'e' && curr == 'i') count++;
        prev = curr;
    }
    printf("'ei' occured %d times.\n", count);
    return 0;
}