// sort_str.c -- input strings, and sort them in order
#include <stdio.h>
#include <string.h>
#define SIZE    81      // limit the length of strings, including '\0' character
#define LIM     20      // the max number of lines can be inputed
#define HALT    ""      // empty string which halt the input
void stsrt(char *string[], int num);    // function that sorts strings
char *s_gets(char *st, int n);
int main(void)
{
    char input[LIM][SIZE];      // store arrays inputed
    char *ptstr[LIM];           // array containing pointer variables
    int ct = 0;                 // input counter
    int k;                      // output counter
    printf("Input up to %d lines, and I will sort them.\n", LIM);
    printf("To stop, press the Enter key at a line's start.\n");
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];
        ct++;
    }
    stsrt(ptstr, ct);           // function that sorts strings
    puts("\nHere's the sorted list:\n");
    for (k = 0; k < ct; k++)
        puts(ptstr[k]);         // pointers sorted
    return 0;
}
// function that sorts pointers of string
void stsrt(char *strings[], int num)
{
    char *temp;
    int top, seek;
    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top], strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}