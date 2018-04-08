// compiled together with Exer_17_7_tree.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Exer_17_7_tree.h"

#define MAX_SIZE    1024

void print_item(Item item);

int main()
{
    printf("Please enter the filename: ");
    char filename[MAX_SIZE];
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Can't open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    char word[MAX_SIZE];
    Tree tree;
    InitializeTree(&tree);
    while (fscanf(file, "%s", word) == 1) {
        Item temp;
        strcpy(temp.word, word);
        temp.counter = 0;
        if (InTree(&temp, &tree))
            UpdateCounter(FindItem(&temp, &tree));
        else
            AddItem(&temp, &tree);
    }
    Traverse(&tree, print_item);
    fclose(file);
}

void print_item(Item item)
{
    printf("counts of %s: %d\n", item.word, item.counter);
}
