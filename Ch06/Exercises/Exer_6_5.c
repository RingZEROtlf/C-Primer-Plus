#include <stdio.h>
int main()
{
    char ch;
    printf("Please enter an upper-case letter: ");
    scanf("%c", &ch);
    for (char i = 'A'; i <= ch; i++) {
        for(int j = 1; j <= ch - i; j++) {
            printf(" ");
        }
        for(char j = 'A'; j <= i; j++) {
            printf("%c", j);
        }
        for(char j = i - 1; j >= 'A'; j--) {
            printf("%c", j);
        }
        printf("\n");
    }
    return 0;
}