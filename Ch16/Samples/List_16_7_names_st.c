// names_st.c -- definitions of functions in List_16_6_names_st.h
#include <stdio.h>
#include "List_16_6_names_st.h"     // include header file
// function definitions
void get_names(names *pn)
{
    printf("Please enter your first name: ");
    s_gets(pn->first, SLEN);
    printf("Please enter your last name: ");
    s_gets(pn->last, SLEN);
}
void show_names(const names *pn)
{
    printf("%s %s", pn->first, pn->last);
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');    // search for new-line character
        if (find)                   // if the address is not null
            *find = '\0';           // place an empty character here
        else
            while (getchar() != '\n')
                continue;           // deal with the left characters in this input line
    }
    return ret_val;
}