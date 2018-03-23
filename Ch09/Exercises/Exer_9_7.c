#include <stdio.h>
int position(char character);
int main()
{
    char character;
    while ((character = getchar()) != EOF) {
        int pos = position(character);
        if (pos == -1)
            printf("%c is not a letter.\n", character);
        else if (pos == 1)
            printf("%c is the 1st letter.\n", character);
        else if (pos == 2)
            printf("%c is the 2nd letter.\n", character);
        else if (pos == 3)
            printf("%c is the 3rd letter.\n", character);
        else
            printf("%c is the %dth letter.\n", character, pos);
    }
}
int position(char character)
{
    if ('a' <= character && character <= 'z')
        return character - 'a' + 1;
    else if ('A' <= character && character <= 'Z')
        return character - 'A' + 1;
    else
        return -1;
}