#include <stdio.h>
int main()
{
    double deposit = 100.0;
    int year = 0;
    do {
        year++;
        deposit = deposit * 1.08 - 10.0;
    } while (deposit >= 0.0);
    printf("At year %d, the deposit of Chuckie Lucky is zero.\n", year);
    return 0;
}