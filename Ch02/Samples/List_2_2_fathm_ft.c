// fathm_ft.c -- change 2 fathoms into inches
#include <stdio.h>

int main()
{
    int feet, fathoms;
    fathoms = 2;
    feet = 6 * fathoms;
    printf("There are %d feet in %d fathoms!\n", feet, fathoms);
    printf("Yes, I said %d feet!\n", 6 * fathoms);
    return 0;
}