#include <stdio.h>
#include <stdbool.h>
char *get_first_word(char *start);
int main()
{
    char word[100];
    while (get_first_word(word) != NULL)
        puts(word);
    puts("Finished!\n");
    return 0;
}
char *get_first_word(char *start)
{
    char *ret = start;
    char character;
    while (true) {
        character = getchar();
        if (character == '\0' || character == '\n') return NULL;
        else if (character != ' ' && character != '\t') break;
    }
    do {
        *start = character;
        start++;
        character = getchar();
        if (character == '\0' || character == '\n') {
            *start = '\0';
            return ret;
        }
        else if (character == ' ' || character == '\t') break;
    } while (true);
    *start = '\0';
    while (true) {
        character = getchar();
        if (character == '\0' || character == '\n') break;
    }
    return ret;
}