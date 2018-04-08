// queue.h -- interfaces of Queue
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>
// insert definition of Item type here, for example
typedef struct item { long arrive; int processtime; } Item;    // used in Exer_17_4_mall.c
#define MAXQUEUE    10
typedef struct node
{
    Item item;
    struct node *next;
} Node;
typedef struct queue
{
    Node *front;            // pointer points to the head node of queue
    Node *rear;             // pointer points to the tail node of queue
    int items;              // number of items in the queue
} Queue;
/* Operation:       initialize a queue
 * Precondition:    pq points to a queue
 * Postcondition:   the given queue is initialized to an empty queue
 */
void InitializeQueue(Queue *pq);
/* Operation:       check if queue is full
 * Precondition:    pq points to an initialized queue
 * Postcondition:   return true if queue is full, false otherwise
 */
bool QueueIsFull(const Queue *pq);
/* Operation:       check if queue is empty
 * Precondition:    pq points to an initialized queue
 * Postcondition:   return true if queue is empty, false otherwise
 */
bool QueueIsEmpty(const Queue *pq);
/* Operation:       get the number of items in a queue
 * Precondition:    pq points to an initialized queue
 * Postcondition:   return the number of items of the given queue
 */
int QueueItemCount(const Queue *pq);
/* Operation:       append item to the end of a queue
 * Precondition:    pq points to an initialized queue, item is the element to be appended
 * Postcondition:   if queue is not empty, item is appended to the tail of the queue, and return true;
 *                  otherwise, do nothing to the queue, and return false
 */
bool EnQueue(Item item, Queue *pq);
/* Operation:       delete element from the start of a queue
 * Precondition:    pq points to an initialized queue
 * Postcondition:   if queue is not empty, the item at the start of the given queue is copied to *pitem and 
 *                  deleted, return true; if this operation results in an empty queue, reset the queue to an
 *                  empty one; if the given queue is an empty one before this operation take action, just
 *                  return false
 */
bool DeQueue(Item *pitem, Queue *pq);
/* Operation:       clear a queue
 * Precondition:    pq points to an initialized queue
 * Postcondition:   the given queue is cleared
 */
void EmtpyTheQueue(Queue *pq);
#endif