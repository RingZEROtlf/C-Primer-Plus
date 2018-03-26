#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare_two_integers(const void *a, const void *b);

int main()
{
    int random_numbers[100];
    srand((unsigned int) time(NULL));
    for (int i = 0; i < 100; i++)
        random_numbers[i] = rand() % 10 + 1;
    qsort(random_numbers, 100, sizeof *random_numbers, compare_two_integers);
    for (int i = 0; i < 100; i++) {
        printf("%02d ", random_numbers[i]);
        if (i % 10 == 9) putchar('\n');
    }
    return 0;
}

int compare_two_integers(const void *a, const void *b)
{
    int *pa = (int *)a, *pb = (int *)b;
    return *pb - *pa;
}