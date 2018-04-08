// tree.h -- binary search tree
// this tree structure doesn't accept repeated elements
#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>
// redefine Item according to the specific situation
#define SLEN        20
typedef struct item
{
    char petname[SLEN];
    char petkind[SLEN];
} Item;
#define MAXITEMS    10
typedef struct trnode
{
    Item item;
    struct trnode *left;    // pointer points to the left branch
    struct trnode *right;   // pointer points to the right branch
} Trnode;
typedef struct tree
{
    Trnode *root;           // pointer points to the root of the tree
    int size;               // elements of tree
} Tree;
// function prototypes
/* Operation:       initialize the tree as an empty one
 * Precondition:    ptree points to a tree
 * Postcondition:   tree is initialized as an empty one
 */
void InitializeTree(Tree *ptree);
/* Operation:       check if a tree is empty
 * Precondition:    ptree points to a tree
 * Postcondition:   if the given tree is empty, return true; otherwise return false
 */
bool TreeIsEmpty(const Tree *ptree);
/* Operation:       check if a tree is full
 * Precondition:    ptree points to a tree
 * Postcondition:   if the given tree is full, return true; otherwise return false
 */
bool TreeIsFull(Tree *ptree);
/* Operation:       get the number of elements of a tree
 * Precondition:    ptree points to a tree
 * Postcondition:   return the number of elements of the given tree
 */
int TreeItemCount(const Tree *ptree);
/* Operation:       insert an item into a tree
 * Precondition:    pi is the address of the item to be inserted, ptree points to an initialized tree
 * Postcondition:   if the insertion is allowed, this function inserts the given item into the given
 *                  tree, and return true; otherwise, return false
 */
bool AddItem(const Item *pi, Tree *ptree);
/* Operation:       find an item in a tree
 * Precondition:    pi points to an item, ptree points to an initialized tree
 * Postcondition:   if found the given item into the given tree, return true; otherwise, return false
 */
bool InTree(const Item *pi, const Tree *ptree);
/* Operation:       delete an item from a tree
 * Precondition:    pi is the item to be deleted, ptree points to an initialized tree
 * Postcondition:   if deleted the given item from the given tree successfully, return true; otherwise
 *                  return false
 */
bool DeleteItem(const Item *pi, Tree *ptree);
/* Operation:       apply a funtion to every item in a tree
 * Precondition:    ptree points to a tree; pfun points to a function, which accepts a parameter of the
 *                  type Item, and with no return value
 * Postcondition:   every item in the given tree is applied once by the function pfun points to
 */
void Traverse(const Tree *ptree, void (*pfun)(Item item));
/* Operation:       delete all items in a tree
 * Precondition:    ptree points to an initialized tree
 * Postcondition:   the given tree is an empty one
 */
void DeleteAll(Tree *ptree);
#endif