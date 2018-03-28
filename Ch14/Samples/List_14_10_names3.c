// names3.c -- using pointer and malloc()
#include <stdio.h>
#include <string.h>         // providing function prototypes of strcpy() and strlen()
#include <stdlib.h>         // providing function prototypes of malloc() and free()
#define SLEN        81
struct namect {
    char *fname;            // using pointer
    char *lname;
    int letters;
};
void getinfo(struct namect *);  // allocate memory
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *);  // release memory when calling this function
char *s_gets(char *st, int n);
int main(void)
{
    struct namect person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);
    return 0;
}
void getinfo(struct namect *pst)
{
    char temp[SLEN];
    printf("Please enter your first name.\n");
    s_gets(temp, SLEN);
    // allocate memory to store name
    pst->fname = (char *) malloc(strlen(temp) + 1);
    // copy the name into the dynamic-allocated memory
    strcpy(pst->fname, temp);
    printf("Please enter your last name.\n");
    s_gets(temp, SLEN);
    pst->lname = (char *) malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}
void makeinfo(struct namect *pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}
void showinfo(const struct namect *pst)
{
    printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
}
void cleanup(struct namect *pst)
{
    free(pst->fname);
    free(pst->lname);
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