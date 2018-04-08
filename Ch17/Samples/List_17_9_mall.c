// mall.c -- using Queue interfaces
// compiled together with List_17_7_queue.c
#include <stdio.h>
#include <stdlib.h>             // providing function prototypes of rand() and srand()
#include <time.h>               // providing function prototypes of time()
#include "List_17_6_queue.h"    // remember to change the typedef of Item
#define MIN_PER_HR      60.0
bool newcustomer(double x);     // if new customer is coming
Item customertime(long when);   // set customer params
int main(void)
{
    Queue line;
    Item temp;              // data of new customer
    int hours;              // hours simulated
    int perhour;            // how many customers per hour
    long cycle, cyclelimit; // cycle counter, the limit of counter
    long turnaways = 0;     // customers rejected cause full of queue
    long customers = 0;     // customers added into the queue
    long served = 0;        // customers asked for advice from Sigmund during simulating
    long sum_line = 0;      // length of queue accumulated
    int wait_time = 0;      // time need from the current to Sigmund's free time
    double min_per_cust;    // average time for customers to arrive
    long line_wait = 0;     // total time for queue to wait
    InitializeQueue(&line);
    srand((unsigned int) time(0));  // rand() initialization
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;
    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line))
                turnaways++;
            else
            {
                customers++;
                temp = customertime(cycle);
                EnQueue(temp, &line);
            }
        }
        if (wait_time <= 0 && !QueueIsEmpty(&line))
        {
            DeQueue(&temp, &line);
            wait_time = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += QueueItemCount(&line);
    }
    if (customers > 0)
    {
        printf("customers accepted: %ld\n", customers);
        printf("  customers served: %ld\n", served);
        printf("         turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n", (double) sum_line / cyclelimit);
        printf(" average wait time: %.2f minutes\n", (double) sum_line / served);
    }
    else
        puts("No customers!");
    EmtpyTheQueue(&line);
    puts("Bye!");
    return 0;
}
// x is the average time for customers to arrive (unit: minute)
// if customers arrive in no more than one minute, return true
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}
// when is time customers arrive
// this function return an Item struct, the customer'a arriving time is set as when
// advice time is set as a 1~3 random number
Item customertime(long when)
{
    Item cust;
    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;
    return cust;
}