// lethead2.c
#include <stdio.h>
#include <string.h>     // provide function prototype for strlen()
#define NAME        "GIGATHINK, INC"
#define ADDRESS     "101 Megabuck Plaza"
#define PLACE       "Megapolis, CA 94904"
#define WIDTH       40
#define SPACE       ' '
void show_n_char(char ch, int num);
int main(void)
{
    int spaces;
    show_n_char('*', WIDTH);    // use character constant as parameter
    putchar('\n');
    show_n_char(SPACE, 12);     // use character constant as parameter
    printf("%s\n", NAME);
    spaces = (WIDTH - strlen(ADDRESS)) / 2; // calculate how many spaces needed to be skipped
    show_n_char(SPACE, spaces); // use a variable as parameter
    printf("%s\n", ADDRESS);
    show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);    // use an expression as parameter
    printf("%s\n", PLACE);
    show_n_char('*', WIDTH);
    putchar('\n');
    return 0;
}
void show_n_char(char ch, int num)
{
    int count;
    for (count = 1; count <= num; count++)
        putchar(ch);
}