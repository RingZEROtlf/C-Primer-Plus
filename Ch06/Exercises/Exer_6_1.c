#include <stdio.h>
int main()
{
    char letters[26];
    for (int i = 0; i < 26; i++) {
        letters[i] = 'a' + i;
    }
    for (int i = 0; i < 26; i++) {
        printf("%c ", letters[i]);
    }
    printf("\n");
    return 0;
}