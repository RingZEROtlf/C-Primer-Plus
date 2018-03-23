#include <stdio.h>
int main()
{
    const int dunbar_number = 150;
    int friends = 5, week = 0;
    while (friends <= dunbar_number) {
        week++;
        friends = (friends - week) * 2;
        printf("At week %d, the number of Dr. Rabnud's friends is %d.\n", week, friends);
    }
    return 0;
}