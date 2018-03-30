#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXTITL     40
#define MAXAUTL     40
#define MAXBKS      10
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    bool  is_deleted;
};
void new_book(struct book *book, char *title, char *author, float value);
int main(void)
{
    struct book library[1024];
    int count = 0;
    FILE *pbooks;
    if ((pbooks = fopen("book.dat", "r+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }
    rewind(pbooks);
    char title[MAXTITL], author[MAXAUTL];
    float value;
    while (count < MAXBKS && fscanf(pbooks, "%s %s %f", title, author, &value) == 3) {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", title, author, value);
        new_book(&library[count], title, author, value);
        count++;
    }
    if (count == MAXBKS) {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }
    puts("Please inuput your operations (add + title + author + value, delete + title).");
    puts("Press [enter] at the start of a line to stop.");
    char op[16];
    int real_count = count;
    while (real_count < MAXBKS && scanf("%s", op) == 1) {
        if (strcmp(op, "add") == 0) {
            scanf("%s %s %d", title, author, &value);
            new_book(&library[count], title, author, value);
            count++;
            real_count++;
        }
        else if (strcmp(op, "delete") == 0) {
            scanf("%s", title);
            for (int i = 0; i < count; i++)
                if (!library[i].is_deleted && strcmp(library[i].title, title) == 0) {
                    library[i].is_deleted = true;
                    break;
                }
            real_count--;
        }
        else printf("Operation invalid!\n");
    }
    if (real_count > 0)
    {
        puts("Here is the list of your books:");
        for (int i = 0; i < count; i++) {
            if (!library[i].is_deleted) printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
            fprintf(pbooks, "%s %s %.2f\n", library[i].title, library[i].author, library[i].value);
        }
    }
    else
        puts("No books? Too bad.\n");
    puts("Bye.\n");
    fclose(pbooks);
    return 0;
}
void new_book(struct book *book, char *title, char *author, float value)
{
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->value = value;
    book->is_deleted = false;
}
