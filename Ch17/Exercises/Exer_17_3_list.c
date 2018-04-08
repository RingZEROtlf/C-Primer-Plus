// list.c -- functions support list operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Exer_17_3_list.h"
// interface functions
// set list as an empty one
void InitializeList(List *plist)
{
    plist->items = 0;
}
// if list is empty, return true
bool ListIsEmpty(const List *plist)
{
    return (plist->items == 0 ? true : false);
}
// if list is full, return true
bool ListIsFull(const List *plist)
{
    return (plist->items == MAXSIZE ? true : false);
}
// return the number of nodes in a list
unsigned int ListItemCount(const List *plist)
{
    return plist->items;
}
// create the node to store item, and append it to the tail of the list plist points to (a slow implementation)
bool AddItem(Item item, List *plist)
{
    if (!ListIsFull(plist)) {
        int items = plist->items;
        strcpy(plist->entries[items].title, item.title);
        plist->entries[items].rating = item.rating;
        plist->items++;
    }
    else {
        puts("List is full!");
        return false;
    }
    return true;
}
// access every node and execute the function which pfun points to
void Traverse(const List *plist, void (*pfun)(Item item))
{
    for (int i = 0; i < plist->items; i++) {
        (*pfun)(plist->entries[i]);
    }
}
// free memory allocated by malloc()
// set the list to NULL
void EmptyTheList(List *plist)
{
    plist->items = 0;
}
