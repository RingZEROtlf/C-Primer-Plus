/* praise2.c */
// if compiler cannot recognize %zd, try %u or %lu.
#include <stdio.h>
#include <string.h>     // provide the function prototype of strlen()
#define PRAISE  "You are an extraordinary being."
int main(void)
{
    char name[40];
    printf("What's your name? ");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    printf("Your name of %zd letters occupies %zd memory cells.\n",
        strlen(name), sizeof name);
    printf("The phrase of praise has %zd letters ",
        strlen(PRAISE));
    printf("and occupies %zd memory cells.\n", sizeof PRAISE);
    return 0;
}

