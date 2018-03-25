// global.c -- using external varialbe
#include <stdio.h>
int units = 0;      // exteranl variable
void critic(void);
int main(void)
{
    extern int units;   // optional repetive declaration
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic();
    printf("You must have looked it up!\n");
    return 0;
}
void critic(void)
{
    // repetive declaration deleted
    printf("No lack, my friend. Try again.\n");
    scanf("%d", &units);
}