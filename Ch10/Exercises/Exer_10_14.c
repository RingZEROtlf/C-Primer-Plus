#include <stdio.h>
void get_inputs(int d1, int d2, double numbers[d1][d2]);
double average_of_a_group(int group, int d1, int d2, double numbers[d1][d2]);
double average_of_all(int d1, int d2, double numbers[d1][d2]);
double find_max(int d1, int d2, double numbers[d1][d2]);
double output_all(int d1, double group_averages[d1], double average, double max);
int main()
{
    double numbers[3][5];
    get_inputs(3, 5, numbers);
    double group_averages[3];
    for (int i = 0; i < 3; i++)
        group_averages[i] = average_of_a_group(i, 3, 5, numbers);
    double average = average_of_all(3, 5, numbers);
    double max = find_max(3, 5, numbers);
    output_all(3, group_averages, average, max);
    return 0;
}
void get_inputs(int d1, int d2, double numbers[d1][d2])
{
    printf("Please input 3 groups of numbers, 5 each:\n");
    for (int i = 0; i < d1; i++)
        for (int j = 0; j < d2; j++)
            scanf("%lf", &numbers[i][j]);
}
double average_of_a_group(int group, int d1, int d2, double numbers[d1][d2])
{
    double total = 0.0;
    for (int j = 0; j < d2; j++)
        total += numbers[group][j];
    return total / d2;
}
double average_of_all(int d1, int d2, double numbers[d1][d2])
{
    double total = 0.0;
    for (int i = 0; i < d1; i++)
        for (int j = 0; j < d2; j++)
            total += numbers[i][j];
    return total / (d1 * d2);
}
double find_max(int d1, int d2, double numbers[d1][d2])
{
    double max = numbers[0][0];
    for (int i = 0; i < d1; i++)
        for (int j = 0; j < d2; j++)
            max = max > numbers[i][j] ? max : numbers[i][j];
    return max;
}
double output_all(int d1, double group_averages[d1], double average, double max)
{
    printf("\n");
    for (int i = 0; i < d1; i++)
        printf("The average of groud #%d is %.2lf.\n", i + 1, group_averages[i]);
    printf("\nThe average of all numbers is %.2lf.\n\n", average);
    printf("The maximum of all numbers is %.2lf.\n", max);
}
