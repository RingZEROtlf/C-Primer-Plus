// compiled together with Exer_12_3a.c
#include <stdio.h>
#include "Exer_12_3a.h"
int main(void)
{
    int mode;
    double distance, fuel;
    printf("Enter 0 for metric mode, 1 for US mod: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        get_info(&mode, &distance, &fuel);
        show_info(mode, distance, fuel);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}