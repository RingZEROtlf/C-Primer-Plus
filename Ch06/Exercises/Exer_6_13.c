#include <stdio.h>
int main()
{
    int powers_of_two[8];
    powers_of_two[0] = 2;
    for (int i = 1; i < 8; i++) {
        powers_of_two[i] = powers_of_two[i - 1] * 2;
    }
    int i = 0;
    do {
        printf("%d ", powers_of_two[i++]);
    } while (i < 8);
    printf("\n");
    return 0;
}