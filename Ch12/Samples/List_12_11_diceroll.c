// diceroll.c -- dice rolling simulator
// compiled together with List_12_13_manydice.c
#include "List_12_12_diceroll.h"
#include <stdio.h>
#include <stdlib.h>     // providing function prototype of rand()
int roll_count = 0;     // external linkage
static int rollem(int sides)    // private function of this file
{
    int roll;
    roll = rand() % sides + 1;
    ++roll_count;       // calculate revoke times of this function;
    return roll;
}
int roll_n_dice(int dice, int sides)
{
    int d;
    int total = 0;
    if (sides < 2)
    {
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (dice < 1)
    {
        printf("Need at least 1 die.\n");
        return -1;
    }
    for (d = 0; d < dice; d++)
        total += rollem(sides);
    return total;
}