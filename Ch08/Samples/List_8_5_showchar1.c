// showchar1.c -- a program with essential I/O problem
#include <stdio.h>
void display(char cr, int lines, int width);
int main(void)
{
    int ch;             // character to be printed
    int rows, cols;     // number of lines and coluns;
    printf("Enter a character and two integers:\n");
    while ((ch = getchar()) != '\n')
    {
        scanf("%d %d", &rows, &cols);
        display(ch, rows, cols);
        printf("Enter another character and two integers:\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye.\n");
    return 0;
}
void display(char cr, int lines, int width)
{
    int row, col;
    for (row = 1; row <= lines; row++)
    {
        for (col = 1; col <= width; col++)
            putchar(cr);
        putchar('\n');  // terminate one line to start a new one
    }
}