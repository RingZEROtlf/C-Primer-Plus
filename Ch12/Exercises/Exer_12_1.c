#include <stdio.h>
void critic(int *punits);
int main(void)
{
    int units;
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic(&units);
    printf("You must have looked it up!\n");
    return 0;
}
void critic(int *punits)
{
    printf("No lack, my friend. Try again.\n");
    scanf("%d", punits);
}