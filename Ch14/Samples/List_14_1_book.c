// book.c -- index of a book
#include <stdio.h>
#include <string.h>
char *s_gets(char *st, int n);
#define MAXTITL     41      // max length of book name + 1
#define MAXAUTL     31      // max length of author name + 1
struct book {               // struct template: book is its mark
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;            // struct template ends
};
int main(void)
{
    struct book library;    // declare library as a variable of type book
    printf("Please enter the book title.\n");
    s_gets(library.title, MAXTITL);     // access the title part
    printf("Now enter the author.\n");
    s_gets(library.author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf("%f", &library.value);
    printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
    printf("%s:\n \"%s\" ($%.2f)\n", library.author, library.title, library.value);
    printf("Done.\n");
    return 0;
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