#include <stdio.h>
int find_index_of_max(double numbers[], int size);
int main()
{
    double numbers[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    printf("%d\n", find_index_of_max(numbers, 5));
    return 0;
}
int find_index_of_max(double numbers[], int size)
{
    double max = numbers[0];
    int index = 0;
    for (int i = 1; i < size; i++)
        if (max < numbers[i]) {
            max = numbers[i];
            index = i;
        }
    return index;
}