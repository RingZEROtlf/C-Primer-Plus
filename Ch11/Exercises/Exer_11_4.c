#include <stdio.h>
#include <stdbool.h>
char *get_first_word_with_length_limit(char *start, int limit);
int main()
{
    char word[101];
    while (get_first_word_with_length_limit(word, 100) != NULL)
        puts(word);
    puts("Finished!\n");
    return 0;
}
char *get_first_word_with_length_limit(char *start, int limit)
{
    char *ret = start;
    char character;
    while (true) {
        character = getchar();
        if (character == '\0' || character == '\n') return NULL;
        else if (character != ' ' && character != '\t') break;
    }
    int count = 0;
    do {
        if (count < limit) count++; else break;
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