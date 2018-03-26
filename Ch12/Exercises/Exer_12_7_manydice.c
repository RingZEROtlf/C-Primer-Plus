// manydice.c -- simulates rolling dice several times
// compiled together with Exer_12_11_diceroll.c
#include <stdio.h>
#include <stdlib.h>                 // providing function prototype of srand()
#include <time.h>                   // providing function prototype of time()
#include "Exer_12_7_diceroll.h"    // providing function prototype of roll_n_dice(), and declaration of roll_count
int main(void)
{
    int dice, roll;
    int sides;
    int status;
    srand((unsigned int) time(0));      // random seed
    int sets;
    printf("Enter the number of sets; enter q to stop: ");
    while (scanf("%d", &sets) == 1 && sets > 0)
    {
        printf("How many sides and how many dice? ");
        if (scanf("%d %d", &sides, &dice) != 2) break;
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (int i = 0; i < sets; i++)
            printf(" %d ", roll_n_dice(dice, sides));
        putchar('\n');
        printf("How many sets? Enter q to stop: ");
    }
    return 0;
}