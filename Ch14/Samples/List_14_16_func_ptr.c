// func_ptr.c -- using function pointer
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN     81
char *s_gets(char *st, int n);
char showmenu(void);
void eatline(void);             // read till the end of line
void show(void (*fp)(char *), char *str);
void ToUpper(char *);           // turn characters into upper-case
void ToLower(char *);           // turn characters into lower-case
void Transpose(char *);         // upper-case and lower-case alternative
void Dummy(char *);             // do nothing the the string
int main(void)
{
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pfun)(char *);       // declaration of a function pointer, the function pointed to accepts a char * type parameter, with no return value
    puts("Enter a string (empty line to quit):");
    while (s_gets(line, LEN) != NULL && line[0] != '\0')
    {
        while ((choice = showmenu()) != '\n')
        {
            switch (choice)     // switch to set pointer
            {
            case 'u': pfun = ToUpper; break;
            case 'l': pfun = ToLower; break;
            case 't': pfun = Transpose; break;
            case 'o': pfun = Dummy; break;
            }
            strcpy(copy, line); // copy for show()
            show(pfun, copy);   // executing the selected function according to the user's choice
        }
        puts("Enter a string (empty line to quit):");
    }
    puts("Bye!");
    return 0;
}
char showmenu(void)
{
    char ans;
    puts("Enter menu choice:");
    puts("u) uppercase          l) lowercase");
    puts("t) transposed case    o) original case");
    puts("n) next string");
    ans = getchar();            // acquire the user's input
    ans = tolower(ans);         // transform it into lower-case
    eatline();                  // flush the rest of input line
    while (strchr("ulton", ans) == NULL)
    {
        puts("Please enter a u, l, t, o, or n:");
        ans = tolower(getchar());
        eatline();
    }
    return ans;
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
void ToUpper(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}
void ToLower(char *str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}
void Transpose(char *str)
{
    while (*str)
    {
        if (islower(*str))
            *str = toupper(*str);
        else if (isupper(*str))
            *str = tolower(*str);
        str++;
    }
}
void Dummy(char *str)
{
    // do nothing
}
void show(void (*fp)(char *), char *str)
{
    (*fp)(str);     // executing the selected function with parameter str
    puts(str);      // output result
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');    // search the new-line character
        if (find)                   // if the address is not NULL
            *find = '\0';           // place an empty character here
        else
            while (getchar() != '\n')
                continue;           // deal with the remain characters in the input
    }
    return ret_val;
}