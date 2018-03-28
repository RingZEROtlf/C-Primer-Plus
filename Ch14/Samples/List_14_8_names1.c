// names1.c -- using pointers which point to struct
#include <stdio.h>
#include <string.h>
#define NLEN    30
struct namect {
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};
void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
char *s_gets(char *st, int n);
int main(void)
{
    struct namect person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    return 0;
}
void getinfo(struct namect *pst)
{
    printf("Please enter your first name.\n");
    s_gets(pst->fname, NLEN);
    printf("Please enter your last name.\n");
    s_gets(pst->lname, NLEN);
}
void makeinfo(struct namect *pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}
void showinfo(const struct namect *pst)
{
    printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
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