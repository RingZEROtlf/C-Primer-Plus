#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE    1024

void select_randomly_and_print(int array[], int size, int count);

int main()
{
    int numbers[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
        numbers[i] = i;
    select_randomly_and_print(numbers, 1024, 5);
    return 0;
}

void select_randomly_and_print(int array[], int size, int count)
{
    srand((unsigned int) time(0));
    bool used[size];
    if (count > size) {
        puts("Times of selection too large!");
        return;
    }
    memset(used, false, sizeof(used));
    for (int i = 0; i < count; i++) {
        while (true) {
            int pos = rand() % size;
            if (!used[pos]) {
                printf("%d ", array[pos]);
                used[pos] = true;
                break;
            }
        }
    }
    putchar('\n');
}
