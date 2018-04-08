#include <stdio.h>
#include <stdbool.h>

bool search_in_array(int array[], int size, int pattern);

int main()
{
    int array[3] = { 1, 2, 3 };
    if (search_in_array(array, 3, 2))
        puts("Found!");
    else
        puts("Not found!");
    return 0;
}

bool search_in_array(int array[], int size, int pattern)
{
    if (size <= 0)
        return false;
    else if (size == 1)
        return (array[0] == pattern ? true : false);
    else
        return (search_in_array(array, size / 2, pattern) || search_in_array(array + size / 2, size - size / 2, pattern) ? true : false);
}
