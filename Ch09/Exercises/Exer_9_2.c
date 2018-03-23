#include <stdio.h>
void chline(char ch, int i, int j);
int main()
{
    chline('*', 8, 10);
    return 0;
}
void chline(char ch, int i, int j)
{
    for (int ii = 0; ii < i; ii++) {
        for (int jj = 0; jj < j; jj++)
            putchar(ch);
        putchar('\n');
    }
}