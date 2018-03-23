// mod_str.c -- modifying strings
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT   81
void ToUpper(char *);
int PunctCount(const char *);
int main(void)
{
    char line[LIMIT];
    char *find;
    puts("Please enter a line:");
    fgets(line, LIMIT, stdin);
    find = strchr(line, '\n');      // searching new line character
    if (find)                       // if the address in not NULL
        *find = '\0';               // replace it with empty character
    ToUpper(line);
    puts(line);
    printf("That line has %d punctuation characters.\n", PunctCount(line));
    return 0;
}
void ToUpper(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}
int PunctCount(const char *str)
{
    int ct = 0;
    while (*str)
    {
        if (ispunct(*str))
            ct++;
        str++;
    }
    return ct;
}