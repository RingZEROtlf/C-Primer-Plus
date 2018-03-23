#include <stdio.h>
double range_between_max_and_min(double numbers[], int size);
int main()
{
    double numbers[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    printf("%lf\n", range_between_max_and_min(numbers, 5));
    return 0;
}
double range_between_max_and_min(double numbers[], int size)
{
    double max = numbers[0], min = numbers[0];
    for (int i = 1; i < size; i++) {
        max = max > numbers[i] ? max : numbers[i];
        min = min < numbers[i] ? min : numbers[i];
    }
    return max - min;
}
