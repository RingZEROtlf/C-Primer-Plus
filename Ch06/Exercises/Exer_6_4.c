#include <stdio.h>
int main()
{
    char ch = 'A';
    for(int i = 1; i <= 6; i++) {
        for(int j = 1; j <= i; j++, ch++) {
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}