// Exer_12_2b.c
// compiled together with Exer_12_2a.c
#include <stdio.h>
#include "Exer_12_2a.h"
int main(void)
{
    int mode;
    printf("Enter 0 for metric mode, 1 for US mod: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}