// min_sec.c -- change seconds into minutes and seconds
#include <stdio.h>
#define SEC_PER_MIN 60      // 1 minute has 60 seconds
int main(void)
{
    int sec, min, left;
    printf("Convert seconds to minutes and seconds!\n");
    printf("Enter the number of seconds (<=0 to quit):\n");
    scanf("%d", &sec);      // input seconds
    while(sec > 0)
    {
        min = sec / SEC_PER_MIN;    // intercept minutes
        left = sec % SEC_PER_MIN;   // seconds left
        printf("%d seconds is %d minutes, %d seconds.\n", sec, min, left);
        printf("Enter the number of seconds (<=0 to quit):\n");
        scanf("%d", &sec);
    }
    printf("Done!\n");
    return 0;
}