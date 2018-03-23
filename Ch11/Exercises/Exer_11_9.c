#include <stdio.h>
#include <string.h>
char *reverse_string(char *string);
int main()
{
    char strings[5][100] = {
        "1",
        "12",
        "123",
        "1234",
        "12345"
    };
    for (int i = 0; i < 5; i++) {
        printf("Origin: \"%s\"\n", strings[i]);
        printf("Reversed: \"%s\"\n\n", reverse_string(strings[i]));
    }
    return 0;
}
char *reverse_string(char *string)
{
    int length = strlen(string);
    for (int i = 0; i <= length / 2; i++) {
        char tmp = string[i];
        string[i] = string[length - 1 - i];
        string[length - 1 - i] = tmp;
    }
    return string;
}