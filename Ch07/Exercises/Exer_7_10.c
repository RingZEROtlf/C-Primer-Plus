#include <stdio.h>
int main()
{
    int type;
    double income;
    double thresholds[4] = { 17850, 23900, 29750, 14875 };
    double rate[2] = { 0.15, 0.28 };
    while (1) {
        printf("Please enter the type of the tax payer (0 for single, 1 for householder, 2 for married with shared house, 3 for married but divorced),\n")
        printf("and the income of the tax payer: ");
        if (scanf("%d %lf", &type, &income) != 2) break;
        double fax = income > thresholds[type] ? thresholds[type] * rate[0] + (income - thresholds[type]) * rate[1] : income * rate[0];
        printf("The fax should be %.2f.\n", fax);
    }
    return 0;
}