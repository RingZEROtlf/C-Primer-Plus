#include <stdio.h>
int is_within(char *string, char character);
int main()
{
    char *string = "abcdefghijklmnopq";
    for (char character = 'a'; character <= 'z'; character++)
        printf("%c %s in \"%s\".\n", character,is_within(string, character) ? "is" : "isn't", string);
    return 0;
}
int is_within(char *string, char character)
{
    while (*string != '\0') {
        if (*string == character) return 1;
        string++;
    }
    return 0;
}