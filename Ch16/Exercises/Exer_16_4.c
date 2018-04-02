#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void my_sleep(double gap_seconds);

int main()
{
    puts("Wait 60s.");
    puts("Start!");
    my_sleep(60);
    puts("End!");
    return 0;
}

void my_sleep(double gap_seconds)
{
    clock_t start = clock();
    while (true) {
        clock_t curr = clock();
        if ((curr - start) / CLOCKS_PER_SEC >= gap_seconds) break;
    }
}