#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char *string_in(char *s1, char *s2);
int main()
{
    printf("%p\n", string_in("hats", "at"));
    printf("%p\n", string_in("123", "abcd"));
    return 0;
}
char *string_in(char *s1, char *s2)
{
    if (strlen(s1) < strlen(s2)) return NULL;
    else if (strlen(s1) == strlen(s2)) {
        if (strcmp(s1, s2) == 0) return s1; else return NULL;
    }
    for (int i = 0; i < strlen(s1); i++) {
        bool flag = true;
        for (int j = 0; j < strlen(s2); j++)
            if (s1[i + j] != s2[j]) {
                flag = false;
                break;
            }
        if (flag) return s1;
    }
    return NULL;
}