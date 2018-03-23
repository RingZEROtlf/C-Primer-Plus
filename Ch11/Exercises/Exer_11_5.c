#include <stdio.h>
char *find_first_occurance(char *string, char character);
int main()
{
    char *string = "abcdefghijklmnopq";
    for (char character = 'a'; character <= 'z'; character++)
        printf("%p\n", find_first_occurance(string, character));
    return 0;
}
char *find_first_occurance(char *string, char character)
{
    while (*string != '\0') {
        if (*string == character) return string;
        string++;
    }
    return NULL;
}