/* platinum.c   -- your weight in platinum */
#include <stdio.h>

int main(void)
{
    float weight;       /* your weight */
    float value;        /* the value of platinum of the same weight */
    printf("Are you worth your weight in platinum?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds: ");
    /* get user input */
    scanf("%f", &weight);
    /* assume the price of platinum is $1700/ounce */
    /* 14.5833 is used to change pound into troy ounce */
    value = 1700.0 * weight * 14.5833;
    printf("Your weight in platinum is worth $%.2f.\n", value);
    printf("You are easily worth that! If platinum prices drop,\n");
    printf("eat more to maintain your value.\n");

    return 0;
}