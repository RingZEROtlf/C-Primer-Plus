// tree.c -- the support functions of tree
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Exer_17_7_tree.h"
// local data types
typedef struct pair {
    Trnode *parent;
    Trnode *child;
} Pair;
// local function prototypes
static Trnode *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode *root, void (*pfun)(Item item));
static Pair SeekItem(const Item *pi, const Tree *ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode *ptr);
// function definitions
void InitializeTree(Tree *ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}
bool TreeIsEmpty(const Tree *ptree)
{
    if (ptree->root == NULL)
        return true;
    else
        return false;
}
bool TreeIsFull(Tree *ptree)
{
    if (ptree->size == MAXITEMS)
        return true;
    else
        return false;
}
int TreeItemCount(const Tree *ptree)
{
    return ptree->size;
}
bool AddItem(const Item *pi, Tree *ptree)
{
    Trnode *new_node;
    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;           // return ahead of time
    }
    if (SeekItem(pi, ptree).child != NULL)
    {
        fprintf(stderr, "Attempted to add duplicate item\n");
        return false;           // return ahead of time
    }
    new_node = MakeNode(pi);    // points to the new node
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;           // return ahead of time
    }
    // create a new node successfully
    ptree->size++;
    if (ptree->root == NULL)    // situation 1: the tree is empty
        ptree->root = new_node; // the new node is now the root of the given tree
    else
        AddNode(new_node, ptree->root); // add the new node into the tree
    return true;                // return successfully
}
bool InTree(const Item *pi, const Tree *ptree)
{
    return (SeekItem(pi, ptree).child == NULL ? false : true);
}
Item *FindItem(const Item *pi, const Tree *ptree)
{
    return &(SeekItem(pi, ptree).child->item);
}
void UpdateCounter(Item *pi)
{
    pi->counter++;
}
bool DeleteItem(const Item *pi, Tree *ptree)
{
    Pair look;
    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return false;
    if (look.parent == NULL)        // delete the root node
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->right);
    ptree->size--;
    return true;
}
void Traverse(const Tree *ptree, void (*pfun)(Item item))
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}
void DeleteAll(Tree *ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}
// local functions
static void InOrder(const Trnode *root, void (*pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}
static void DeleteAllNodes(Trnode *root)
{
    Trnode *pright;
    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}
static void AddNode(Trnode *new_node, Trnode *root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL)     // empty subtree
            root->left = new_node;  // add root node here
        else
            AddNode(new_node, root->left);  // otherwise, deal with the subtree
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else                            // duplicate items are not allowed
    {
        fprintf(stderr, "location error in AddNode()\n");
        exit(1);
    }
}
static bool ToLeft(const Item *i1, const Item *i2)
{
    int comp1;
    if ((comp1 = strcmp(i1->word, i2->word)) < 0)
        return true;
    else
        return false;
}
static bool ToRight(const Item *i1, const Item *i2)
{
    int comp1;
    if ((comp1 = strcmp(i1->word, i2->word)) > 0)
        return true;
    else
        return false;
}
static Trnode *MakeNode(const Item *pi)
{
    Trnode *new_node;
    new_node = (Trnode *) malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}
static Pair SeekItem(const Item *pi, const Tree *ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;
    if (look.child == NULL)
        return look;                // return ahead of time
    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else                        // otherwise, it must be the equal situation
            break;                  // the node of target item of look.child
    }
    return look;                    // return successfully
}
static void DeleteNode(Trnode **ptr)    // ptr is the address of pointer member which points to the parent node of target node
{
    Trnode *temp;
    if ((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else            // the node to be deleted has two subnodes
    {
        // find the position to relink the right subtree
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}