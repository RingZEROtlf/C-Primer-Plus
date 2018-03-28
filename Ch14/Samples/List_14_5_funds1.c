// funds1.c -- pass struct members as parameters
#include <stdio.h>
#define FUNDLEN     50
struct funds {
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};
double sum(double, double);
int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };
    printf("Stan has a total of $%.2f.\n", sum(stan.bankfund, stan.savefund));
    return 0;
}
// sumary of two double values
double sum(double x, double y)
{
    return (x + y);
}