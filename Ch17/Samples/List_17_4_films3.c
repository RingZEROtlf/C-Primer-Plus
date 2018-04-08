// films3.c -- using abstract data type (ADT) style list
// compiled together with List_17_5_list.c
#include <stdio.h>
#include <stdlib.h>             // providing function prototype of exit()
#include "List_17_3_list.h"     // providing definition of List, Item
#include <string.h>
void showmovies(Item item);
char *s_gets(char *st, int n);
int main(void)
{
    List movies;
    Item temp;
    // Initialization
    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }
    // acquire user input and store it
    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n')
            continue;
        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem allocating memroy.\n");
            break;
        }
        if (ListIsFull(&movies))
        {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }
    // display
    if (ListIsEmpty(&movies))
        printf("No data entered.\n");
    else
    {
        printf("Here is the movie list:\n");
        Traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));
    // clear
    EmptyTheList(&movies);
    printf("Bye!\n");
    return 0;
}
void showmovies(Item item)
{
    printf("Movie: %s Rating: %d\n", item.title, item.rating);
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