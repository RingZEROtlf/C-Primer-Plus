#include <stdio.h>
#define GROUPS      3
#define SIZE        5
void get_inputs(double numbers[][SIZE]);
double average_of_a_group(int group, double numbers[][SIZE]);
double average_of_all(double numbers[][SIZE]);
double find_max(double numbers[][SIZE]);
double output_all(double group_averages[], double average, double max);
int main()
{
    double numbers[GROUPS][SIZE];
    get_inputs(numbers);
    double group_averages[SIZE];
    for (int i = 0; i < SIZE; i++)
        group_averages[i] = average_of_a_group(i, numbers);
    double average = average_of_all(numbers);
    double max = find_max(numbers);
    output_all(group_averages, average, max);
    return 0;
}
void get_inputs(double numbers[][SIZE])
{
    printf("Please input 3 groups of numbers, 5 each:\n");
    for (int i = 0; i < GROUPS; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%lf", &numbers[i][j]);
}
double average_of_a_group(int group, double numbers[][SIZE])
{
    double total = 0.0;
    for (int j = 0; j < SIZE; j++)
        total += numbers[group][j];
    return total / SIZE;
}
double average_of_all(double numbers[][SIZE])
{
    double total = 0.0;
    for (int i = 0; i < GROUPS; i++)
        for (int j = 0; j < SIZE; j++)
            total += numbers[i][j];
    return total / (GROUPS * SIZE);
}
double find_max(double numbers[][SIZE])
{
    double max = numbers[0][0];
    for (int i = 0; i < GROUPS; i++)
        for (int j = 0; j < SIZE; j++)
            max = max > numbers[i][j] ? max : numbers[i][j];
    return max;
}
double output_all(double group_averages[], double average, double max)
{
    printf("\n");
    for (int i = 0; i < GROUPS; i++)
        printf("The average of groud #%d is %.2lf.\n", i + 1, group_averages[i]);
    printf("\nThe average of all numbers is %.2lf.\n\n", average);
    printf("The maximum of all numbers is %.2lf.\n\n", max);
}
