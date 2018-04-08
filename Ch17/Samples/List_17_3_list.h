// list.h -- simple header file of list type
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>        // C99 feature
// declaration of specific program
#define TSIZE       45      // size of array stroing film names
struct film
{
    char title[TSIZE];
    int rating;
};
// definition of general types
typedef struct film Item;
typedef struct node
{
    Item item;
    struct node *next;
} Node;
typedef Node *List;
// function prototypes
/* Operation:       initialize a list
 * Precondition:    plist points to a list
 * Postcondition:   list is initialized as an empty list
 */
void InitializeList(List *plist);
/* Operation:       check list is empty or not
 * Precondition:    plist points to an initialized list
 * Postcondition:   return true if list is empty, false otherwise
 */
bool ListIsEmpty(const List *plist);
/* Operation:       check if list is full
 * Precondition:    plist points to an initialized list
 * Postcondition:   return true if list is full, false otherwise
 */
bool ListIsFull(const List *plist);
/* Operation:       get the number of items in a list
 * Precondition:    plist points to an initialized list
 * Postconditon:    return the number of items in the given list
 */
unsigned int ListItemCount(const List *plist);
/* Operation:       add an item at the tail of the list
 * Precondition:    item is an element to be added, plist points to an initialized list
 * Postconditon:    add the item given and return true if possible, return false otherwise
 */
bool AddItem(Item item, List *plist);
/* Operation:       execute the function for every item in a list
 * Precondition:    plist points to an initialized list; pfun points to a function, which
 *                  accepts a parameter of type Item and with no return value
 * Postconditon:    every item in the given list is passed to the function and executed once
 */
void Traverse(const List *plist, void (*pfun)(Item item));
/* Operation:       free memory allocated (if any)
 * Precondition:    plist points to an initialized list
 * Postconditon:    memory allocated for the given list is freed, the given list is set to NULL
 */
void EmptyTheList(List *plist);
#endif