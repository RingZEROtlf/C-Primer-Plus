#include <stdio.h>
int main()
{
    int day;
    printf("Please enter days: ");
    scanf("%d", &day);
    printf("%d days has %d weeks, %d days.\n", day, day / 7, day % 7);
    return 0;
}