// list.c -- functions support list operations
#include <stdio.h>
#include <stdlib.h>
#include "Exer_17_2_list.h"
// local function prototype
static void CopyToNode(Item item, Node *pnode);
// interface functions
// set list as an empty one
void InitializeList(List *plist)
{
    plist->head = NULL;
    plist->end = NULL;
}
// if list is empty, return true
bool ListIsEmpty(const List *plist)
{
    if (plist->head == NULL)
        return true;
    else
        return false;
}
// if list is full, return true
bool ListIsFull(const List *plist)
{
    Node *pt;
    bool full;
    pt = (Node *) malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);
    return full;
}
// return the number of nodes in a list
unsigned int ListItemCount(const List *plist)
{
    unsigned int count = 0;
    Node *pnode = plist->head;       // set to the start of list
    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;    // set to the next node
    }
    return count;
}
// create the node to store item, and append it to the tail of the list plist points to (a slow implementation)
bool AddItem(Item item, List *plist)
{
    Node *pnew;
    Node *scan = plist->head;
    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return false;           // exit this function if failed
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL) {         // empty list, so put pnew at the start of the list
        plist->head = pnew;
        plist->end = pnew;
    }
    else
    {
        while (scan->next != NULL)
            scan = scan->next;  // find the tail of the list
        scan->next = pnew;      // append pnew to the tail of the list;
        plist->end = pnew;
    }
    return true;
}
// access every node and execute the function which pfun points to
void Traverse(const List *plist, void (*pfun)(Item item))
{
    Node *pnode = plist->head;       // set to the start of the list
    while (pnode != NULL)
    {
        (*pfun)(pnode->item);   // apply the function the item in the list
        pnode = pnode->next;    // step to the next item
    }
}
// free memory allocated by malloc()
// set the list to NULL
void EmptyTheList(List *plist)
{
    Node *psave;
    Node *curr = plist->head;
    while (curr != NULL)
    {
        psave = curr->next;     // save the address of the next node
        free(curr);             // free the current node
        curr = psave;           // step to the next node
    }
}
// local function definition
// copy one item to a node
static void CopyToNode(Item item, Node *pnode)
{
    pnode->item = item;         // copy struct
}