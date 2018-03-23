#include <stdio.h>
int find_max(int numbers[], int size);
int main()
{
    int numbers[5] = { 1, 2, 3, 4, 5 };
    printf("%d\n", find_max(numbers, 5));
    return 0;
}
int find_max(int numbers[], int size)
{
    int max = -2147483648;
    for (int i = 0; i < size; i++) 
        max = max > numbers[i] ? max : numbers[i];
    return max;
}