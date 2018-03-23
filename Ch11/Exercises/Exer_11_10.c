#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char *get_line(char *line);
char *remove_blanks(char *string);
int main()
{
    char line[128];
    while (get_line(line) != NULL) {
        printf("%s\n", remove_blanks(line));
    }
    return 0;
}
char *get_line(char *line)
{
    char *ret = line, character;
    int count = 0;
    while (true) {
        character = getchar();
        if (character == '\0' || character == '\n') break;
        line[count] = character;
        count++;
    }
    line[count] = '\0';
    if (count == 0) return NULL; else return ret;
}
char *remove_blanks(char *string)
{
    char duplication[128];
    strcpy(duplication, string);
    int i = 0, j = 0;
    while (i < strlen(duplication)) {
        if (duplication[i] != ' ' && duplication[i] != '\t') {
            string[j] = duplication[i];
            j++;
        }
        i++;
    }
    string[j] = '\0';
    return string;
}