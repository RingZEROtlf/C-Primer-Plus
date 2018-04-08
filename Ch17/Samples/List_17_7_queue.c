// queue.c -- implementation of Queue type
#include <stdio.h>
#include <stdlib.h>
#include "List_17_6_queue.h"
// local functions
static void CopyToNode(Item item, Node *pn);
static void CopyToItem(Node *pn, Item *pi);
void InitializeQueue(Queue *pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}
bool QueueIsFull(const Queue *pq)
{
    return pq->items == MAXQUEUE;
}
bool QueueIsEmpty(const Queue *pq)
{
    return pq->items == 0;
}
int QueueItemCount(const Queue *pq)
{
    return pq->items;
}
bool EnQueue(Item item, Queue *pq)
{
    Node *pnew;
    if (QueueIsFull(pq))
        return false;
    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
    {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(1);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (QueueIsEmpty(pq))
        pq->front = pnew;       // at the start of the queue
    else
        pq->rear->next = pnew;  // link to the tail of the queue
    pq->rear = pnew;            // store the tail of the queue
    pq->items++;                // update items in the queue
    return true;
}
bool DeQueue(Item *pitem, Queue *pq)
{
    Node *pt;
    if (QueueIsEmpty(pq))
        return false;
    CopyToItem(pq->front, pitem);
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items == 0)
        pq->rear = NULL;
    return true;
}
// clear the queue
void EmtpyTheQueue(Queue *pq)
{
    Item dummy;
    while (!QueueIsEmpty(pq))
        DeQueue(&dummy, pq);
}
// local functions
static void CopyToNode(Item item, Node *pn)
{
    pn->item = item;
}
static void CopyToItem(Node *pn, Item *pi)
{
    *pi = pn->item;
}