// films2.c -- using struct list
#include <stdio.h>
#include <stdlib.h>     // providing function prototype of malloc()
#include <string.h>     // providing function prototype of strcpy()
#define TSIZE       45  // size of the array stroing film names
struct film {
    char title[TSIZE];
    int rating;
    struct film *next;  // pointing to the next struct in the list
};
char *s_gets(char *st, int n);
int main(void)
{
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];
    // collect and store infomation
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL)       // the first struct
            head = current;
        else                    // the subsequent structs
            prev->next = current;
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }
    // output film list
    if (head == NULL)
        printf("No data entered.\n");
    else
        printf("Here is the movie list:\n");
    current = head;
    while (current != NULL)
    {
        printf("Movie: %s Rating: %d\n", current->title, current->rating);
        current = current->next;
    }
    // task finished, free memory alloced
    current = head;
    while (current != NULL)
    {
        current = head;
        head = current->next;
        free(current);
    }
    printf("Bye!\n");
    return 0;
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