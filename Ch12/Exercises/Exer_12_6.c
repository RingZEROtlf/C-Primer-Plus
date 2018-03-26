#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int counter[10];
    for (int i = 0; i < 10; i++) {
        srand((unsigned int) i);
        memset(counter, 0, sizeof(counter));
        for (int j = 0; j < 1000; j++) {
            int random_number = rand() % 10 + 1;
            counter[random_number - 1]++;
        }
        printf("seed: %1d\n", i);
        for (int j = 0; j < 10; j++)
            printf("%2d: %4d\n", j + 1, counter[j]);
        putchar('\n');
    }
    return 0;
}