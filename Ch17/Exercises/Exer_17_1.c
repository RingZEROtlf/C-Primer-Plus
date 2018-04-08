#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE       45
struct film {
    char title[TSIZE];
    int rating;
    struct film *next;
};
void print_films_in_forward_direction(struct film *head);
void _print_films_in_backward_direction(struct film *current);
void print_films_in_backward_direction(struct film *head);
char *s_gets(char *st, int n);
int main(void)
{
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL)
            head = current;
        else
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
    print_films_in_forward_direction(head);
    putchar('\n');
    print_films_in_backward_direction(head);
    putchar('\n');
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
void print_films_in_forward_direction(struct film *head)
{
    if (head == NULL)
        printf("No data entered.\n");
    else
        printf("Here is the movie list:\n");
    struct film *current = head;
    while (current != NULL)
    {
        printf("Movie: %s Rating: %d\n", current->title, current->rating);
        current = current->next;
    }
}
void _print_films_in_backward_direction(struct film *current)
{
    if (current != NULL) {
        _print_films_in_backward_direction(current->next);
        printf("Movie: %s Rating: %d\n", current->title, current->rating);
    }
}
void print_films_in_backward_direction(struct film *head)
{
    if (head == NULL)
        printf("No data entered.\n");
    else
        printf("Here is the movie list:\n");
    _print_films_in_backward_direction(head);
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}