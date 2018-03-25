// manydice.c -- simulates rolling dice several times
// compiled together with List_12_11_diceroll.c
#include <stdio.h>
#include <stdlib.h>                 // providing function prototype of srand()
#include <time.h>                   // providing function prototype of time()
#include "List_12_12_diceroll.h"    // providing function prototype of roll_n_dice(), and declaration of roll_count
int main(void)
{
    int dice, roll;
    int sides;
    int status;
    srand((unsigned int) time(0));      // random seed
    printf("Enter the number of sides per die, 0 to stop.\n");
    while (scanf("%d", &sides) == 1 && sides > 0)
    {
        printf("How many dice?\n");
        if ((status = scanf("%d", &dice)) != 1)
        {
            if (status == EOF)
                break;      // exit loop
            else
            {
                printf("You should have entered an integer.");
                printf(" Let's begin again.\n");
                while (getchar() != '\n')
                    continue;   // dealing with mistake input
                printf("How many sides? Enter 0 to stop.\n");
                continue;       // enter next iteration of loop
            }
        }
        roll = roll_n_dice(dice, sides);
        printf("You have rolled a %d using %d %d-sided dice.\n", roll, dice, sides);
        printf("How many sides? Enter 0 to stop.\n");
    }
    printf("The rollem() function was called %d times.\n", roll_count); // using external variable
    printf("GOOD FORTUNE TO YOU!\n");
    return 0;
}