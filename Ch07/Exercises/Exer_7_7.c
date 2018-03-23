#include <stdio.h>
#define BASE_SALARY     1000.0
#define BASE_TIME       40.0
#define FACTOR          1.5
#define RATE1           0.15
#define BASE1           300.0
#define RATE2           0.20
#define BASE2           150.0
#define RATE3           0.25
int main()
{
    double hour;
    printf("Please enter the working hour in a week: ");
    scanf("%lf", &hour);
    if (hour > BASE_TIME) hour = BASE_TIME + (hour - BASE_TIME) * FACTOR;
    double salary = hour * BASE_SALARY;
    if (salary > BASE1 + BASE2) {
        salary -= BASE1 * RATE1 + BASE2 * RATE2 + (salary - BASE1 - BASE2) * RATE3;
    }
    else if (salary > BASE1) {
        salary -= BASE1 * RATE1 + (salary - BASE1) * RATE2;
    }
    else salary *= (1.0 - RATE1);
    printf("The salary of a week should be $%.2f.\n", salary);
    return 0;
}