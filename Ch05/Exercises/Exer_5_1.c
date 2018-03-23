#include <stdio.h>
const int MINUTES_IN_ONE_HOUR = 60;
int main()
{
    int hour;
    while(scanf("%d", &hour) == 1) {
        if(hour <= 0) break;
        int minute = hour % 60;
        hour /= 60;
        printf("%d %d\n", hour, minute);
    }
    return 0;
}