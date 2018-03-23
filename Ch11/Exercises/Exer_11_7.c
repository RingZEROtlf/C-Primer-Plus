#include <stdio.h>
#include <string.h>
char *mystrncpy(char *dest, const char *src, int count);
int main()
{
    char dests[5][100] = {
        "12345",
        "12",
        "abcde",
        "ab",
        "Hello World!"
    };
    char src[100] = "0123456789";
    for (int i = 0; i < 5; i++) {
        int len = strlen(dests[i]);
        mystrncpy(dests[i], src, len);
        for (int j = 0; j < len; j++) {
            if (dests[i][j] != '\0') printf("%c ", dests[i][j]); else printf("\\0 ");
        }
        printf("\n");
    }
    return 0;
}
char *mystrncpy(char *dest, const char *src, int count)
{
    for (int i = 0; i < count; i++) {
        dest[i] = src[i];
        if (src[i] == '\0') break;
    }
    return dest;
}