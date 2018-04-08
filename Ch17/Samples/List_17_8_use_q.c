// use_q.c -- driver program testing Queue interfaces
// compiled together with List_17_7_queue.c
#include <stdio.h>
#include "List_17_6_queue.h"        // providing definitions of Queue, Item
int main(void)
{
    Queue line;
    Item temp;
    char ch;
    InitializeQueue(&line);
    puts("Testing the Queue interface. Type a to add a value,");
    puts("type d to delete a value, and type q to quit.");
    while ((ch = getchar()) != 'q')
    {
        if (ch != 'a' && ch != 'd')     // ignore other inputs
            continue;
        if (ch == 'a')
        {
            printf("Integer to add: ");
            scanf("%d", &temp);
            if (!QueueIsFull(&line))
            {
                printf("Putting %d into queue.\n", temp);
                EnQueue(temp, &line);
            }
            else
                puts("Queue is full!");
        }
        else
        {
            if (QueueIsEmpty(&line))
                puts("Nothing to delete!");
            else
            {
                DeQueue(&temp, &line);
                printf("Removing %d from queue.\n", temp);
            }
        }
        printf("%d items in queue.\n", QueueItemCount(&line));
        puts("Type a to add, d to delete, q to quit:");
    }
    EmtpyTheQueue(&line);
    puts("Bye!");
    return 0;
}